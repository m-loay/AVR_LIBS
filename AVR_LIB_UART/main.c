/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"

const char *message1="    USART    ";

int main (void)
{
	u8 data;
	u8 counter=1;

	DIO_init();
	DIO_set_pin_direction(PIN16,INPUT);
	DIO_set_pin_direction(PIN17,OUTPUT);

	LCD_init();
	LCD_gotoxy(1,1);
	printf("%s",message1);
	LCD_gotoxy(1,2);


	USART_init();

	while(1)
	{
		USART_Transmit_data('A');
		_delay_ms(500);


		LCD_gotoxy(counter,2);

		data=USART_Receiving_data();
		printf ("%c",data );
		counter++;
		if (counter==15)
		{
			LCD_gotoxy(1,2);
			printf("                ");
			LCD_gotoxy(1,2);
			counter=1;
		}


	}

	return(0);

}


