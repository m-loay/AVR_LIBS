/*
 * KEYPAD_Array.c
 *
 *  Created on: Nov 6, 2015
 *      Author: Mohamed
 */
#include "common.h"
#include "KEYPAD_Array_CFG.h"

u8 row,col;
/**Set You keypad Configuration on KEYPAD_Array_CFG.h
 * Specify with pins the Rows and columns of your keypad KEYPAD_Array_CFG.h
 * SPecify the keypad map in constant array dimension of 2*2 [ROW][COL]
 * prepare the two array list example
   const u8 row_array[ROW]={ROW0,ROW1,ROW2,ROW3};
   const u8 col_array[COL]={COL0,COL1,COL2};
   for keypad_map[ROW][COL]
 * **/

#if KEYPAD_44==1
//Conversion table from keypad input to corresponding character.
const u8 conv_table [4][4] =
{
		{'7',  '8',  '9',  '/'},
		{'4',  '5',  '6',  '*'},
		{'1',  '2',  '3',  '-'},
		{'n',  '0',  '=',  '+'}
};
const u8 row_array[ROW]={ROW0,ROW1,ROW2,ROW3};
const u8 col_array[COL]={COL0,COL1,COL2,COL3};

#endif


#if KEYPAD_43==1
//Conversion table from keypad input to corresponding character.
const u8 conv_table[4][3] =
{
		{'1',  '2',  '3'},
		{'4',  '5',  '6'},
		{'7',  '8',  '9'},
		{'*',  '0',  '#'},
};
const u8 row_array[ROW]={ROW0,ROW1,ROW2,ROW3};
const u8 col_array[COL]={COL0,COL1,COL2};

#endif

#if KEYPAD_33==1
//Conversion table from keypad input to corresponding character.
const u8 conv_table[3][3] =
{
		{'1',  '2',  '3'},
		{'4',  '5',  '6'},
		{'7',  '8',  '9'},
};
const u8 row_array[ROW]={ROW0,ROW1,ROW2};
const u8 col_array[COL]={COL0,COL1,COL2};

#endif

/**Initialization of Keypad port **/
void keypad_init(void)
{
	u8 row,col;
	for(row=0;row<ROW;row++)
	{
		/*Set the row of the keypad as output*/
		DIO_set_pin_direction(row_array[row],OUTPUT);
		/*Set the row of the keypad as output and make it high*/
		DIO_set_pin(row_array[row],HIGH);
	}

	for(col=0;col<COL;col++)
	{
		/*Set the col of the keypad as input*/
		DIO_set_pin_direction(col_array[col],INPUT);
		/*Set the col of the keypad as input with pull up*/
		DIO_set_pin_input_mode(col_array[col],PULLUP);
	}
}


/*This function is used to get key pressed in key pad*/
volatile u8 KEY_scan (void)
{


	keypad_init();

	for(row=0;row<ROW;row++)
	{
		TO_DELAY(DELAY_TIME_KEY);
		DIO_set_pin(row_array[row],LOW);

		for(col=0;col<COL;col++)
		{

			if(button_is_pressed_clear(col_array[col]))
			{
				return conv_table [row][col];
			}

		}

		TO_DELAY(DELAY_TIME_KEY);
		DIO_set_pin(row_array[row],HIGH);
	}

	return '\0';
}

/**Delay function**/

