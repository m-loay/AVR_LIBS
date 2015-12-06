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
	u8 counter;
	DIO_init();
	DIO_set_pin_direction(PIN23,OUTPUT);
	DIO_set_pin(PIN23,LOW);

	TIMER2_Configure_Mode(TIMER2_MODE,TIMER2_OUT_MODE);
	TIMER2_Configure_CLK(TIMER2_CLK);
	TIMER2_out_compare_value(0x00);


	while(1)
	{
		for(counter=0;counter<256;counter++)
		{
			TIMER2_out_compare_value(counter);
			TO_DELAY(500);
			if(counter==255)counter=0;
		}
	}

	return(0);

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
**/
