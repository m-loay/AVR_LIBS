/*
 * External_ISR.c
 *
 *  Created on: Nov 9, 2015
 *      Author: Mohamed
 */

#include "common.h"
#include "External_ISR_CFG.h"

/*This function is used to configure the interrupt number and its mode
 * The first argument takes the interrupt number INTRRUPT_0,INTRRUPT_1,INTRRUPT_2
 * The second arguments takes the mode LOW_LEVEL ,ANY_LOGICAL_CHANGE,
 * The third arguments is about input mode HIGH_IMPEDENCE , PULLUP
 * FALLING_EDGE, RISING_EDGE
 * IMPORTANT INT2 Modes only FALLING_EDGE or RISING_EDGE
 * */
void Configure_Interrupt(u8 INT_Number , u8 INT_Mode,u8 Input_Mode)
{
	switch(INT_Number)
	{
	case INTRRUPT_0:
		switch(INT_Mode)
		{
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			DIO_set_pin_direction(INT0_PIN,INPUT);
			DIO_set_pin(INT0_PIN,Input_Mode);
			break;

		case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			DIO_set_pin_direction(INT0_PIN,INPUT);
			DIO_set_pin(INT0_PIN,Input_Mode);
			break;

		case FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC01);
			DIO_set_pin_direction(INT0_PIN,INPUT);
			DIO_set_pin(INT0_PIN,Input_Mode);
			break;

		case RISING_EDGE:
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC01);
			DIO_set_pin_direction(INT0_PIN,INPUT);
			DIO_set_pin(INT0_PIN,Input_Mode);
			break;

		default:break;
		}
		break;

		case INTRRUPT_1:
			switch(INT_Mode)
			{
			case LOW_LEVEL:
				CLEAR_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				DIO_set_pin_direction(INT1_PIN,INPUT);
				DIO_set_pin(INT1_PIN,Input_Mode);
				break;

			case ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				DIO_set_pin_direction(INT1_PIN,INPUT);
				DIO_set_pin(INT1_PIN,Input_Mode);
				break;

			case FALLING_EDGE:
				CLEAR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				DIO_set_pin_direction(INT1_PIN,INPUT);
				DIO_set_pin(INT1_PIN,Input_Mode);
				break;

			case RISING_EDGE:
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				DIO_set_pin_direction(INT1_PIN,INPUT);
				DIO_set_pin(INT1_PIN,Input_Mode);
				break;

			default:break;
			}
			break;

			case INTRRUPT_2:
				switch(INT_Mode)
				{
				case FALLING_EDGE:
					CLEAR_BIT(MCUCSR,ISC2);
					DIO_set_pin_direction(INT2_PIN,INPUT);
					DIO_set_pin(INT2_PIN,Input_Mode);
					break;

				case RISING_EDGE:
					SET_BIT(MCUCSR,ISC2);
					DIO_set_pin_direction(INT2_PIN,INPUT);
					DIO_set_pin(INT2_PIN,Input_Mode);
					break;

				default:break;
				}
				break;

				default:break;
	}
}


/*This function is used to Enables the interrupt
 * The argument takes the interrupt number INTRRUPT_0,INTRRUPT_1,INTRRUPT_2
 * */
void Enable_Interrupt (u8 INT_Number )
{
	switch (INT_Number)
	{
	case INTRRUPT_0:
		SET_BIT(GICR,INT0);
		break;

	case INTRRUPT_1:
		SET_BIT(GICR,INT1);
		break;

	case INTRRUPT_2:
		SET_BIT(GICR,INT0);
		break;

		default:break;
	}
}

/*This function is used to Disable the interrupt
 * The argument takes the interrupt number INTRRUPT_0,INTRRUPT_1,INTRRUPT_2
 * */
void Disable_Interrupt (u8 INT_Number )
{
	switch (INT_Number)
	{
	case INTRRUPT_0:
		CLEAR_BIT(GICR,INT0);
		break;

	case INTRRUPT_1:
		CLEAR_BIT(GICR,INT1);
		break;

	case INTRRUPT_2:
		CLEAR_BIT(GICR,INT0);
		break;

		default:break;
	}
}

/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function enable the global interrupt
 * **/
void Enable_Global_ISR (void)
{
	SET_BIT(SREG,7);
}

/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function disable the global interrupt
 * **/
void Disable_Global_ISR (void)
{
	CLEAR_BIT(SREG,7);
}

