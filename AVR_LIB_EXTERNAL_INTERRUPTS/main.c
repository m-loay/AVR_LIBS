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
	DIO_set_pin(PIN8,LOW);
	DIO_set_pin(PIN9,LOW);
	DIO_set_pin(PIN10,LOW);

	EXTERNAL_Interrupt_Configure(INTRRUPT_0,FALLING_EDGE,PULLUP);
	EXTERNAL_Interrupt_Configure(INTRRUPT_1,FALLING_EDGE,PULLUP);
	EXTERNAL_Interrupt_Configure(INTRRUPT_2,FALLING_EDGE,PULLUP);

	EXTERNAL_Interrupt_Enable(INTRRUPT_0);
	EXTERNAL_Interrupt_Enable(INTRRUPT_1);
	EXTERNAL_Interrupt_Enable(INTRRUPT_2);

	Enable_Global_ISR();

	while(1)
	{
		DIO_toggle_pin(PIN24);
		TO_DELAY(500);
	}

	return(0);

}


ISR(INT0_vect)
{
	int i=0;
	for(i=0;i<=5;i++)
	{
		DIO_toggle_pin(PIN8);
		TO_DELAY(500);
	}
}


ISR (INT1_vect)
{
	Enable_Global_ISR();
	int i=0;
	for(i=0;i<=5;i++)
	{
		DIO_toggle_pin(PIN9);
		TO_DELAY(500);
	}

}

ISR (INT2_vect)
{
	int i=0;
	for(i=0;i<=5;i++)
	{
		DIO_toggle_pin(PIN10);
		TO_DELAY(500);
	}
}



