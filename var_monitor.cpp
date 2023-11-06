#include "var_monitor.h"
#include <unistd.h>
#include <sys/time.h>
#include <fstream>

using namespace std;

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
    monitor_manager_[index_map_[pid]].monitor_config_.out_method_ = 0;
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
void VarMonitor::push_var(double var)
{
    unsigned int index = index_map_[pthread_self()];
    if(monitor_manager_[index].monitor_config_.enable_)
    {
        monitor_manager_[index].monitor_pool_.item_.push_back(var);
    }
}

void VarMonitor::push_var(double *var, int nums)
{
    unsigned int index = index_map_[pthread_self()];
    if(monitor_manager_[index].monitor_config_.enable_)
    {
        for(int i=0;i<nums;++i)
        {
            monitor_manager_[index].monitor_pool_.item_.push_back(var[i]);
        }
    }
}

void VarMonitor::push_var(Eigen::Vector<double,6> &var)
{
    unsigned int index = index_map_[pthread_self()];
    if(monitor_manager_[index].monitor_config_.enable_)
    {
        for(int i=0;i<6;++i)
        {
            monitor_manager_[index].monitor_pool_.item_.push_back(var(i));
        }
    }
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
        gettimeofday(&tv, NULL);
        time_ms = ((long long)tv.tv_sec*1000000 + tv.tv_usec) / 1000;
        monitor_manager_[index].monitor_pool_.item_.push_back(time_ms);

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
    vector<double> item;
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
    //output << monitor_manager_[index].monitor_config_.thread_name_ << endl;
    for(vector<vector<double>>::iterator i = monitor_manager_[index].monitor_pool_.pool_.begin(); i!=monitor_manager_[index].monitor_pool_.pool_.end();++i)
    {
        for(vector<double>::iterator it = i->begin(); it != i->end(); ++it)
        {
            output << *it << ",";
        }
        output << endl;
    }

}

void VarMonitor::output_network(unsigned int index)
{
    if(!monitor_manager_[index].monitor_pool_.item_.empty())
    {
        for(vector<double>::iterator it = monitor_manager_[index].monitor_pool_.item_.begin(); it != monitor_manager_[index].monitor_pool_.item_.end(); ++it)
        {
            printf("%lf,",*it);
        }
        printf("\n");
        monitor_manager_[index].monitor_pool_.item_.clear();
    }
}

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


