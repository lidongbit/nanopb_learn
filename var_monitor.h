#ifndef VAR_MONITOR_
#define VAR_MONITOR_
#include <map>
#include <vector>
#include <Eigen/Dense>
#include <mutex>
#include <iostream>
#include <pb.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "var_monitor_data.pb.h"
#include "lockfree_queue.h"
#define THREAD_MONITOR_NUM 10
#define THREAD_NAME_SIZE 32
#define VAR_NAME_SIZE 64
typedef struct
{
    char thread_name_[THREAD_NAME_SIZE];
    unsigned int enable_;
    unsigned int out_method_; /*0-console 1-file 2-network*/
    unsigned int interval_;
    unsigned int itemlen_;
}MonitorConfig_t;

typedef struct
{
    char name[VAR_NAME_SIZE]; //data name
    std::vector<double> elem; //elem data include length
}MonitorDataElem_t;

typedef struct
{
    std::vector<MonitorDataElem_t> item_;
    std::vector<std::vector<MonitorDataElem_t>> pool_;
    base_space::LockFreeQueue<std::vector<MonitorDataElem_t>> lock_free_pool_;
}MonitorPool_t;

typedef struct
{
    unsigned int tick_;
    unsigned int cnt_;
}MonitorCtrl_t;

typedef struct
{
    MonitorConfig_t monitor_config_;
    MonitorCtrl_t monitor_ctrl_;
    MonitorPool_t monitor_pool_;
}MonitorManager_t;

class VarMonitor
{
public:
    VarMonitor(const char *thread_name);

    ~VarMonitor();

    static void set_monitor_info(const char *thread_name, MonitorConfig_t &cfg);
    static void get_monitor_info(const char *thread_name, MonitorConfig_t &cfg);
    static void get_monitor_info(MonitorConfig_t *cfg, int nums);

    //static void push_var(double);
    //static void push_var(double *var, int nums);
    static void push_var(const char *name, double *var, int nums=1);
    static void push_var(const char *name, Eigen::Vector<double,6> &var);
    static void push_item();
    static void upload(void);
    static void input_decode(unsigned int index, VarMonitorData &mvar, pb_istream_t &stream);
private:
    static void upload(unsigned int index);
    static void output_print(unsigned int index, std::ostream &output);
    static void output_network(unsigned int index);
    static void output_file(unsigned int index);
    static void output_encode(unsigned int index, VarMonitorData &mvar, pb_ostream_t &stream, size_t &message_length);
private:
    static MonitorManager_t monitor_manager_[THREAD_MONITOR_NUM];
    std::mutex map_mutex_;
    static std::map<unsigned long, unsigned int> index_map_;
    static unsigned int occupied_index_;
    static uint8_t buffer[5*1024*1024];
};

#endif
