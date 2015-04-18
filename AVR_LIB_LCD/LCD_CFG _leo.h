/*
 * LCD_CFG_H_
 *
 *  Created on: Dec 20, 2013
 *      Author: mody
 */

#ifndef CFG_LCD_H_
#define CFG_LCD_H_

#define bit4_cont_mode_Enable 	0
#define bit4_mixed_mode_Enable  1


#if bit4_cont_mode_Enable==1
//Defs of the ports
#define lcd_data_port				PORTB
#define lcd_data_direction			DDRB
#define lcd_data_pin				PINB
#define lcd_RS						PB0
#define lcd_RW						PB1
#define lcd_EN						PB2
#endif

#if bit4_mixed_mode_Enable==1
//Mixed Pins
#define RS_data_port				PORTC
#define RS_data_direction			DDRC
#define RS_data_pin					PC6

#define RW_data_port				PORTD
#define RW_data_direction			DDRD
#define RW_data_pin					PD4

#define EN_data_port				PORTD
#define EN_data_direction			DDRD
#define EN_data_pin					PD3

#define D4_data_port				PORTC
#define D4_data_direction			DDRC
#define D4_data_pin					PC7

#define D5_data_port				PORTF
#define D5_data_direction			DDRF
#define D5_data_pin					PF5

#define D6_data_port				PORTF
#define D6_data_direction			DDRF
#define D6_data_pin					PF4

#define D7_data_port				PORTF
#define D7_data_direction			DDRF
#define D7_data_pin					PF1
#endif


#endif /* LCD_CFG_H_ */
