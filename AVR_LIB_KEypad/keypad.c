	/*
	 * keypad.c
	 *
	 *  Created on: Dec 27, 2013
	 *      Author: mody
	 */

	#include "keypad.h"

	//Initialization of Keypad port
	void keypad_init(void)
	{

		KB_PORT_DDR = 0x0f;	//Key-board port, higer nibble - input, lower nibble - output
		KB_PORT_OUT = 0xff;		//pull-up enabled for higher nibble
	}

	//function to get the pressed key
	unsigned char get_key(void)
	{
		unsigned char upperNibble, keyCode, i;
		upperNibble = 0xff;
		unsigned char keyPressed;

		//for loop to ground each column
		for (i = 0; i < 4; i++) {
			_delay_ms(1);
			KB_PORT_OUT = ~(0x01 << i);
			_delay_ms(1);  		  	 		  //delay for port o/p settling
			upperNibble = KB_PORT_IN | 0x0f;

			if (upperNibble != 0xff) {
				_delay_ms(20); 		  		 //key debouncing delay
				upperNibble = KB_PORT_IN | 0x0f;
				if (upperNibble == 0xff)
					break;

				keyCode = (upperNibble & 0xf0) | (0x0f & ~(0x01 << i));

				while (upperNibble != 0xff)
					upperNibble = KB_PORT_IN | 0x0f;

				_delay_ms(20);   			   //key debouncing delay

				switch (keyCode)		//generating key characetr to display on LCD
				{
				case (0xe7):
					keyPressed = R4_C4;
					break;
				case (0xeb):
					keyPressed = R3_C4;
					break;
				case (0xdb):
					keyPressed = R3_C3;
					break;
				case (0xbb):
					keyPressed = R3_C2;
					break;
				case (0xed):
					keyPressed = R2_C4;
					break;
				case (0xdd):
					keyPressed = R2_C3;
					break;
				case (0xbd):
					keyPressed = R2_C2;
					break;
				case (0xee):
					keyPressed = R1_C4;
					break;
				case (0xde):
					keyPressed = R1_C3;
					break;
				case (0xbe):
					keyPressed = R1_C2;
					break;
				case (0xd7):
					keyPressed = R4_C3;
					break;
				case (0xb7):
					keyPressed = R4_C2;
					break;
				case (0x7e):
					keyPressed = R1_C1;
					break;
				case (0x7d):
					keyPressed = R2_C1;
					break;
				case (0x7b):
					keyPressed = R3_C1;
					break;
				case (0x77):
					keyPressed = R4_C1;
					break;
				default:
					keyPressed = 'X';
					break;
				}			   //end of switch

			}			   //end of if

		}			   //end of for
		return (keyPressed);
	}
