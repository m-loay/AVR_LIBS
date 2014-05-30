#include <avr/interrupt.h>
#include <avr/I2C.h>
#include <avr/io.h>

int main(void)
{

    TWI_init_slave(0X01);
    DDRA = (1 << 0)|(1 << 1);
    while(1)
    {
        TWI_match_read_slave_R();
        TWI_read_slave();
        if(rec_data == 0X11)
            PORTA ^= (1 << 0);
        else
            PORTA ^= (1 << 1);
    }
    return 0;
}
