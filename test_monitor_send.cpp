#include "var_monitor.h"
#include <iostream>
#include <pthread.h>
#include <sys/unistd.h>
using namespace std;
void *thread_1(void* param_ptr)
{   
    char thread_name[32];
    usleep(10);
    pthread_t pid = pthread_self();
    //sprintf(thread_name, "Thread_%ld",pid);
    pthread_getname_np(pid, thread_name, 32);
    cout<< thread_name << " start!\n";
    VarMonitor vm_tid1((const char*)thread_name);
    Eigen::Vector<double, 6> var;
    var<<1,1,1,1,1,1;
    double index = 0;
    for(int i=0;i<1000;i++)
    {
        index = i;
        var = var.array() + 1;
        VarMonitor::push_var("index", &index, 1);
        //cout << var.transpose()<<endl;
        for(int j=0;j<1;j++)
        {
            VarMonitor::push_var("Vector6", var);
        }
        VarMonitor::push_item();
        usleep(5000); // 5ms
    }
    usleep(10000000);
    return NULL;
}

int main()
{
    pthread_t tid[4];

    pthread_create(&tid[0], NULL, thread_1, NULL);
    pthread_setname_np(tid[0], "Thread-1");

    //pthread_create(&tid[1], NULL, thread_1, NULL);
    //pthread_setname_np(tid[1], "Thread-2");

    //pthread_create(&tid[2], NULL, thread_1, NULL);
    usleep(1500000);
    VarMonitor::stop("Thread-1");
    printf("Thread-1 stop!\n");
    usleep(1500000);
    VarMonitor::start("Thread-1");
    printf("Thread-1 restart!\n");
    pthread_join(tid[0], NULL);
    //pthread_join(tid[1], NULL);
    return 0;
}