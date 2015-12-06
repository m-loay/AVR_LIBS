/*
 * TIMER2.c
 *
 *  Created on: Nov 17, 2015
 *      Author: Mohamed
 */

#include "TIMER2.h"
/*Initialize timer 2*/
void TIMER2_init(void)
{
	CLEAR_REG(TCCR2);
	CLEAR_REG(TCNT2);
	CLEAR_REG(OCR2);
	CLEAR_REG(ASSR);
	CLEAR_BIT(TIMSK,TOIE2);
	CLEAR_BIT(TIMSK,OCIE2);
	CLEAR_BIT(TIFR,TOV2);
	CLEAR_BIT(TIFR,OCF2);
}

/**  Select the mode and type of output
 * First Argument is about timer mode NORMAL ,PHASE_CORRECT_PWM,CTC,FAST_PWM
 * Second Argument os about timer output NORMAL_PORT,TOGGLE_OC2,CLEAR_OC2,SET_OC2
 * All the data can be found in TIMER2.h
 * **/
void TIMER2_Configure_Mode(u8 TMR2_Mode , u8 OUT_mode )
{
	switch (TMR2_Mode)
	{
	case NORMAL:
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		switch (OUT_mode)
		{
		case NORMAL_PORT:
			CLEAR_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;

		case TOGGLE_OC2:
			SET_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;

		case CLEAR_OC2:
			CLEAR_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;

		case SET_OC2:
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;

		default:break;
		}
		break;

		case PHASE_CORRECT_PWM:
			SET_BIT(TCCR2,WGM20);
			CLEAR_BIT(TCCR2,WGM21);
			switch (OUT_mode)
			{
			case NORMAL_PORT:
				CLEAR_BIT(TCCR2,COM20);
				CLEAR_BIT(TCCR2,COM21);
				break;

			case CLEAR_OC2:
				CLEAR_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
				break;

			case SET_OC2:
				SET_BIT(TCCR2,COM20);
				SET_BIT(TCCR2,COM21);
				break;

			default:break;
			}
			break;

			case CTC:
				CLEAR_BIT(TCCR2,WGM20);
				SET_BIT(TCCR2,WGM21);
				switch (OUT_mode)
				{
				case NORMAL_PORT:
					CLEAR_BIT(TCCR2,COM20);
					CLEAR_BIT(TCCR2,COM21);
					break;

				case TOGGLE_OC2:
					SET_BIT(TCCR2,COM20);
					CLEAR_BIT(TCCR2,COM21);
					break;

				case CLEAR_OC2:
					CLEAR_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
					break;

				case SET_OC2:
					SET_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
					break;

				default:break;
				}
				break;

				case FAST_PWM:
					SET_BIT(TCCR2,WGM20);
					SET_BIT(TCCR2,WGM21);
					switch (OUT_mode)
					{
					case NORMAL_PORT:
						CLEAR_BIT(TCCR2,COM20);
						CLEAR_BIT(TCCR2,COM21);
						break;

					case CLEAR_OC2:
						CLEAR_BIT(TCCR2,COM20);
						SET_BIT(TCCR2,COM21);
						break;

					case SET_OC2:
						SET_BIT(TCCR2,COM20);
						SET_BIT(TCCR2,COM21);
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
void TIMER2_Configure_CLK(u8 CLK_Mode )
{
	switch (CLK_Mode)
	{
	case clk_1:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;

	case clk_8:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;

	case clk_64:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;

	case clk_256:
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;

	case clk_1024:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);

		break;

	case EXTclk_Falling_Edge:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;

	case EXTclk_Rising_Edge:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;

	default:break;
	}

}

/*To load TCNT2 value*/
void TIMER2_set_timer_value(u8 value)
{
	TIMER2_clear_outcompare_flag();
	TIMER2_clear_overflow_flag();
	OCR2=0x00;

	TCNT2 = value;
}

/*To load OCR2 value*/
void TIMER2_out_compare_value(u8 value)
{
	TIMER2_clear_outcompare_flag();
	TIMER2_clear_overflow_flag();
	TCNT2 = 0x00;

	OCR2 = value;
}

/*Enable Interrupt for timer overflow*/
void TIMER2_Overflow_Enable_ISR(void)
{
	SET_BIT(TIMSK ,TOIE2);
}

/*Disable Interrupt for timer overflow*/
void TIMER2_Overflow_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,TOIE2);
}

/*Enable Interrupt for PWM*/
void TIMER2_Outcmpare_Enable_ISR(void)
{
	SET_BIT(TIMSK ,OCIE2);
}

/*Disable Interrupt for PWM*/
void TIMER2_Outcmpare_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,OCIE2);
}

/*Get the status of flag overflow*/
u8 TIMER2_get_overflow_flag(void)
{
	return(GET_BIT(TIFR,TOV2));
}

/*Get the status of outcompare match status*/
u8 TIMER2_get_outcompare_flag(void)
{
	return(GET_BIT(TIFR,OCF2));
}

/*clear the status of flag overflow*/
void TIMER2_clear_overflow_flag(void)
{
	SET_BIT(TIFR,TOV2);
}

/*clear the status of outcompare match status*/
void TIMER2_clear_outcompare_flag(void)
{
	SET_BIT(TIFR,OCF2);
}
