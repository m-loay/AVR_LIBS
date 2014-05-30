/*
 * main.c
 *
 *  Created on: Jan 17, 2014
 *      Author: mody
 */


#include<avr/io.h>
#include<util/delay.h>
#include"LCD_4bit.h"
const char *message1="     LCD_LIB    ";
const char *message2="      _AVR_    ";
double num=13.5;
int main (void)
{
	

	lcd_init();
	lcd_gotoxy(1,1);
	printf("%s",message1);
	lcd_gotoxy(1,2);
	printf("%s",message2);
lcd_command(0x18);

	while(1)
	{


	}
	return(0);
}
