#include <stdio.h>

#include "crc32.h"




int main (int argc, char **argv)
{

    int return_value = 0;
    unsigned char buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,0x0A};

    static unsigned int buff_len = sizeof(buffer);
    
    int count;

    printf("Buffer: len=%d [", buff_len);
    for (count = 0;count< buff_len; count++)
    {
        printf("0x%0x, ", buffer[count]);
    }

    printf("]\n");

    unsigned long crc = CalculateBlockCRC32(buff_len, buffer);

    printf("CRC32 Value = %ld\n", crc);



    return return_value;
}
