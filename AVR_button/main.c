/*
  * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"

int main (void)
{
	u8 flag=0;
	/*Init the All DIOS*/
	DIO_init();

	/*Configuration of pin0*/
	DIO_set_pin_direction(PIN18,INPUT);
	DIO_set_pin_input_mode(PIN18,HIGH_IMPEDENCE);

	/*Configuration of pin1*/
	DIO_set_pin_direction(PIN8,OUTPUT);
	DIO_set_pin(PIN8,LOW);

	while(1)
	{

		if(button_is_pressed_set(PIN18)==HIGH)
		{
			if(flag==0)
			{
				DIO_toggle_pin(PIN8);
				flag=1;
			}
			else flag=0;
			//DIO_set_pin(PIN1,DIO_get_pin(PIN0));
		}

	}

	return(0);

}



