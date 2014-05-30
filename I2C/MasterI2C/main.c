#include <avr/interrupt.h>
#include <avr/I2C.h>
#include <avr/io.h>

int main(void)
{
    TWI_init();
    while(1)
    {
        TWI_start();
        TWI_read_address_W(0x00);
        TWI_write_data(0X11);
        TWI_stop();

    }

    return 0;
}
