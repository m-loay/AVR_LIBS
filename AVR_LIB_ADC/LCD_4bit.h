/*
 * LCD_4bit.h
 *
 * Created: 2/23/2013 1:38:54 PM
 *  Author: mohamed
 */ 


#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_


#include "LCD_CFG.h"
#include "common.h"
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
#define DELAY_TIME_LCD				5


//prtotypes of functions

/**  Initialization of LCD
 * Select 4bit mode ( continous port or mixed pins) from LCD_CFG.h file
 * **/
void LCD_init (void);

#if bit4_mixed_mode_Enable==1
/**
 * This function is used to serialize the data on mixed pins
 * **/
void lcd_mixed_pins (u8 nibbles);
#endif


/*
 * This finction is used to send command in lcd
 * select the proper command you want form LCD_4bit.h file
 * */
void LCD_command (u8 cmnd);

/*
 * This finction is used to send data to lcd */
void LCD_data  (u8 _data);

/*
 * This function is used to comtrol the position of writing in lcd
 * since the lcd 16 bit x axis and 2 bits in y axis */
void LCD_gotoxy (u16 x, u16 y);

/*This function is used to write strings to lcd*/
void LCD_string_print (u8 *str);



#endif /* LCD_4BIT_H_ */
