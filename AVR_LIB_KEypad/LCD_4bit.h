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
#include "LCD_CFG.h"
//prtotypes of functions
void lcd_command (unsigned char cmnd);
void lcd_data  (unsigned char data);
void lcd_init ();
void lcd_gotoxy (unsigned x, unsigned y);
void lcd_string_print (unsigned char *str);

#endif /* LCD_4BIT_H_ */
