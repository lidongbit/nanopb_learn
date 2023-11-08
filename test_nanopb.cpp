#include <iostream>
#include <vector>
#include <pb.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "var_monitor_data.pb.h" // 包含生成的 C++ 代码头文件

int main() {
    std::vector<std::vector<double>> vdat = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}, {3.1, 3.2, 3.3}};

    // /* This is the buffer where we will store our message. */
    uint8_t buffer[128];
    size_t message_length;
    bool status;
    
    // /* Encode our message */

    {
        /* Allocate space on the stack to store the message data.*/
        VarMonitorData mvar = VarMonitorData_init_zero;
        
        /* Create a stream that will write to our buffer. */
        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
        
        /* Fill in the lucky number */
        mvar.item_count = vdat.size();
        mvar.head_count = vdat.size();
        for(int i = 0; i<(int)mvar.item_count; ++i)
        {
            sprintf(mvar.head[i],"%d",i);
            mvar.item[i].data_count = vdat[i].size();
            for(int j = 0; j<(int)vdat[i].size(); ++j)
            {
                mvar.item[i].data[j] = vdat[i][j];
            }
        }
        
        /* Now we are ready to encode the message! */
        status = pb_encode(&stream, VarMonitorData_fields, &mvar);
        message_length = stream.bytes_written;
        
        /* Then just check for any errors.. */
        if (!status)
        {
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }
    }
    
    /* Now we could transmit the message over network, store it in a file or
     * wrap it to a pigeon's leg.
     */

    /* But because we are lazy, we will just decode it immediately. */

    {
        /* Allocate space for the decoded message. */
        VarMonitorData mvar = VarMonitorData_init_zero;
        
        /* Create a stream that reads from the buffer. */
        pb_istream_t stream = pb_istream_from_buffer(buffer, message_length);
        
        /* Now we are ready to decode the message. */
        status = pb_decode(&stream, VarMonitorData_fields, &mvar);
        
        /* Check for errors... */
        if (!status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
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
    
  return 0;
}
