/*
 * TIMER1.h
 *
 *  Created on: Nov 17, 2015
 *      Author: Mohamed
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "common.h"
#include "TIMER1_CFG.h"

#define		NORMAL						0

#define 	PHASE_CORRECT_PWM_8			1
#define 	PHASE_CORRECT_PWM_9			2
#define 	PHASE_CORRECT_PWM_10		3

#define		CTC_OCR1A					4

#define		FAST_PWM_8					5
#define		FAST_PWM_9					6
#define		FAST_PWM_10					7

#define		PHASE_FREQ_PWM_ICR1			8
#define		PHASE_FREQ_PWM_OCR1A		9

#define 	PHASE_CORRECT_PWM_ICR1		10
#define 	PHASE_CORRECT_PWM_OCR1A		11

#define		CTC_ICR1					12

#define		FAST_PWM_ICR1				13
#define		FAST_PWM_OCR1A				14


#define 	PWM_INVERTED				4
#define 	PWM_NON_INVERTED			5

#define 	NORMAL_PORT					0
#define     TOGGLE_OC					1
#define     CLEAR_OC					2
#define     SET_OC						3
#define 	PWM_INVERTED				4
#define 	PWM_NON_INVERTED			5

#define 	CHANNEL_A					0
#define 	CHANNEL_B					1

#define 	clk_1						1
#define 	clk_8						2
#define 	clk_64						3
#define 	clk_256						4
#define 	clk_1024					5
#define 	EXTclk_Falling_Edge			6
#define 	EXTclk_Rising_Edge			7


/**  Initialize the Timer 1**/
void TIMER1_init(void);

/**  Select the mode and type of output
 *  Argument is about timer mode NORMAL ,PHASE_CORRECT_PWM,CTC,FAST_PWM,and another 10 modes
 * All the data can be found in TIMER1.h
 * **/
void TIMER1_Configure_Mode(u8 TMR1_Mode);

/*This function to select the mode of oUTput and channel
 * First Argument enter the mode NORMAL_PORT , TOGGLE_OC , CLEAR_OC
 * SET_OC,PWM_INVERTED,PWM_NON_INVERTED
 * Second Enter the channel  CHANNEL_A ,CHANNEL_B
 *
 * */
void TIMER1_Configure_Output_Mode( u8 OUT_mode , u8 Channel);

/**  Select the clock source
 * clk_1, clk_8, clk_64, clk_256, clk_1024, EXTclk_Falling_Edge, EXTclk_Rising_Edge
 * All the data can be found in TIMER1.h
 * **/
void TIMER1_Configure_CLK(u8 CLK_Mode );

/*To load TCNT1 value*/
void TIMER1_set_timer_value(u16 value);

/*To load OCR1A value*/
void TIMER1_set_compare_A_value(u16 value);

/*To load OCR1A value*/
void TIMER1_set_compare_B_value(u16 value);

/*Enable Interrupt for timer overflow*/
void TIMER1_Overflow_Enable_ISR(void);

/*Disable Interrupt for timer overflow*/
void TIMER1_Overflow_Disable_ISR(void);

/*Enable Interrupt for timer compare A*/
void TIMER1_Compare_A_Enable_ISR(void);

/*Disable Interrupt for timer compare A*/
void TIMER1_Compare_A_Disable_ISR(void);

/*Enable Interrupt for timer compare B*/
void TIMER1_Compare_B_Enable_ISR(void);

/*Disable Interrupt for timer compare B*/
void TIMER1_Compare_B_Disable_ISR(void);

/*Enable Interrupt for timer compare Input capture*/
void TIMER1_Input_Capture_Enable_ISR(void);

/*Disable Interrupt for timer compare Input capture*/
void TIMER1_Input_Capture_Disable_ISR(void);

/*Get the status of flag overflow*/
u8 TIMER1_get_overflow_flag(void);

/*Get the status of outcompare match status*/
u8 TIMER1_get_outcompare_A_flag(void);

/*Get the status of outcompare match status*/
u8 TIMER1_get_Input_Capture_flag(void);

/*Clear the status of flag overflow*/
void TIMER1_clear_overflow_flag(void);

/*Clear the status of outcompare match status*/
void TIMER1_clear_outcompare_A_flag(void);

/*Clear the status of outcompare match status*/
void TIMER1_clear_outcompare_B_flag(void);

/*Clear the status of outcompare match status*/
void TIMER1_clear_Input_Capture_flag(void);

#endif /* TIMER1_H_ */
