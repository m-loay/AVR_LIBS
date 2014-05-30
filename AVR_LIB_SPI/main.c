/*
 * spi_master_main.c
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */

#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"

int main (void)
{
	SPI_MasterInit();

	while(1)
	{

		SPI_MasterSend_String ("REEM & MODY");
		_delay_ms(200);
		SPI_MasterSend(' ');
		_delay_ms(200);

	}
	return (0);
}
