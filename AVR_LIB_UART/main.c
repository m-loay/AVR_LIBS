/*
 * uart_main.c
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */

#include<avr/io.h>
#include <util/delay.h>
#include"usart.h"

int main(void)
{
	DDRC=0xFF;
	USART_Init();        //Call the USART initialization code

	while(1)
	{
		USART_putstring("hello");    //Pass the string to the USART_putstring function and sends it over the serial
		PORTC^=0xFF;
		_delay_ms(5000);        //Delay for 5 seconds so it will re-send the string every 5 seconds

	}

	return 0;
}

