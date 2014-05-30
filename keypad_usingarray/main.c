/*
 * main.c
 *
 *  Created on: Feb 18, 2014
 *      Author: mody
 */

#include<avr/io.h>
#include<util/delay.h>
#include"LCD_4bit.h"
#include"keypad_using_array.h"
int main(void)
{

	PORTC=0xFF;
	unsigned char key;
	static FILE mystdout = FDEV_SETUP_STREAM(lcd_printf, NULL, _FDEV_SETUP_WRITE);
	// setup our stdio stream
	stdout = &mystdout;

	keypad_init();
	lcd_init ();
	lcd_gotoxy(1,1);
	printf("keypad");
	lcd_gotoxy(1,2);

	while(1)
	{
		/* the function to get the pressed key*/
		key=key_scan();
		/*important to write only when a key is pressed*/
		//if (key!=0)	printf("%c",key);
		if (key!=0)	PORTC=key_scan();

	}
	return(0);
}

