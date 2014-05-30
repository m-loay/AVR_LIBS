/*
 * LCD_4bit.c
 *
 * Created: 2/23/2013 1:37:21 PM
 *  Author: mohamed
 */ 

//the command function

#include "LCD_4bit.h"


void lcd_command (unsigned char cmnd)
{
	lcd_data_port = (lcd_data_port & 0x0F)|(cmnd& 0xF0); //send cmnd to data port
	lcd_data_port &=~(1<<lcd_RS);//RS=0 for command
	lcd_data_port &=~(1<<lcd_RW);//RW=0 for data wite
	lcd_data_port |=(1<<lcd_EN);
	//delay_us(1);
	_delay_ms(5);
	lcd_data_port &=~(1<<lcd_EN);
	//delay_us(100);
	_delay_ms(5);
	lcd_data_port = (lcd_data_port & 0x0F) |(cmnd<<4);
	lcd_data_port |=(1<<lcd_EN);
	//delay_us(1);
	_delay_ms(5);
	lcd_data_port &=~(1<<lcd_EN);
	//delay_us(100);
	_delay_ms(5);
	
}

//the data function

void lcd_data  (unsigned char data)
{
	lcd_data_port= (lcd_data_port & 0x0F) |(data & 0xF0);
	lcd_data_port |= (1<<lcd_RS);
	lcd_data_port &=~(1<<lcd_RW);
	lcd_data_port |=(1<<lcd_EN);
	//delay_us(1);
	_delay_ms(5);
	lcd_data_port &=~(1<<lcd_EN);
	_delay_ms(5);
	lcd_data_port = (lcd_data_port & 0x0F)|(data <<4);
	lcd_data_port |=(1<<lcd_EN);
	//delay_us(1);
	_delay_ms(5);
	lcd_data_port &=~(1<<lcd_EN);
	//delay_us(100);
	_delay_ms(5);
	
}


//initialization of lcd
void lcd_init ()
{
	lcd_data_direction=0xFF;
	lcd_data_port &=~ (1<<lcd_EN);
	lcd_command (0x33);
	lcd_command (0x32);
	lcd_command (0x28);
	lcd_command (0x0E);
	lcd_command (0x01);
	//delay_us(2000);
	_delay_ms(2);
	lcd_command (0x06);
	
}

//control the position
void lcd_gotoxy (unsigned x, unsigned y)
{
unsigned char first_char_adr[]={0x80,0xC0,0x94,0xD4};
lcd_command(first_char_adr[y-1]+x-1);
//delay_us(100);
//_delay_ms(10);
}

//print a string
void lcd_string_print (unsigned char *str)
{
	unsigned char i=0;
	while (str[i] !=0)
	{
		lcd_data(str[i]);
		i++;
	}
}


