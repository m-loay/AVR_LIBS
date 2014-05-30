/*
 * DIO.h
 *
 *  Created on: Jan 17, 2014
 *      Author: mody
 */

#ifndef DIO_H_
#define DIO_H_
#include<avr/io.h>
#include<util/delay.h>



/*the shift bit*/
#define BIT(x)			(1 << (x))
/*IN, OUT -> to set direction ip/op (Data Direction Register) */
#define OUT(port,pin)	((DDR  ## port) |=  (1<<pin))
#define IN(port,pin)	((DDR  ## port) &= ~(1<<pin))

/* SET, CLR -> pin to 1(set), pin to 0(clr)*/
#define CLR(port,pin)	((PORT ## port) &= ~(1<<pin))
#define SET(port,pin)	((PORT ## port) |=  (1<<pin))

/*TOGL -> toggle any pin*/
#define TOGL(port,pin)	((PORT ## port) ^=  (1<<pin))

/*equivalent to bit_is_clear, bit_is_set*/
#define READ(port,pin)	((PIN  ## port) &   (1<<pin))

#endif /* DIO_H_ */
