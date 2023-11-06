#include "var_monitor.h"
#include <unistd.h>
#include <sys/time.h>
#include <fstream>

using namespace std;
uint8_t VarMonitor::buffer[5*1024*1024];
MonitorManager_t VarMonitor::monitor_manager_[THREAD_MONITOR_NUM];
map<unsigned long, unsigned int> VarMonitor::index_map_;
unsigned int VarMonitor::occupied_index_ = 0;

VarMonitor::VarMonitor(const char *thread_name)
{
    pthread_t pid = pthread_self();

    map_mutex_.lock();
    if(occupied_index_ >= THREAD_MONITOR_NUM)
    {
        map_mutex_.unlock();
        return;
    }
    index_map_[pid] = occupied_index_++;
    map_mutex_.unlock();

    if (strlen(thread_name) > (THREAD_NAME_SIZE - 1))
    {
        memcpy(monitor_manager_[index_map_[pid]].monitor_config_.thread_name_, thread_name, (THREAD_NAME_SIZE - 1));
        monitor_manager_[index_map_[pid]].monitor_config_.thread_name_[THREAD_NAME_SIZE - 1] = '\0';
    }
    else
    {
        memset(monitor_manager_[index_map_[pid]].monitor_config_.thread_name_, 0, THREAD_NAME_SIZE);
        strcpy(monitor_manager_[index_map_[pid]].monitor_config_.thread_name_, thread_name);
    }

    /* config */
    monitor_manager_[index_map_[pid]].monitor_config_.enable_ = 1;      
    monitor_manager_[index_map_[pid]].monitor_config_.out_method_ = 2;
    monitor_manager_[index_map_[pid]].monitor_config_.interval_ = 1;
    monitor_manager_[index_map_[pid]].monitor_config_.itemlen_ = 5;
}

VarMonitor::~VarMonitor()
{

}
void VarMonitor::set_monitor_info(const char *thread_name, MonitorConfig_t &cfg)
{

}
void VarMonitor::get_monitor_info(const char *thread_name, MonitorConfig_t &cfg)
{

}
void VarMonitor::get_monitor_info(MonitorConfig_t *cfg, int nums)
{

}

void VarMonitor::push_var(const char *name, double *var, int nums)
{
    unsigned int index = index_map_[pthread_self()];
    
    if(monitor_manager_[index].monitor_config_.enable_)
    {
        MonitorDataElem_t elem;
        // MonitorDataElem_t:name
        if(strlen(name)<VAR_NAME_SIZE)
        {
            strncpy(elem.name, name, strlen(name));
            elem.name[strlen(name)] = '\0';
        }
        else
        {
            strncpy(elem.name, name, VAR_NAME_SIZE-1);
            elem.name[VAR_NAME_SIZE-1] = '\0';
        }
        // MonitorDataElem_t:data
        for(int i=0;i<nums;++i)
        {
            elem.elem.push_back(var[i]);
        }
        monitor_manager_[index].monitor_pool_.item_.push_back(elem);
    }
}

void VarMonitor::push_var(const char *name, Eigen::Vector<double,6> &var)
{
    push_var(name, var.data(), 6);
}

void VarMonitor::push_item()
{
    unsigned int index = index_map_[pthread_self()];
    double time_ms = 0;
    struct timeval tv;
    if(monitor_manager_[index].monitor_config_.enable_)
    {
        /* wait config interval */
        if((monitor_manager_[index].monitor_ctrl_.tick_++)%(monitor_manager_[index].monitor_config_.interval_))
        {
            monitor_manager_[index].monitor_pool_.item_.clear();
            return;
        }
        
        /* add time stamp */
        MonitorDataElem_t tick;
        gettimeofday(&tv, NULL);
        time_ms = ((long long)tv.tv_sec*1000000 + tv.tv_usec) / 1000;
        push_var("tick", &time_ms);

        /* add monitor data to free lock pool && clear item vector*/
        monitor_manager_[index].monitor_pool_.lock_free_pool_.push(monitor_manager_[index].monitor_pool_.item_);
        monitor_manager_[index].monitor_pool_.item_.clear();
    }
}

void VarMonitor::upload(void)
{
    map<unsigned long, unsigned int>::iterator it;
    for(it=index_map_.begin();it!=index_map_.end();it++)
    {
        if(monitor_manager_[(*it).second].monitor_config_.enable_)
        {
            VarMonitor::upload((*it).second);
        }
    } 
}

