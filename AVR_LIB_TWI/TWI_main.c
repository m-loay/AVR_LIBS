/*
 * TWI.c
 *
 *  Created on: Jan 20, 2014
 *      Author: mody
 */

#include<avr/io.h>
#include"TWI_Master.h"

/*Master Functions*/
/*Init the TWI module*/
void TWI_Init (void)
{
	/*Set own Salve Address*/
	TWAR = OWN_ADR;
	/*SCL Frequency=F_CPU/(16+2(TWBR).4^TWPS)*/
	TWBR=TWBR_Value;
	/* Enable the module from TWI Control Register*/
	TWCR|=(1<<TWEN);
}

/*Function to wait until the TWINT is set by hardware*/
void Wait_TWI_int(void)
{
	while (!(TWCR & (1<<TWINT))) ;
}

/*Send a Start condition or Repeated start*/
unsigned char Send_start (void)
{
	/*Send start condition from TWI control register*/
	TWCR|=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	/*wait untin the TWINT hardware flag to be set*/
	Wait_TWI_int();
	/*If status other than START or Repeated start */
	if((TWSR != START)&&(TWSR != REP_START))
		return TWSR;
	return SUCCESS;
}

/*Send Stop*/
void Send_stop(void)
{
	/*Send stop condition from TWI control register*/
	TWCR = ((1<<TWEN)+(1<<TWINT)+(1<<TWSTO));
}

/*Send the address of the slave+R/W bit*/
unsigned char Send_Address (unsigned char adr)
{
	/*Put the Address of the Salve in the TWDR*/
	TWDR=adr;
	/*wait untin the TWINT hardware flag to be set*/
	Wait_TWI_int();
	/*If NACK received return  TWSR*/
	if((TWSR != MTX_ADR_ACK)&&(TWSR != MRX_ADR_ACK))
		return TWSR;
	return SUCCESS;

}

unsigned char Send_byte (unsigned char data)
{
	/*Put the data in the TWI data register*/
	TWDR=data;
	/*wait untin the TWINT hardware flag to be set*/
	Wait_TWI_int();
	/*Check if a NACK is received*/
	if(TWSR != MTX_DATA_ACK)
		return TWSR;
	return SUCCESS;
}

unsigned char Get_byte (unsigned char last_byte)
{
	/*When receiving the last byte from the slave it will be sent a NACK to
		make the slave stop transmitting, all bits before the last will get
		an ACK*/
	if(last_byte)							//Not the last byte

		/*Clear int flag and enable acknowledge to receive data.*/
		TWCR = ((1<<TWINT)+(1<<TWEA)+(1<<TWEN));

	else									//Last byte
		/*Clear int flag to and do not enable acknowledge to tell the slave
			to stop transmitting*/
		TWCR = ((1<<TWINT)+(1<<TWEN));

	/*wait untin the TWINT hardware flag to be set*/
	Wait_TWI_int();

	/*Save the data received in a register*/
	data_recevied=TWDR;

	/*If ACK has been transmitted or this was the last byte and NACK has been
		sent -> return SUCCESS, else return TWSR*/
	if(((TWSR == MRX_DATA_NACK)&&(last_byte == 0))||(TWSR == MRX_DATA_ACK))
		return SUCCESS;
	return TWSR;
}

