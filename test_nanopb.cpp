#include <iostream>
#include <vector>
#include <pb.h>
#include <pb_encode.h>
#include "var_monitor_data.pb.h" // 包含生成的 C++ 代码头文件

bool item_produce(pb_ostream_t *stream, const pb_field_t *field, void * const *arg)
{
    VarMonitorData_Array item = {};
    std::vector<double> *dat = static_cast<std::vector<double>*>(*arg);
    item.cnt = dat->size();
    item.data;
    // 根据来自pb_field_t的常量信息对字段的标头进行编码
    pb_encode_tag_for_field(stream, field);

    // 根据FileInfo 结构对字段的数据进行编码
    pb_encode_submessage(stream, VarMonitorData_Array_fields, &item);
}

int main() {
    std::vector<std::vector<double>> vdat = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}, {3.1, 3.2, 3.3}};

    /* This is the buffer where we will store our message. */
    uint8_t buffer[128];
    size_t message_length;
    bool status;
    
    /* Encode our message */
    {
        /* Allocate space on the stack to store the message data.*/
        VarMonitorData mvar = VarMonitorData_init_zero;
        
        /* Create a stream that will write to our buffer. */
        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
        mvar.len = 3;
        mvar.item.funcs.encode = &item_produce;
        mvar.item.arg = &vdat;
        /* Fill in the lucky number */
        


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
    
    // /* Now we could transmit the message over network, store it in a file or
    //  * wrap it to a pigeon's leg.
    //  */

    // /* But because we are lazy, we will just decode it immediately. */
    
    // {
    //     /* Allocate space for the decoded message. */
    //     VarMonitorData message = VarMonitorData_init_zero;
        
    //     /* Create a stream that reads from the buffer. */
    //     pb_istream_t stream = pb_istream_from_buffer(buffer, message_length);
        
    //     /* Now we are ready to decode the message. */
    //     status = pb_decode(&stream, VarMonitorData_fields, &message);
        
    //     /* Check for errors... */
    //     if (!status)
    //     {
    //         printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
    //         return 1;
    //     }
        
    //     /* Print the data contained in the message. */
    //     printf("Your lucky number was %d!\n", (int)message.lucky_number);
    // }
    
  return 0;
}
