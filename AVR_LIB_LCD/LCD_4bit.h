/*
 * LCD_4bit.h
 *
 * Created: 2/23/2013 1:38:54 PM
 *  Author: mohamed
 */ 


#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "LCD_CFG.h"

//define LCD Commands
/*The Commands of LCD*/
#define CLR_DISPLAY					0x01
#define RET_HOME					0x02
#define DEC_CURSOR					0x04
#define INC_CURSOR					0x06
#define SHIFT_DISPLAY_RIGHT			0x05
#define SHIFT_DISPLAY_LEFT			0x07
#define DISPLAY_OFF_CURSOR_OFF		0x08
#define DISPLAY_OFF_CURSOR_ON		0x0A
#define DISPLAY_ON_CURSOR_OFF		0x0C
#define DISPLAY_ON_CURSOR_BLINK		0x0E
#define SHIFT_CURSOR_RIGHT			0x10
#define SHIFT_CURSOR_LEFT			0x14
#define SHIFT_ENTIRE_DISPLAY_RIGHT	0x18
#define SHIFT_ENTIRE_EDISPLAY_LEFT	0x1C
#define FORCE_CURSOR_1ST_LINE		0X80
#define FORCE_CURSOR_2ND_LINE		0XC0
#define LINES_D4_D7_4BIT			0X28
#define LINES_D8_D7_8BIT			0X38


//prtotypes of functions
void lcd_init ();

#if bit4_mixed_mode_Enable==1
void lcd_mixed_pins (unsigned char nibbles);
#endif

void lcd_command (unsigned char cmnd);
void lcd_data  (unsigned char data);
void lcd_gotoxy (unsigned x, unsigned y);
void lcd_string_print (unsigned char *str);
int lcd_printf(char var, FILE *stream);
void To_delay (void);

#endif /* LCD_4BIT_H_ */
