/*
 * TIMER1.c
 *
 *  Created on: Nov 17, 2015
 *      Author: Mohamed
 */

#include "TIMER1.h"

/**  Initialize the Timer 1**/
void TIMER1_init(void)
{
	CLEAR_REG(TCCR1A);
	CLEAR_REG(TCCR1B);

	CLEAR_REG(TCNT1);

	CLEAR_REG(OCR1A);
	CLEAR_REG(OCR1B);
	CLEAR_REG(ICR1);

	CLEAR_BIT(TIMSK,TOIE1);
	CLEAR_BIT(TIMSK,OCIE1A);
	CLEAR_BIT(TIMSK,OCIE1B);
	CLEAR_BIT(TIMSK,TICIE1);

	CLEAR_BIT(TIFR,TOV1);
	CLEAR_BIT(TIFR,OCF1A);
	CLEAR_BIT(TIFR,OCF1B);
	CLEAR_BIT(TIFR,ICF1);

}

/**  Select the mode and type of output
 *  Argument is about timer mode NORMAL ,PHASE_CORRECT_PWM,CTC,FAST_PWM,and another 10 modes
 * All the data can be found in TIMER1.h
 * **/
void TIMER1_Configure_Mode(u8 TMR1_Mode)
{
	switch (TMR1_Mode)
	{
	case NORMAL:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case PHASE_CORRECT_PWM_8:
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case PHASE_CORRECT_PWM_9:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case PHASE_CORRECT_PWM_10:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case CTC_OCR1A:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case FAST_PWM_8:
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case FAST_PWM_9:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case FAST_PWM_10:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case PHASE_FREQ_PWM_ICR1:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case PHASE_FREQ_PWM_OCR1A:
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case PHASE_CORRECT_PWM_ICR1:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case PHASE_CORRECT_PWM_OCR1A:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case CTC_ICR1:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case FAST_PWM_ICR1:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	case FAST_PWM_OCR1A:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

	default:break;
	}
}

/*This function to select the mode of oUTput and channel
 * First Argument enter the mode NORMAL_PORT , TOGGLE_OC , CLEAR_OC
 * SET_OC,PWM_INVERTED,PWM_NON_INVERTED
 * Second Enter the channel  CHANNEL_A ,CHANNEL_B
 *
 * */
void TIMER1_Configure_Output_Mode( u8 OUT_mode , u8 Channel)
{
	switch (Channel)
	{
	case CHANNEL_A:
		switch (OUT_mode)
		{
		case NORMAL_PORT:
			CLEAR_BIT(TCCR1A,COM1A0);
			CLEAR_BIT(TCCR1A,COM1A1);
			break;

		case TOGGLE_OC:
			SET_BIT(TCCR1A,COM1A0);
			CLEAR_BIT(TCCR1A,COM1A1);
			break;

		case CLEAR_OC:
			CLEAR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;

		case SET_OC:
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;

		case PWM_INVERTED:
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;

		case PWM_NON_INVERTED:
			CLEAR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;

		default:break;
		}
		break;

		case CHANNEL_B:
			switch(OUT_mode)
			{
			case NORMAL_PORT:
				CLEAR_BIT(TCCR1A,COM1B0);
				CLEAR_BIT(TCCR1A,COM1B1);
				break;

			case TOGGLE_OC:
				SET_BIT(TCCR1A,COM1B0);
				CLEAR_BIT(TCCR1A,COM1B1);
				break;

			case CLEAR_OC:
				CLEAR_BIT(TCCR1A,COM1B0);
				SET_BIT(TCCR1A,COM1B1);
				break;

			case SET_OC:
				SET_BIT(TCCR1A,COM1B0);
				SET_BIT(TCCR1A,COM1B1);
				break;

			case PWM_NON_INVERTED:
				CLEAR_BIT(TCCR1A,COM1B0);
				SET_BIT(TCCR1A,COM1B1);
				break;

			case PWM_INVERTED:
				SET_BIT(TCCR1A,COM1B0);
				SET_BIT(TCCR1A,COM1B1);
				break;
			default:break;
			}
			break;
			default:break;
	}
}

/**  Select the clock source
 * clk_1, clk_8, clk_64, clk_256, clk_1024, EXTclk_Falling_Edge, EXTclk_Rising_Edge
 * All the data can be found in TIMER1.h
 * **/
