/***********************
 *****DIO_Prog.c********
 **********************/
#include "common.h"
#include "DIO_Private.h"


/**This function is used to give initial value to all pins in the micro-controller
 * Also it can be configured through DIO_cfg.h
 * **/
void DIO_init(void)
{	
	PORT0_DIR = FUN_HELPER(PIN7_INIT_DIR_VALUE,PIN6_INIT_DIR_VALUE,PIN5_INIT_DIR_VALUE,PIN4_INIT_DIR_VALUE,PIN3_INIT_DIR_VALUE,PIN2_INIT_DIR_VALUE,PIN1_INIT_DIR_VALUE,PIN0_INIT_DIR_VALUE);
	PORT1_DIR = FUN_HELPER(PIN15_INIT_DIR_VALUE,PIN14_INIT_DIR_VALUE,PIN13_INIT_DIR_VALUE,PIN12_INIT_DIR_VALUE,PIN11_INIT_DIR_VALUE,PIN10_INIT_DIR_VALUE,PIN9_INIT_DIR_VALUE,PIN8_INIT_DIR_VALUE);
	PORT2_DIR = FUN_HELPER(PIN23_INIT_DIR_VALUE,PIN22_INIT_DIR_VALUE,PIN21_INIT_DIR_VALUE,PIN20_INIT_DIR_VALUE,PIN19_INIT_DIR_VALUE,PIN18_INIT_DIR_VALUE,PIN17_INIT_DIR_VALUE,PIN16_INIT_DIR_VALUE);
	PORT3_DIR = FUN_HELPER(PIN31_INIT_DIR_VALUE,PIN30_INIT_DIR_VALUE,PIN29_INIT_DIR_VALUE,PIN28_INIT_DIR_VALUE,PIN27_INIT_DIR_VALUE,PIN26_INIT_DIR_VALUE,PIN25_INIT_DIR_VALUE,PIN24_INIT_DIR_VALUE);

	PORT0_OUTPUT_VALUE = FUN_HELPER(PIN7_INIT_LEVEL_VALUE,PIN6_INIT_LEVEL_VALUE,PIN5_INIT_LEVEL_VALUE,PIN4_INIT_LEVEL_VALUE,PIN3_INIT_LEVEL_VALUE,PIN2_INIT_LEVEL_VALUE,PIN1_INIT_LEVEL_VALUE,PIN0_INIT_LEVEL_VALUE);
	PORT1_OUTPUT_VALUE = FUN_HELPER(PIN15_INIT_LEVEL_VALUE,PIN14_INIT_LEVEL_VALUE,PIN13_INIT_LEVEL_VALUE,PIN12_INIT_LEVEL_VALUE,PIN11_INIT_LEVEL_VALUE,PIN10_INIT_LEVEL_VALUE,PIN9_INIT_LEVEL_VALUE,PIN8_INIT_LEVEL_VALUE);
	PORT2_OUTPUT_VALUE = FUN_HELPER(PIN23_INIT_LEVEL_VALUE,PIN22_INIT_LEVEL_VALUE,PIN21_INIT_LEVEL_VALUE,PIN20_INIT_LEVEL_VALUE,PIN19_INIT_LEVEL_VALUE,PIN18_INIT_LEVEL_VALUE,PIN17_INIT_LEVEL_VALUE,PIN16_INIT_LEVEL_VALUE);
	PORT3_OUTPUT_VALUE = FUN_HELPER(PIN31_INIT_LEVEL_VALUE,PIN30_INIT_LEVEL_VALUE,PIN29_INIT_LEVEL_VALUE,PIN28_INIT_LEVEL_VALUE,PIN27_INIT_LEVEL_VALUE,PIN26_INIT_LEVEL_VALUE,PIN25_INIT_LEVEL_VALUE,PIN24_INIT_LEVEL_VALUE);

	return;
}

/**This function is used to set a pin High or LOW
 * First Argument number of the pin number (can be found in DIO_Interface.h)
 * second Argument is the level (HIGH or LOW)
 * **/
void DIO_set_pin(u8 U8PinNum,u8 U8PinLevel)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_OUTPUT_VALUE) ,
									& (PORT1_OUTPUT_VALUE) ,
									& (PORT2_OUTPUT_VALUE) ,
									& (PORT3_OUTPUT_VALUE) };

	if(U8PinLevel)
		SET_BIT(*Ports_Array[(U8PinNum/8)],(U8PinNum%8));
	else
		CLEAR_BIT(*Ports_Array[(U8PinNum/8)],(U8PinNum%8));
	return;
}

/**This function is used to toggle a pin High or LOW
 * First Argument number of the pin number (can be found in DIO_Interface.h)
 * **/
void DIO_toggle_pin(u8 U8PinNum)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_OUTPUT_VALUE) ,
									& (PORT1_OUTPUT_VALUE) ,
									& (PORT2_OUTPUT_VALUE) ,
									& (PORT3_OUTPUT_VALUE) };

	TOGGLE_BIT(*Ports_Array[(U8PinNum/8)],(U8PinNum%8));

	return;
}

/**This function is used to NOT a pin High or LOW
 * First Argument number of the pin number (can be found in DIO_Interface.h)
 * **/
