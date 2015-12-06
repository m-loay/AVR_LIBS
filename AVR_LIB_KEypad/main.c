/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"
volatile u8 KeyPressed = '\0';

int main(void)
{
	u8 counter=0;

	DIO_init();
	keypad_init();
	LCD_init();

	LCD_gotoxy(1,1);
	printf("KEYPAD");
	TO_DELAY(2000);
	LCD_gotoxy(1,2);

	while(1)
	{
		/* the function to get the pressed key*/
		KeyPressed=KEY_scan();

		if (KeyPressed!='\0')
		{
			printf("%c",KeyPressed) ;
			counter++;
			if (counter==15)
			{
				LCD_gotoxy(1,2);
				printf("                ");
				LCD_gotoxy(1,2);
				counter=0;
			}

		}
		KeyPressed='\0';


	}
	return 0;
}

