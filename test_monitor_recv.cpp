#include "var_monitor.h"
#include <iostream>
#include <unistd.h>
#include "nanomsg/nn.h"
#include "nanomsg/pair.h"
using namespace std;

int main(void)
{   
    uint8_t buff[5*1024*1024];
    int vm_sock_;
    int cnt = 0;
    /* bind socket which is used for var monitor */
    if ((vm_sock_ = nn_socket(AF_SP, NN_PAIR)) < 0) {
        
        printf("sampleing nn_socket error!\n");
        return -1;
    }
    int to = 5000;
    if (nn_setsockopt(vm_sock_, NN_SOL_SOCKET, NN_RCVTIMEO, &to,
        sizeof(to)) < 0) {
        printf("nn_setsockopt error\n");
        return -1;
    }
    if (nn_connect(vm_sock_, "tcp://192.168.56.101:11119") < 0) {
        
        printf("sampleing nn_bind error!\n");
        nn_close(vm_sock_);
        return -1;
    }

    while(1)
    {
        // read total bytes
        int32_t total_bytes = 0;
        int bytes = nn_recv(vm_sock_, &total_bytes, sizeof(int32_t), 0);
        if (bytes < 0) {
            printf("nn_recv nothing\n");
            continue;
        }
        else {
            printf("total bytes: %d\n", total_bytes);
        }

        // rcv all sample data and write to file
        int cnt_bytes = 0;

        while (cnt_bytes < total_bytes) {

            char* buf = NULL;
            int bytes = nn_recv(vm_sock_, &buf, NN_MSG, 0);
            if (bytes < 0) {
                printf("nn_recv nothing\n");
                continue;;
            }

            memcpy(buff+cnt_bytes, buf, bytes);
            cnt_bytes += bytes;
            nn_freemsg(buf);
        }
   
        printf("============%d=============\n",cnt++);
        /* Allocate space for the decoded message. */
        VarMonitorData mdat = VarMonitorData_init_zero;
        /* Create a stream that reads from the buffer. */
        pb_istream_t stream = pb_istream_from_buffer(buff, total_bytes);
        VarMonitor::input_decode(mdat, stream);
        memset(buff, 0, 5*1024*1024);
        total_bytes = 0;
        usleep(100000);
    }

    nn_close(vm_sock_);
    return 0;
}