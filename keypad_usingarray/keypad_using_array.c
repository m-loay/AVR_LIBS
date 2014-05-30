/*
 * keypad_using_array.c
 *
 *  Created on: Feb 18, 2014
 *      Author: mody
 */

#include"keypad_using_array.h"

#if KEYPAD_44==1
//Conversion table from keypad input to corresponding character.
unsigned char conv_table[] =
{
		'7',  '8',  '9',  '/',
		'4',  '5',  '6',  '*',
		'1',  '2',  '3',  '-',
		'n',  '0',  '=',  '+'
};
#endif

#if KEYPAD_43==1

//Conversion table from keypad input to corresponding character.
unsigned char conv_table[] =
{
		'1',  '2',  '3',
		'4',  '5',  '6',
		'7',  '8',  '9',
		'&',  '0',  '#',
};

#endif

//Initialization of Keypad port
	void keypad_init(void)
	{

		KB_PORT_DDR =0xF0;	//Key-board port, higer nibble - input, lower nibble - output
		KB_PORT_OUT =0xFF;		//pull-up enabled for higher nibble
	}

//Scan the keypad to see if a button is pressed.
unsigned char key_scan()
{
	unsigned char i,j;
	for( i = ROW ; i < TOTAL ; i++ )
	{ // Set one column at a time to Zero Voltage.
		 //Keep only ROW most significant bits.
		for ( j = 0; j < ROW ; j++ )
		{ //Scan each row checking if a button was pressed.
			KB_PORT_OUT =  ~(0x01 << i);
			_delay_ms(1);
			/* Use i and j to index into conversion table */
			if( button_is_pressed_clear(KB_PORT_IN,j) == 1 )
			{
				return conv_table[(i-ROW)+(j*ROW)];
			}
		}
	}
	return '\0';
}