void TIMER1_Configure_CLK(u8 CLK_Mode )
{
	switch (CLK_Mode)
	{
	case clk_1:
		SET_BIT(TCCR1B ,CS10);
		CLEAR_BIT(TCCR1B ,CS11);
		CLEAR_BIT(TCCR1B ,CS12);
		break;

	case clk_8:
		CLEAR_BIT(TCCR1B ,CS10);
		SET_BIT(TCCR1B ,CS11);
		CLEAR_BIT(TCCR1B ,CS12);
		break;

	case clk_64:
		SET_BIT(TCCR1B ,CS10);
		SET_BIT(TCCR1B ,CS11);
		CLEAR_BIT(TCCR1B ,CS12);
		break;

	case clk_256:
		CLEAR_BIT(TCCR1B ,CS10);
		CLEAR_BIT(TCCR1B ,CS11);
		SET_BIT(TCCR1B ,CS12);
		break;

	case clk_1024:
		SET_BIT(TCCR1B ,CS10);
		CLEAR_BIT(TCCR1B ,CS11);
		SET_BIT(TCCR1B ,CS12);

		break;

	case EXTclk_Falling_Edge:
		CLEAR_BIT(TCCR1B ,CS10);
		SET_BIT(TCCR1B ,CS11);
		SET_BIT(TCCR1B ,CS12);
		break;

	case EXTclk_Rising_Edge:
		SET_BIT(TCCR1B ,CS10);
		SET_BIT(TCCR1B ,CS11);
		SET_BIT(TCCR1B ,CS12);
		break;

	default:break;
	}

}

/*To load TCNT1 value*/
void TIMER1_set_timer_value(u16 value)
{
	TIMER1_clear_Input_Capture_flag();
	TIMER1_clear_outcompare_A_flag();
	TIMER1_clear_outcompare_B_flag();
	TIMER1_clear_overflow_flag();
	OCR1B = 0x00;
	OCR1A = 0x00;

	TCNT1 = value;
}

/*To load OCR1A value*/
void TIMER1_set_compare_A_value(u16 value)
{
	TIMER1_clear_Input_Capture_flag();
	TIMER1_clear_outcompare_A_flag();
	TIMER1_clear_outcompare_B_flag();
	TIMER1_clear_overflow_flag();
	TCNT1 = 0x00;
	OCR1B = 0x00;

	OCR1A = value;
}

/*To load OCR1A value*/
void TIMER1_set_compare_B_value(u16 value)
{

	TIMER1_clear_Input_Capture_flag();
	TIMER1_clear_outcompare_A_flag();
	TIMER1_clear_outcompare_B_flag();
	TIMER1_clear_overflow_flag();
	TCNT1 = 0x00;
	OCR1A = 0x00;

	OCR1B = value;
}

/*Enable Interrupt for timer overflow*/
void TIMER1_Overflow_Enable_ISR(void)
{
	SET_BIT(TIMSK ,TOIE1);
}

/*Disable Interrupt for timer overflow*/
void TIMER1_Overflow_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,TOIE1);
}

/*Enable Interrupt for timer compare A*/
void TIMER1_Compare_A_Enable_ISR(void)
{
	SET_BIT(TIMSK ,OCIE1A);
}

/*Enable Interrupt for timer compare A*/
void TIMER1_Compare_A_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,OCIE1A);
}

/*Enable Interrupt for timer compare B*/
void TIMER1_Compare_B_Enable_ISR(void)
{
	SET_BIT(TIMSK ,OCIE1B);
}

/*Enable Interrupt for timer compare B*/
void TIMER1_Compare_B_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,OCIE1B);
}

/*Enable Interrupt for timer compare Input capture*/
void TIMER1_Input_Capture_Enable_ISR(void)
{

	SET_BIT(TIMSK ,TICIE1);
}

/*Enable Interrupt for timer compare Input capture*/
void TIMER1_Input_Capture_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK ,TICIE1);
}

/*Get the status of flag overflow*/
u8 TIMER1_get_overflow_flag(void)
{
	return(GET_BIT(TIFR,TOV1));
}

/*Get the status of outcompare match status*/
u8 TIMER1_get_outcompare_A_flag(void)
{
	return(GET_BIT(TIFR,OCF1A));
}

/*Get the status of outcompare match status*/
u8 TIMER1_get_outcompare_B_flag(void)
{
	return(GET_BIT(TIFR,OCF1B));
}

/*Get the status of outcompare match status*/
u8 TIMER1_get_Input_Capture_flag(void)
{
	return(GET_BIT(TIFR,ICF1));
}

/*Clear the status of flag overflow*/
void TIMER1_clear_overflow_flag(void)
{
	SET_BIT(TIFR,TOV1);
}

/*Clear the status of outcompare match status*/
void TIMER1_clear_outcompare_A_flag(void)
{
	SET_BIT(TIFR,OCF1A);
}

/*Clear the status of outcompare match status*/
void TIMER1_clear_outcompare_B_flag(void)
{
	SET_BIT(TIFR,OCF1B);
}

/*Clear the status of outcompare match status*/
void TIMER1_clear_Input_Capture_flag(void)
{
	SET_BIT(TIFR,ICF1);
}