void DIO_not_pin(u8 U8PinNum)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_OUTPUT_VALUE) ,
									& (PORT1_OUTPUT_VALUE) ,
									& (PORT2_OUTPUT_VALUE) ,
									& (PORT3_OUTPUT_VALUE) };

	NOT_BIT(*Ports_Array[(U8PinNum/8)],(U8PinNum%8));

	return;
}

/**This function is used to set the pin direction
 * First Argument name of the pin number (can be found in DIO_Interface.h)
 * second Argument INPUT or OUTPUT
 * **/
void DIO_set_pin_direction(u8 U8PinNum,u8 U8Direction)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_DIR) ,
									& (PORT1_DIR) ,
									& (PORT2_DIR) ,
									& (PORT3_DIR) };

	if(U8Direction == OUTPUT)
		SET_BIT(*Ports_Array[(U8PinNum/8)] ,(U8PinNum%8));
	else
		CLEAR_BIT(*Ports_Array[(U8PinNum/8)] ,(U8PinNum%8));

	return;
}

/**This function is used to set the mode of the pin
 * First Argument name of the pin number (can be found in DIO_Interface.h)
 * second Argument HIGH_IMPEDENCE , PULLUP
 * **/
void DIO_set_pin_input_mode(u8 U8PinNum,u8 U8InputMode)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_OUTPUT_VALUE) ,
									& (PORT1_OUTPUT_VALUE) ,
									& (PORT2_OUTPUT_VALUE) ,
									& (PORT3_OUTPUT_VALUE)};

	if(U8InputMode == PULLUP)
		SET_BIT(*Ports_Array[(U8PinNum/8)] ,(U8PinNum%8));
	else
		CLEAR_BIT(*Ports_Array[(U8PinNum/8)] ,(U8PinNum%8));
	return;
}

/**This function is used to get the value of the pin
 * Argument name of the pin number (can be found in DIO_Interface.h)
 * and it returns the value of the port
 * **/
volatile u8 DIO_get_pin(u8 U8PinNum)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_INPUT_VALUE) ,
									& (PORT1_INPUT_VALUE) ,
									& (PORT2_INPUT_VALUE) ,
									& (PORT3_INPUT_VALUE)};

	return (GET_BIT(*Ports_Array[(U8PinNum/8)], (U8PinNum%8))  ) ;
}

/**This function is used to set a Port with certain value
 * First Argument name of the port name (can be found in DIO_Interface.h)
 * second Argument is the value
 * **/
void DIO_set_port(u8 U8PortNum,u8 U8PortValue)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_OUTPUT_VALUE) ,
									& (PORT1_OUTPUT_VALUE) ,
									& (PORT2_OUTPUT_VALUE) ,
									& (PORT3_OUTPUT_VALUE) };

	ASSIGN_REG(*Ports_Array[(U8PortNum)] , U8PortValue );
	return;
}

/**This function is used to toggle a Port
 * First Argument name of the port name (can be found in DIO_Interface.h)
 * **/
void DIO_toggle_port(u8 U8PortNum)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_OUTPUT_VALUE) ,
									& (PORT1_OUTPUT_VALUE) ,
									& (PORT2_OUTPUT_VALUE) ,
									& (PORT3_OUTPUT_VALUE) };

	TOGGLE_REG(*Ports_Array[(U8PortNum)]);
	return;
}


/**This function is used to set the port direction
 * First Argument name of the port name (can be found in DIO_Interface.h)
 * second Argument INPUT or OUTPUT
 * **/
void DIO_set_port_direction(u8 U8PortNum,u8 U8Direction)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_DIR) ,
									& (PORT1_DIR) ,
									& (PORT2_DIR) ,
									& (PORT3_DIR)};

	if(U8Direction == OUTPUT)
		SET_REG(*Ports_Array[(U8PortNum)]);
	else
		CLEAR_REG(*Ports_Array[(U8PortNum)]);
	return;
}



/**This function is used to set the mode of the pin
 * First Argument name of the pin number (can be found in DIO_Interface.h)
 * second Argument HIGH_IMPEDENCE , PULLUP
 * **/
void DIO_set_port_input_mode(u8 U8PortNum,u8 U8InputMode)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_OUTPUT_VALUE) ,
									& (PORT1_OUTPUT_VALUE) ,
									& (PORT2_OUTPUT_VALUE) ,
									& (PORT3_OUTPUT_VALUE)};

	if(U8InputMode == PULLUP)
		SET_REG(*Ports_Array[(U8PortNum)]);
	else
		CLEAR_REG(*Ports_Array[(U8PortNum)]);

	return;
}

/**This function is used to get the value of the port
 * Argument name of the port name (can be found in DIO_Interface.h)
 * and it returns the value of the port
 * **/
volatile u8 DIO_get_port(u8 U8PortNum)
{
	volatile u8 * Ports_Array[4] = {& (PORT0_INPUT_VALUE) ,
									& (PORT1_INPUT_VALUE) ,
									& (PORT2_INPUT_VALUE) ,
									& (PORT3_INPUT_VALUE)};
	return ( *Ports_Array[(U8PortNum)] ) ;
}





