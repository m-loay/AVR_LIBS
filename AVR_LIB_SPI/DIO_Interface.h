/**********************
 ****DIO_Interface.h***
 **********************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include"std_typed.h"


/**  Zone Defines  **/

/*PORTB pins B0 to B7*/
#define		PIN0				0
#define		PIN1				1
#define		PIN2				2
#define		PIN3				3
#define		PIN4				4
#define		PIN5				5
#define		PIN6				6
#define		PIN7				7

/*PORTC pins C0 to C7*/
#define		PIN8				8
#define		PIN9				9
#define		PIN10				10
#define		PIN11				11
#define		PIN12				12
#define		PIN13				13
#define		PIN14				14
#define		PIN15				15

/*PORTD pins D0 to D7*/
#define		PIN16				16
#define		PIN17				17
#define		PIN18				18
#define		PIN19				19
#define		PIN20				20
#define		PIN21				21
#define		PIN22				22
#define		PIN23				23

/*PORTA pins A0 to A7*/
#define		PIN24				24
#define		PIN25				25
#define		PIN26				26
#define		PIN27				27
#define		PIN28				28
#define		PIN29				29
#define		PIN30				30
#define		PIN31				31


/*PORTB*/
#define		PORT0				0
/*PORTC*/
#define		PORT1				1
/*PORTD*/
#define		PORT2				2
/*PORTA*/
#define		PORT3				3


#define		LOW					0
#define		HIGH				1
#define 	PORT_HIGH			0xFF
#define 	PORT_LOW			0x00
#define 	PORT_OUTPUT			0xFF
#define 	PORT_INPUT			0x00

/**  AVR Status  **/
#define		INPUT				0
#define		OUTPUT				1
#define		HIGH_IMPEDENCE 		0
#define 	PULLUP				1

/**  AVR Registers  **/

#define PORT0_DIR				(*(volatile u8*) 0x37)//DDRB
#define PORT1_DIR				(*(volatile u8*) 0x34)//DDRC
#define PORT2_DIR				(*(volatile u8*) 0x31)//DDRD
#define PORT3_DIR				(*(volatile u8*) 0x3A)//DDRA

#define PORT0_OUTPUT_VALUE		(*(volatile u8*) 0x38)//PORTB
#define PORT1_OUTPUT_VALUE		(*(volatile u8*) 0x35)//PORTC
#define PORT2_OUTPUT_VALUE		(*(volatile u8*) 0x32)//PORTD
#define PORT3_OUTPUT_VALUE		(*(volatile u8*) 0x3B)//PORTA

#define PORT0_INPUT_VALUE		(*(volatile u8*) 0x36)//PINB
#define PORT1_INPUT_VALUE		(*(volatile u8*) 0x33)//PINC
#define PORT2_INPUT_VALUE		(*(volatile u8*) 0x30)//PIND
#define PORT3_INPUT_VALUE		(*(volatile u8*) 0x39)//PINA



/**  Public Functions  Zone  **/


/**This function is used to give initial value to all pins in the micro-controller
 * Also it can be configured through DIO_cfg.h
 * **/
void DIO_init(void);

/**This function is used to set a pin High or LOW
 * First Argument number of the pin (can be found in DIO_Interface.h)
 * second Argument is the level (HIGH or LOW)
 * **/
void DIO_set_pin(u8 U8PinNum,u8 U8PinLevel);

/**This function is used to toggle a pin High or LOW
 * First Argument number of the pin number (can be found in DIO_Interface.h)
 * **/
void DIO_toggle_pin(u8 U8PinNum);

/**This function is used to NOT a pin High or LOW
 * First Argument number of the pin number (can be found in DIO_Interface.h)
 * **/
void DIO_not_pin(u8 U8PinNum);

/**This function is used to set the pin direction of a pin
 * First Argument name of the pin (can be found in DIO_Interface.h)
 * second Argument INPUT or OUTPUT
 * **/
void DIO_set_pin_direction(u8 U8PinNum,u8 U8Direction);

/**This function is used to set the mode of the pin
 * First Argument name of the pin number (can be found in DIO_Interface.h)
 * second Argument HIGH_IMPEDENCE , PULLUP
 * **/
void DIO_set_pin_input_mode(u8 U8PinNum,u8 U8InputMode);

/**This function is used to get the value of the pin
 * Argument name of the pin number (can be found in DIO_Interface.h)
 * and it returns the value of the port
 * **/
volatile u8 DIO_get_pin(u8 U8PinNum);

/**This function is used to set a Port with certain value
 * First Argument name of the port (can be found in DIO_Interface.h)
 * second Argument is the value
 * **/
void DIO_set_port(u8 U8PortNum,u8 U8PortValue);

/**This function is used to toggle a Port
 * First Argument name of the port name (can be found in DIO_Interface.h)
 * **/
void DIO_toggle_port(u8 U8PortNum);

/**This function is used to set the port direction
 * First Argument name of the port (can be found in DIO_Interface.h)
 * second Argument INPUT or OUTPUT
 * **/
void DIO_set_port_direction(u8 U8PortNum,u8 U8Direction);

/**This function is used to set the mode of the pin
 * First Argument name of the pin number (can be found in DIO_Interface.h)
 * second Argument HIGH_IMPEDENCE , PULLUP
 * **/
void DIO_set_port_input_mode(u8 U8PortNum,u8 U8InputMode);

/**This function is used to get the value of the port
 * Argument name of the port name (can be found in DIO_Interface.h)
 * and it returns the value of the port
 * **/
volatile u8 DIO_get_port(u8 U8PortNum);





#endif /* _DIO_INTERFACE_H_ */
