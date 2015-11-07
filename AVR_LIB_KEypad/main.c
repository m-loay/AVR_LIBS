/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"

const char *message1="     LCD_LIB    ";
const char *message2="      _AVR_    ";

int main (void)
{
	u8 key,count_c,count_r;
	count_c=0;
	count_r=0;
	DIO_init();
	keypad_init();
	LCD_init();
	LCD_gotoxy(1,1);
	printf("%s",message1);
	LCD_gotoxy(1,2);
	printf("%s",message2);
	TO_DELAY(2000);
	LCD_command(CLR_DISPLAY);
	LCD_gotoxy(1,1);

	while(1)
	{
		/* the function to get the pressed key*/
		key=KEY_scan();

		/*Proceesing the output from function*/
		if(key=='n')
		{
			LCD_command(CLR_DISPLAY);
			LCD_gotoxy(1,1);
			key='\0';
		}
		if (key!=0)	printf("%c",key) ;


	}

	return(0);

}



