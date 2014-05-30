#include <avr/io.h>

#ifndef I2C_H_INCLUDED
#define I2C_H_INCLUDED

/** master functions **/

void error(void)
{

    PORTA ^= (1 << 5);
}


void TWI_init(void) // Function to initialize master
{
    TWBR=0x01;    // Bit rate
    TWSR=(0<<TWPS1)|(0<<TWPS0); // Setting prescalar bits
    TWCR= (1 << TWEN);
    // SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
}

void TWI_start(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8) != 0X08)
        error();
}

void TWI_read_address_W(unsigned char SLA_W)
{
    TWDR = SLA_W;    // Address and read instruction
    TWCR = (1<<TWINT) | (1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
    if ((TWSR & 0xF8) != 0X18)
        error();  // Check for the acknoledgement
}

void TWI_read_address_R(unsigned char SLA_R)
{
    TWDR = SLA_R;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while (!(TWCR &(1<<TWINT)));
    while ((TWSR & 0XF8) != 0X40)
        error();
}

void TWI_write_data(unsigned char DATA)
{
    TWDR = DATA;    // put data in TWDR
    TWCR = (1<<TWINT) | (1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
    if ((TWSR & 0xF8) != 0X28)
        error(); // Check for the acknoledgement
}

unsigned char rec_data_master;
void TWI_read_data(void)
{
    while ((TWSR & 0XF8) != 0X58)
    {
        TWCR = (1<<TWINT) | (1<<TWEN);
        while (!(TWCR & (1<<TWINT)));
    }
    rec_data_master = TWDR;
}

void TWI_stop(void)
{
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

/** slave functions **/

void TWI_init_slave(unsigned char address) // Function to initilaize slave
{
    TWAR = address;    // Fill slave address to TWAR
    TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
}

void TWI_match_read_slave_R(void) //Function to match the slave address and slave dirction bit(read)
{
    while((TWSR & 0xF8)!= 0x60)  // Loop till correct acknoledgement have been received
    {
        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
    }
}

void TWI_match_read_slave_T(void)
{
    while((TWSR & 0xF8)!= 0xA8)    // Loop till correct acknoledgement have been received
    {
        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
    }
}

unsigned char rec_data;

void TWI_read_slave(void)
{
    // Clear TWI interrupt flag,Get acknowlegement, Enable TWI

    TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));    // Wait for TWINT flag
    if ((TWSR & 0xF8)!=0x80)
        error();        // Wait for acknowledgement
    rec_data = TWDR;                // Get value from TWDR

}

void TWI_write_slave(unsigned char write_data)
{

    TWDR= write_data;              // Fill TWDR register whith the data to be sent
    TWCR= (1<<TWEN)|(1<<TWINT);   // Enable TWI, Clear TWI interrupt flag
    while((TWSR & 0xF8) != 0xC0);
        //PORTA = (1 << 4); // Wait for the acknowledgement
}


#endif // I2C_H_INCLUDED
