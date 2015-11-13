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
	SPI_Enable_ISR();

	while(1)
	{
		SPI_send_byte('A');
		TO_DELAY(300);

	}

	return(0);

}

