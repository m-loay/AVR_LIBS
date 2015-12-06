/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"

volatile u8 flag=0;

int main (void)
{
	u16 counter;

	DIO_init();
	DIO_set_pin(PIN8,LOW);
	DIO_set_pin(PIN20,LOW);
	DIO_set_pin(PIN21,LOW);

	EXTERNAL_Interrupt_Configure(INTRRUPT_0,FALLING_EDGE,PULLUP);
	EXTERNAL_Interrupt_Enable(INTRRUPT_0);

	TIMER1_init();
	TIMER1_Configure_Mode(TIMER1_MODE);
	TIMER1_Configure_CLK(TIMER1_CLK);
	TIMER1_Configure_Output_Mode(TIMER1_OUT_MODE,TIMER1_CHANNEL);
	TIMER1_set_compare_A_value(0x00);

	Enable_Global_ISR();

	while(1)
	{
		for(counter=0;counter<1024;counter++)
		{
			if(flag==0)	TIMER1_set_compare_A_value(counter);
			else TIMER1_set_compare_B_value(counter);

			TO_DELAY(500);
			if(counter==1023)counter=0;
		}
	}

	return(0);

}

ISR(INT0_vect)
{
	if(flag==0)
	{
		TIMER1_Configure_Output_Mode(PWM_NON_INVERTED,CHANNEL_B);
		flag=1;
	}
	else
	{
		TIMER1_Configure_Output_Mode(PWM_NON_INVERTED,CHANNEL_A);
		flag=0;
	}
}

