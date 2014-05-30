/*
 * TWI_Salve.c
 *
 *  Created on: Jan 20, 2014
 *      Author: mody
 */
#include<avr/io.h>
#include"TWI_Slave.h"


void TWI_Slave_Init (void)
{
	/*Select Address of the slave*/
	TWAR=SLAVE_ADDRESS;
	/*Clear int flag and enable acknowledge to receive data.*/
	TWCR = ((1<<TWINT)+(1<<TWEA)+(1<<TWEN));
}
void Wait_TWI_int(void)
{
	while (!(TWCR & (1<<TWINT))) ;
}

void TWI_match_read_slave_R(void) //Function to match the slave address and slave dirction bit(read)
{
    if((TWSR & 0xF8)!=SRX_ADR_ACK)  // Loop till correct acknoledgement have been received
    {
        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        /*wait untin the TWINT hardware flag to be set*/
        Wait_TWI_int();
    }
}

void TWI_match_read_slave_T(void)
{
   if((TWSR & 0xF8)== STX_ADR_ACK)    // Loop till correct acknoledgement have been received
    {
        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        /*wait untin the TWINT hardware flag to be set*/
         Wait_TWI_int();
    }
}

unsigned char rec_data;

void TWI_read_slave(void)
{
    // Clear TWI interrupt flag,Get acknowlegement, Enable TWI

    TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    /*wait untin the TWINT hardware flag to be set*/
     Wait_TWI_int();
    if ((TWSR & 0xF8)==SRX_DATA_ACK)
    rec_data = TWDR;                // Get value from TWDR

}

void TWI_write_slave(unsigned char write_data)
{

    TWDR= write_data;              // Fill TWDR register whith the data to be sent
    TWCR= (1<<TWEN)|(1<<TWINT);   // Enable TWI, Clear TWI interrupt flag
    while((TWSR & 0xF8) != STX_DATA_NACK);
        //PORTA = (1 << 4); // Wait for the acknowledgement
}
