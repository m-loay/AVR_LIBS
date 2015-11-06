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
	DIO_init();
	LCD_init();
	LCD_gotoxy(1,1);
	printf("%s",message1);
	LCD_gotoxy(1,2);
	printf("%s",message2);



	while(1)
	{

	}

	return(0);

}



