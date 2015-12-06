/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile u8 i;
int main (void)
{

	TCCR1A=0x00;//normal mode
	TCCR1B=0x04;//normal mode ,prescalar 256
	TCNT1=0x0F000;
	TIMSK=1<<TOIE1;//unmash the timer interrupt
	sei ();//enable interrupt

	DIO_init();
	SEVEN_SEGMENTS_init();
	sei ();//enable interrupt

	while(1)
	{
		SEVEN_SEGMENTS_write(i);
	}

	return(0);

}


ISR (TIMER1_OVF_vect)
{
	TCNT1=0x0E000;
	i++;
	if(i==115)i=0;
}

