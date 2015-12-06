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
	DIO_set_pin_direction(PIN24,OUTPUT);

	while(1)
	{
		DIO_toggle_pin(PIN24);
		TO_DELAY(500);
	}

	return(0);
}

