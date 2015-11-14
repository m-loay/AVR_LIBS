/*
 * main.c
 *
 *  Created on: Nov 14, 2015
 *      Author: Mohamed
 */


#include "common.h"

int main (void)
{

	//DIO_init();
	u8 data=0;;
	DIO_set_port_direction(PORT0,OUTPUT);
	DIO_set_port(PORT0,0x00);

	TWI_MASTER_init();
	TWI_MASTER_Send_START();
	TWI_MASTER_Send_Address(0b11010000);
	//TWI_MASTER_Send_Byte(0b1110000);
	//TWI_MASTER_Send_Stop();
	TWI_MASTER_Get_Byte(1,&data);
	DIO_set_port(PORT0,data);
	TWI_MASTER_Send_Stop();

	while(1)
	{

	}
	return(0);
}

