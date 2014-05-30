/*
 * LCD_CFG_H_
 *
 *  Created on: Dec 20, 2013
 *      Author: mody
 */

#ifndef CFG_LCD_H_
#define CFG_LCD_H_

//Defs of the ports
#define lcd_data_port				PORTC
#define lcd_data_direction			DDRC
#define lcd_data_pin				PINC
#define lcd_RS						0
#define lcd_RW						1
#define lcd_EN						2

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

#endif /* LCD_CFG_H_ */
