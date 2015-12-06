/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"
//void TIMER0_delay (void);

int main (void)
{
	DIO_init();
	DIO_set_pin_direction(PIN3,OUTPUT);
	DIO_set_pin(PIN3,LOW);

	TIMER0_init();
	TIMER0_Configure_Mode(TIMER0_MODE,TIMER0_OUT_MODE);
	TIMER0_Configure_CLK(TIMER0_CLK);
	TIMER0_set_out_compare_value(TIMER0_VALUE);
	TIMER0_Outcmpare_Enable_ISR();

	Enable_Global_ISR();

	//u8 counter;
	while(1)
	{

	}

	return(0);

}


ISR (TIMER0_COMP_vect)
{
	static u8 counter=0;
	counter++;
	if(counter==17)
	{
	DIO_toggle_pin(PIN3);
	counter=0;
	}
}


/**
void TIMER0_delay (void)
{
	TIMER0_Configure_Mode(TIMER0_MODE,TIMER0_OUT_MODE);
	TIMER0_Configure_CLK(TIMER0_CLK);

	TIMER0_set_timer_value(TIMER0_VALUE);
	TIMER0_out_compare_value(OCR0_VALUE);

	while((GET_BIT(TIFR,TIMER0_FLAG))==0);
	SET_BIT(TIFR,TOV0);
	CLEAR_REG(TCCR0);
}

		for(counter=0;counter<256;counter++)
		{
			TIMER0_set_out_compare_value(counter);
			TO_DELAY(500);
			if(counter==255)counter=0;
		}
**/
