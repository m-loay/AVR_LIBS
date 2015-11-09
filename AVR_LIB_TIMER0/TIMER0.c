/*
 * TIMER0.c
 *
 *  Created on: Nov 9, 2015
 *      Author: Mohamed
 */

#include "TIMER0.h"


/**  Initialize the Timer 0**/
void TIMER0_init(void)
{
	ASSIGN_REG(TCCR0,REG_CLR);
	ASSIGN_REG(TCNT0,REG_CLR);
	ASSIGN_REG(OCR0,REG_CLR);
	CLEAR_BIT(TIMSK,TOIE0);
	CLEAR_BIT(TIMSK,OCIE0);
	CLEAR_BIT(TIFR,TOV0);
	CLEAR_BIT(TIFR,OCF0);
}

/**  Select the mode and type of output
 * First Argument is about timer mode NORMAL ,PHASE_CORRECT_PWM,CTC,FAST_PWM
 * Second Argument os about timer output NORMAL_PORT,TOGGLE_OC0,CLEAR_OC0,SET_OC0
 * All the data can be found in TIMER0.h
 * **/
void TIMER0_Configure_Mode(u8 TMR0_Mode , u8 OUT_mode )
{
	switch (TMR0_Mode)
	{
	case NORMAL:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		switch (OUT_mode)
		{
		case NORMAL_PORT:
			CLEAR_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break;

		case TOGGLE_OC0:
			SET_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break;

		case CLEAR_OC0:
			CLEAR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;

		case SET_OC0:
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;

		default:break;
		}
		break;

		case PHASE_CORRECT_PWM:
			SET_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			switch (OUT_mode)
			{
			case NORMAL_PORT:
				CLEAR_BIT(TCCR0,COM00);
				CLEAR_BIT(TCCR0,COM01);
				break;

			case CLEAR_OC0:
				CLEAR_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
				break;

			case SET_OC0:
				SET_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
				break;

			default:break;
			}
			break;

			case CTC:
				CLEAR_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
				switch (OUT_mode)
				{
				case NORMAL_PORT:
					CLEAR_BIT(TCCR0,COM00);
					CLEAR_BIT(TCCR0,COM01);
					break;

				case TOGGLE_OC0:
					SET_BIT(TCCR0,COM00);
					CLEAR_BIT(TCCR0,COM01);
					break;

				case CLEAR_OC0:
					CLEAR_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
					break;

				case SET_OC0:
					SET_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
					break;

				default:break;
				}
				break;

				case FAST_PWM:
					SET_BIT(TCCR0,WGM00);
					SET_BIT(TCCR0,WGM01);
					switch (OUT_mode)
					{
					case NORMAL_PORT:
						CLEAR_BIT(TCCR0,COM00);
						CLEAR_BIT(TCCR0,COM01);
						break;

					case CLEAR_OC0:
						CLEAR_BIT(TCCR0,COM00);
						SET_BIT(TCCR0,COM01);
						break;

					case SET_OC0:
						SET_BIT(TCCR0,COM00);
						SET_BIT(TCCR0,COM01);
						break;

					default:break;
					}
					break;

					default:break;
	}
}


/**  Select the clock source
 * clk_1, clk_8, clk_64, clk_256, clk_1024, EXTclk_Falling_Edge, EXTclk_Rising_Edge
 * All the data can be found in TIMER0.h
 * **/
void TIMER0_Configure_CLK(u8 CLK_Mode )
{
	switch (CLK_Mode)
	{
	case clk_1:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;

	case clk_8:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;

	case clk_64:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;

	case clk_256:
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;

	case clk_1024:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);

		break;

	case EXTclk_Falling_Edge:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;

	case EXTclk_Rising_Edge:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;

	default:break;
	}

}


/*To load TCNT0 value*/
void TIMER0_set_timer_value(u8 value)
{
	TCNT0 = value;
}

/*To load OCR0 value*/
void TIMER0_out_compare_value(u8 value)
{
	OCR0 = value;
}

/*Enable Interrupt for timer overflow*/
void TIMER0_Overflow_Enable_ISR(void)
{
	SET_BIT(TIMSK ,TOIE0);
}

/*Disable Interrupt for timer overflow*/
void TIMER0_Overflow_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,TOIE0);
}

/*Enable Interrupt for PWM*/
void TIMER0_Outcmpare_Enable_ISR(void)
{
	SET_BIT(TIMSK ,OCIE0);
}

/*Disable Interrupt for PWM*/
void TIMER0_Outcmpare_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,OCIE0);
}

/*Get the status of flag overflow*/
u8 TIMER0_get_overflow_flag(void)
{
	return(GET_BIT(TIFR,TOV0));
}

/*Get the status of outcompare match status*/
u8 TIMER0_get_outcompare_flag(void)
{
	return(GET_BIT(TIFR,OCF0));
}
