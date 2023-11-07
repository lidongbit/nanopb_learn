#include "thread_help.h"


using namespace base_space;

ThreadHelp::ThreadHelp()
{
    thread_name_ = "";
}

ThreadHelp::~ThreadHelp()
{

}

bool ThreadHelp::run(threadFunc func_ptr, void* data, int priority, bool is_rt)
{
    if(func_ptr == NULL
        || priority < 1
        || priority > 99)
    {
        return false;
    }
    pthread_attr_t attr;
    struct sched_param param;
    pthread_attr_init(&attr);
    if(is_rt)
    {
        param.sched_priority = priority;
        pthread_attr_setschedpolicy(&attr, SCHED_RR);
        pthread_attr_setschedparam(&attr,   &param);
        pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    }
    // let realtime thread run on cpu 1
    if(thread_name_ == "realtime")
    {
        cpu_set_t cpus;
        CPU_ZERO(&cpus);
        CPU_SET(1, &cpus);
        pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpus);
    }
    
    // create thread
    pthread_create(&pid_, &attr, func_ptr, data);
 
    pthread_attr_destroy(&attr);

    return true;
}

void ThreadHelp::join()
{
    if(pid_ == 0) return;
    pthread_join(pid_, NULL);
}

void ThreadHelp::detach()
{
    if(pid_ == 0) return;
    pthread_detach(pid_);
}

void ThreadHelp::cancel()
{
    if(pid_ == 0) return;
    pthread_cancel(pid_);
}

int ThreadHelp::getpid()
{
    // usually pid wont larger than (2^31 - 1) or (-1)*(2^31)
    // if it does, something must went wrong
    return static_cast<int>(pid_);
}

