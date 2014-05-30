/*
 * main.c
 *
 *  Created on: Feb 17, 2014
 *      Author: mody
 */


#include <avr/io.h>
#include <util/delay.h>
#include"debounce_button.h"


int main(void)
{

	unsigned char flag;
	flag=0;
	DDRC =0xFF; //Makes first pin of PORTC as Output
	// OR DDRC = 0x01;
	PORTC=0x00;
	DDRD &= ~((1<<1)|(1<<2));//Makes firs pin of PORTD as Input
	// OR DDRD = 0x00; //Makes all pins of PORTD input
	PORTD|=(1<<1);


	while(1) //infinite loop
	{

		if(button_is_pressed_set(PIND,2)) //If switch is pressed
		{
			if (flag==0)
			{
				PORTC ^=(1<<PC0); //Turns OFF LED
				flag=1;
			}

		}
		else
		{
			flag=0;
		}
		//else PORTC &=~(1<<PC0); //Turns ON LED

	}
}

