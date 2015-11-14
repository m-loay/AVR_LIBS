/**********************
 ****DIO_Interface.h***
 **********************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "common.h"
#include "std_typed.h"


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
