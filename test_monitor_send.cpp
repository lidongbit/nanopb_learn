#include "var_monitor.h"
#include <iostream>
#include <pthread.h>
#include <sys/unistd.h>
using namespace std;
void *thread_1(void* param_ptr)
{   
    char thread_name[132];
    pthread_t pid = pthread_self();
    sprintf(thread_name, "Thread_%ld",pid);
    cout<< thread_name<< " start!\n";
    VarMonitor vm_tid1((const char*)thread_name);
    Eigen::Vector<double, 6> var;
    var<<1,1,1,1,1,1;
    double index = 0;
    for(int i=0;i<10000;i++)
    {
        index = i;
        var = var.array() + 1;
        VarMonitor::push_var("index", &index, 1);
        //cout << var.transpose()<<endl;
        for(int j=0;j<20;j++)
        {
            VarMonitor::push_var("Vector6", var);
        }
        VarMonitor::push_item();
        usleep(10);
    }
    usleep(20000000);
    return NULL;
}

int main()
{
    pthread_t tid[4];
    pthread_create(&tid[0], NULL, thread_1, NULL);
    //pthread_create(&tid[1], NULL, thread_2, NULL);
    //pthread_create(&tid[2], NULL, thread_1, NULL);
    pthread_join(tid[0], NULL);
    return 0;
}