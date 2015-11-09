/*
 * TIMER0.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Mohamed
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include"common.h"
#include "TIMER0_CFG.h"

#define		NORMAL					0
#define		PHASE_CORRECT_PWM		1
#define		CTC						2
#define		FAST_PWM				3

#define 	NORMAL_PORT				0
#define     TOGGLE_OC0				1
#define     CLEAR_OC0				2
#define     SET_OC0					3

#define 	clk_1					1
#define 	clk_8					2
#define 	clk_64					3
#define 	clk_256					4
#define 	clk_1024				5
#define 	EXTclk_Falling_Edge		6
#define 	EXTclk_Rising_Edge		7

/**  Initialize the Timer 0**/
void TIMER0_init(void);

/**  Select the mode and type of output
 * First Argument is about timer mode NORMAL ,PHASE_CORRECT_PWM,CTC,FAST_PWM
 * Second Argument os about timer output NORMAL_PORT,TOGGLE_OC0,CLEAR_OC0,SET_OC0
 * All the data can be found in TIMER0.h
 * **/
void TIMER0_Configure_Mode(u8 TMR0_Mode , u8 OUT_mode );
/**  Select the clock source
 * clk_1, clk_8, clk_64, clk_256, clk_1024, EXTclk_Falling_Edge, EXTclk_Rising_Edge
 * All the data can be found in TIMER0.h
 * **/
void TIMER0_Configure_CLK(u8 CLK_Mode );

/*To load TCNT0 value*/
void TIMER0_set_timer_value(u8 value);

/*To load OCR0 value*/
void TIMER0_out_compare_value(u8 value);

/*Enable Interrupt for timer overflow*/
void TIMER0_Overflow_Enable_ISR(void);

/*Disable Interrupt for timer overflow*/
void TIMER0_Overflow_Disable_ISR(void);

/*Enable Interrupt for PWM*/
void TIMER0_Outcmpare_Enable_ISR(void);

/*Disable Interrupt for PWM*/
void TIMER0_Outcmpare_Disable_ISR(void);

/*Get the status of flag overflow*/
u8 TIMER0_get_overflow_flag(void);

/*Get the status of outcompare match status*/
u8 TIMER0_get_outcompare_flag(void);


#endif /* TIMER0_H_ */