void VarMonitor::upload(unsigned int index)
{
    vector<MonitorDataElem_t> item;
    monitor_manager_[index].monitor_pool_.lock_free_pool_.pop(item);

    if(item.size() != 0)
    {
        monitor_manager_[index].monitor_pool_.pool_.push_back(item); 
    }
    
    //cout<<monitor_manager_[index].monitor_pool_.pool_.size()<<endl;
    if(monitor_manager_[index].monitor_pool_.pool_.size()==monitor_manager_[index].monitor_config_.itemlen_)
    {
        /* upload */
        switch(monitor_manager_[index].monitor_config_.out_method_)
        {
        case 0:
            output_print(index, cout);
            break;
        case 1:
            output_file(index);
            break;
        case 2:
            output_network(index);
            break;
        default:
            break;
        }
        /* clear */
        monitor_manager_[index].monitor_pool_.pool_.clear();
    }
}

void VarMonitor::output_print(unsigned int index, ostream &output)
{
    // print head
    for(vector<MonitorDataElem_t>::iterator it = monitor_manager_[index].monitor_pool_.pool_.begin()->begin(); 
                                            it != monitor_manager_[index].monitor_pool_.pool_.begin()->end(); ++it)
    {
        for(size_t i = 0; i < it->elem.size(); ++i)
        {
            output << (*it).name << i << ", ";
        }
    }
    output << endl;
    for(vector<vector<MonitorDataElem_t>>::iterator i = monitor_manager_[index].monitor_pool_.pool_.begin(); 
                                                    i!=monitor_manager_[index].monitor_pool_.pool_.end();++i)
    {
        // print data
        for(vector<MonitorDataElem_t>::iterator it = i->begin(); it != i->end(); ++it)
        {
            for(size_t i = 0; i < it->elem.size(); ++i)
            {
                output << (*it).elem[i] << ", ";
            }
        }
        output << endl;
    }
}

void VarMonitor::input_decode(unsigned int index, VarMonitorData &mvar, pb_istream_t &stream)
{
    size_t message_length;
    bool status;
    /* Now we are ready to decode the message. */
    status = pb_decode(&stream, VarMonitorData_fields, &mvar);
    
    /* Check for errors... */
    if (!status)
    {
        printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        return;
    }
    
    /* Print the data contained in the message. */
    for(int i=0; i< mvar.head_count; ++i)
    {
        printf("%s, ",mvar.head[i]);
    }
    printf("\n");
    for(int i = 0; i<mvar.item_count; ++i)
    {
        for(int j = 0; j<mvar.item[i].data_count; ++j)
        {
            printf("%lf, ",mvar.item[i].data[j]);
        }
        printf("\n");
    }
}
void VarMonitor::output_encode(unsigned int index, VarMonitorData &mvar, pb_ostream_t &stream, size_t &message_length)
{
    bool status;
    int n = 0;
    /* Fill in the monitor data */
    mvar.head_count = 0;
    mvar.item_count = monitor_manager_[index].monitor_config_.itemlen_;

    for(size_t i = 0; i < monitor_manager_[index].monitor_config_.itemlen_; ++i)
    {
        n = 0;
        for(size_t j = 0; j < monitor_manager_[index].monitor_pool_.pool_[i].size(); ++j)
        {
            for(size_t k = 0; k < monitor_manager_[index].monitor_pool_.pool_[i][j].elem.size(); ++k)
            {
                if(i == 0)
                {
                    sprintf(mvar.head[n], "%s%ld\0", monitor_manager_[index].monitor_pool_.pool_[i][j].name, k);
                }
                mvar.item[i].data[n] = monitor_manager_[index].monitor_pool_.pool_[i][j].elem[k];   
                ++n;
            }
        }
        mvar.item[i].data_count = n;
        if(i==0) mvar.head_count = n;
        
    }
    
    /* Now we are ready to encode the message! */
    status = pb_encode(&stream, VarMonitorData_fields, &mvar);
    message_length = stream.bytes_written;
    
    /* Then just check for any errors.. */
    if (!status)
    {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
    }
}

void VarMonitor::output_network(unsigned int index)
{
    size_t message_length;
     /* Allocate space on the stack to store the message data.*/
    VarMonitorData mvar = VarMonitorData_init_zero;

    /* Create a stream that will write to our buffer. */
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
    output_encode(index, mvar, stream, message_length);
    
    {
        /* Allocate space for the decoded message. */
        VarMonitorData mdat = VarMonitorData_init_zero;
        /* Create a stream that reads from the buffer. */
        pb_istream_t stream1 = pb_istream_from_buffer(buffer, message_length);
        input_decode(index, mdat, stream1);
    }
    
}

// write interval time must >= 1s
void VarMonitor::output_file(unsigned int index)
{
    ofstream log_file;
    char file_time[32] = "";
    char file_name[128] = "/tmp/var_";

    time_t t = time(NULL);
    struct tm *t_now = localtime(&t);
    strftime(file_time, sizeof(file_time), "%Y%m%d%H%M%S.csv", t_now);
    strcat(file_name, monitor_manager_[index].monitor_config_.thread_name_);
    strcat(file_name, file_time);

    log_file.open(file_name,ios::trunc);
    output_print(index, log_file);
    log_file.close();
}


