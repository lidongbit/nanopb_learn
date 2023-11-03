#include "var_monitor.h"
#include <iostream>
#include <pthread.h>
using namespace std;
void *thread_1(void* param_ptr)
{   
    char thread_name[132];
    pthread_t pid = pthread_self();
    sprintf(thread_name, "Thread_%ld",pid);
    cout<< thread_name<< " start!\n";
    VarMonitor((const char*)thread_name);
    Eigen::Vector<double, 6> var;
    var<<1,1,1,1,1,1;
    for(int i=0;i<10;i++)
    {
        var = var.array() + 1;
        //cout << var.transpose()<<endl;
        VarMonitor::push_var(var);
        VarMonitor::push_item();
    }
}

int main()
{
    pthread_t tid[4];
	pthread_create(&tid[0], NULL, thread_1, NULL);
    //pthread_create(&tid[1], NULL, thread_1, NULL);
    //pthread_create(&tid[2], NULL, thread_1, NULL);

    while(1)
    {
        VarMonitor::upload();
    }
    return 0;
}