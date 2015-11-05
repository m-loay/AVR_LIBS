/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"
#include <util/delay.h>
int main (void)
{
	DIO_init();
	DIO_set_pin_direction(PORT0_DIR,OUTPUT);
	DIO_set_pin_direction(PORT1_DIR,OUTPUT);

	while(1)
	{
		DIO_set_pin(PIN0,HIGH);
		DIO_toggle_port(PORT1);
		_delay_ms(500);
		DIO_set_pin(PIN0,LOW);
		_delay_ms(500);
	}

	return(0);
}

