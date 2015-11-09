/***********************
 ****DIO_Config.h*******
 **********************/

#ifndef _DIO_CONFIG_H_
#define _DIO_CONFIG_H_

#include "common.h"



/**define the initial direction of each pin  *Range! OUTPUT ,INPUT  End**/

/*PORTB pins B0 to B7*/
#define 	PIN0_INIT_DIR_VALUE				INPUT
#define 	PIN1_INIT_DIR_VALUE				INPUT
#define 	PIN2_INIT_DIR_VALUE				INPUT
#define 	PIN3_INIT_DIR_VALUE				INPUT
#define 	PIN4_INIT_DIR_VALUE				INPUT
#define 	PIN5_INIT_DIR_VALUE				INPUT
#define 	PIN6_INIT_DIR_VALUE				INPUT
#define 	PIN7_INIT_DIR_VALUE				INPUT

/*PORTC pins C0 to C7*/
#define 	PIN8_INIT_DIR_VALUE				OUTPUT
#define 	PIN9_INIT_DIR_VALUE				OUTPUT
#define 	PIN10_INIT_DIR_VALUE			OUTPUT
#define 	PIN11_INIT_DIR_VALUE			OUTPUT
#define 	PIN12_INIT_DIR_VALUE			OUTPUT
#define 	PIN13_INIT_DIR_VALUE			OUTPUT
#define 	PIN14_INIT_DIR_VALUE			OUTPUT
#define 	PIN15_INIT_DIR_VALUE			OUTPUT

/*PORTD pins D0 to D7*/
#define 	PIN16_INIT_DIR_VALUE			INPUT
#define 	PIN17_INIT_DIR_VALUE			INPUT
#define 	PIN18_INIT_DIR_VALUE			INPUT
#define 	PIN19_INIT_DIR_VALUE			INPUT
#define 	PIN20_INIT_DIR_VALUE			INPUT
#define 	PIN21_INIT_DIR_VALUE			INPUT
#define 	PIN22_INIT_DIR_VALUE			INPUT
#define 	PIN23_INIT_DIR_VALUE			INPUT

/*PORTA pins A0 to A7*/
#define 	PIN24_INIT_DIR_VALUE			OUTPUT
#define 	PIN25_INIT_DIR_VALUE			OUTPUT
#define 	PIN26_INIT_DIR_VALUE			OUTPUT
#define 	PIN27_INIT_DIR_VALUE			OUTPUT
#define 	PIN28_INIT_DIR_VALUE			OUTPUT
#define 	PIN29_INIT_DIR_VALUE			OUTPUT
#define 	PIN30_INIT_DIR_VALUE			OUTPUT
#define 	PIN31_INIT_DIR_VALUE			OUTPUT


/*Comment!
 *define the initial value of each pin if it is "INPUT"
 *and if you are using "AVR" and the pin is "input" define the initial mode whether it is 
 *high impedance or pullup by setting the initial level value to LOW or HIGH respectively
 *Range! LOW ,HIGH
 End*/ 

/*PORTB pins B0 to B7*/
#define		PIN0_INIT_LEVEL_VALUE			LOW
#define		PIN1_INIT_LEVEL_VALUE			LOW
#define		PIN2_INIT_LEVEL_VALUE			LOW
#define		PIN3_INIT_LEVEL_VALUE			LOW
#define		PIN4_INIT_LEVEL_VALUE			LOW
#define		PIN5_INIT_LEVEL_VALUE			LOW
#define		PIN6_INIT_LEVEL_VALUE			LOW
#define		PIN7_INIT_LEVEL_VALUE			LOW

/*PORTC pins C0 to C7*/
#define		PIN8_INIT_LEVEL_VALUE			LOW
#define		PIN9_INIT_LEVEL_VALUE			LOW
#define		PIN10_INIT_LEVEL_VALUE			LOW
#define		PIN11_INIT_LEVEL_VALUE			LOW
#define		PIN12_INIT_LEVEL_VALUE			LOW
#define		PIN13_INIT_LEVEL_VALUE			LOW
#define		PIN14_INIT_LEVEL_VALUE			LOW
#define		PIN15_INIT_LEVEL_VALUE			LOW

/*PORTA pins D0 to D7*/
#define		PIN16_INIT_LEVEL_VALUE			LOW
#define		PIN17_INIT_LEVEL_VALUE			LOW
#define		PIN18_INIT_LEVEL_VALUE			LOW
#define		PIN19_INIT_LEVEL_VALUE			LOW
#define		PIN20_INIT_LEVEL_VALUE			LOW
#define		PIN21_INIT_LEVEL_VALUE			LOW
#define		PIN22_INIT_LEVEL_VALUE			LOW
#define		PIN23_INIT_LEVEL_VALUE			LOW

/*PORTA pins A0 to A7*/
#define		PIN24_INIT_LEVEL_VALUE			LOW
#define		PIN25_INIT_LEVEL_VALUE			LOW
#define		PIN26_INIT_LEVEL_VALUE			LOW
#define		PIN27_INIT_LEVEL_VALUE			LOW
#define		PIN28_INIT_LEVEL_VALUE			LOW
#define		PIN29_INIT_LEVEL_VALUE			LOW
#define		PIN30_INIT_LEVEL_VALUE			LOW
#define		PIN31_INIT_LEVEL_VALUE			LOW

#endif /* _DIO_CONFIG_H_ */
