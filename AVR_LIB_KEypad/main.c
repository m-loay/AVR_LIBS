/*
 * LCD_4bit_mode.c
 *
 * Created: 5/3/2013 8:32:01 PM
 *  Author: mohamed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "LCD_4bit.h"
#include"keypad.h"

int main(void)
{

	unsigned char key;
	keypad_init();
	lcd_init ();
	lcd_gotoxy(1,1);
	lcd_string_print("keypad");
	lcd_gotoxy(1,2);

	while(1)
	{
	/* the function to get the pressed key*/
	key=get_key();
	/*important to write only when a key is pressed*/
	if (key!=0)	lcd_data(key);
	}

	return 0;
}


