/*
 * LCD_4bit.c
 *
 * Created: 2/23/2013 1:37:21 PM
 *  Author: mohamed
 */ 

//the command function

#include "LCD_4bit.h"
#include "LCD_private.h"

/**  Initialization of LCD
 * Select 4bit mode ( continous port or mixed pins) from LCD_CFG.h file
 * **/
void LCD_init (void)
{
	/**  setup our stdio stream **/
	static FILE mystdout = FDEV_SETUP_STREAM(lcd_printf, NULL, _FDEV_SETUP_WRITE);
	stdout = &mystdout;

	/**** 4bit mode one port ****/
#if bit4_cont_mode_Enable==1

	DIO_set_port_direction(LCD_DATA_DIRECTION,PORT_OUTPUT);
	DIO_set_pin(EN_DATA_PIN,LOW);

#endif

	/** 4bit mode mixed mode **/
#if bit4_mixed_mode_Enable==1

	DIO_set_pin_direction(RS_DATA_PIN,OUTPUT);
	DIO_set_pin_direction(EN_DATA_PIN,OUTPUT);
	DIO_set_pin_direction(D4_DATA_PIN,OUTPUT);
	DIO_set_pin_direction(D5_DATA_PIN,OUTPUT);
	DIO_set_pin_direction(D6_DATA_PIN,OUTPUT);
	DIO_set_pin_direction(D7_DATA_PIN,OUTPUT);

#endif

	LCD_command (0x33);
	LCD_command (0x32);
	LCD_command (LINES_D4_D7_4BIT);
	LCD_command (DISPLAY_ON_CURSOR_BLINK);
	LCD_command (CLR_DISPLAY);
	To_delay();
	LCD_command (INC_CURSOR);
}


/** 4bit mode mixed mode **/
#if bit4_mixed_mode_Enable==1
/**
 * This function is used to serialize the data on mixed pins
 * **/
void lcd_mixed_pins (u8 nibbles)
{
	if (nibbles & (1<<4)) DIO_set_pin(D4_DATA_PIN,HIGH) ; else DIO_set_pin(D4_DATA_PIN,LOW);
	if (nibbles & (1<<5)) DIO_set_pin(D5_DATA_PIN,HIGH) ; else DIO_set_pin(D5_DATA_PIN,LOW);
	if (nibbles & (1<<6)) DIO_set_pin(D6_DATA_PIN,HIGH) ; else DIO_set_pin(D6_DATA_PIN,LOW);
	if (nibbles & (1<<7)) DIO_set_pin(D7_DATA_PIN,HIGH) ; else DIO_set_pin(D7_DATA_PIN,LOW);
}
#endif

/*
 * This finction is used to send command in lcd
 * select the proper command you want form LCD_4bit.h file
 * */
void LCD_command (u8 cmnd)
{
	/**** 4bit mode one port ****/
#if bit4_cont_mode_Enable==1

	ASSIGN_NIBBLE_DL (LCD_DATA_PORT,cmnd);
	DIO_set_pin(RS_DATA_PIN,LOW);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

	ASSIGN_NIBBLE_DH(LCD_DATA_PORT,cmnd);
	DIO_set_pin(RS_DATA_PIN,LOW);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

#endif

	/** 4bit mode mixed mode **/
#if bit4_mixed_mode_Enable==1

	lcd_mixed_pins(cmnd & 0xF0);
	DIO_set_pin(RS_DATA_PIN,LOW);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

	lcd_mixed_pins(SHIFT_NIBBLE_L(cmnd));
	DIO_set_pin(RS_DATA_PIN,LOW);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

#endif

}


/*
 * This finction is used to send data to lcd */
void LCD_data  (u8 _data)
{

	/**** 4bit mode one port ****/
#if bit4_cont_mode_Enable==1

	ASSIGN_NIBBLE_DL (LCD_DATA_PORT,_data);
	DIO_set_pin(RS_DATA_PIN,HIGH);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

	ASSIGN_NIBBLE_DH(LCD_DATA_PORT,_data);
	DIO_set_pin(RS_DATA_PIN,HIGH);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

#endif

	/** 4bit mode mixed mode **/
#if bit4_mixed_mode_Enable==1
	lcd_mixed_pins( _data & 0xF0);
	DIO_set_pin(RS_DATA_PIN,HIGH);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

	lcd_mixed_pins(SHIFT_NIBBLE_L(_data));
	DIO_set_pin(RS_DATA_PIN,HIGH);
	DIO_set_pin(EN_DATA_PIN,HIGH);
	To_delay();
	DIO_set_pin(EN_DATA_PIN,LOW);
	To_delay();

#endif


}

/*
 * This function is used to comtrol the position of writing in lcd
 * since the lcd 16 bit x axis and 2 bits in y axis */
void LCD_gotoxy (u16 x, u16 y)
{
	unsigned char first_char_adr[]={0x80,0xC0,0x94,0xD4};
	LCD_command(first_char_adr[y-1]+x-1);
	To_delay();
}


/*This function is used to write strings to lcd*/
void LCD_string_print (u8 *str)
{
	unsigned char i=0;
	while (str[i] !=0)
	{
		LCD_data(str[i]);
		i++;
	}
}



// this function is called by printf as a stream handler
int lcd_printf(char var, FILE *stream)
{
	// translate \n to \r for br@y++ terminal
	if (var == '\n') LCD_data('\r');
	LCD_data(var);
	return 0;
}

/*To generate delay*/
void To_delay (void)
{
	_delay_ms(5);
}
