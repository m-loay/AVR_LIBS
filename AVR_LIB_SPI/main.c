/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"

int main (void)
{

	DIO_init();

	SPI_init();

	while(1)
	{
		SPI_send_byte('A');
		_delay_ms(300);
	}

	return(0);

}


