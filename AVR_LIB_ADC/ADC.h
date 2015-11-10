/*
 * ADC.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Mohamed
 */

#ifndef ADC_H_
#define ADC_H_

#include "common.h"
#include "ADC_CFG.h"

#define 	AREF_VOLTAGE					0
#define 	AVCC_VOLTAGE					1
#define 	INTERNAL_VOLTAGE				2

#define		FreeRunningMode					0
#define		Analog_Comparator				1
#define		ExternalInterruptRequest0		2
#define		Timer_Counter0_CompareMatch		3
#define		Timer_Counter0_Overflow			4
#define		Timer_Counter1_CompareMatchB	5
#define		Timer_Counter1_Overflow			6
#define		Timer_Counter1_CaptureEvent		7

#define		ADC0							0
#define		ADC1							1
#define		ADC2							2
#define		ADC3							3
#define		ADC4							4
#define		ADC5							5
#define		ADC6							6
#define		ADC7							7
#define 	ADC0_ADC0_10					8
#define 	ADC1_ADC0_10					9
#define 	ADC0_ADC0_200					10
#define 	ADC1_ADC0_200					11
#define 	ADC2_ADC2_10					12
#define 	ADC3_ADC2_10					13
#define 	ADC2_ADC2_200					14
#define 	ADC3_ADC2_200					15
#define 	ADC0_ADC1_1						16
#define 	ADC1_ADC1_1						17
#define 	ADC2_ADC1_1						18
#define 	ADC3_ADC1_1						19
#define 	ADC4_ADC1_1						20
#define 	ADC5_ADC1_1						21
#define 	ADC6_ADC1_1						22
#define 	ADC7_ADC1_1						23
#define 	ADC0_ADC2_1						24
#define 	ADC1_ADC2_1						25
#define 	ADC2_ADC2_1						26
#define 	ADC3_ADC2_1						27
#define 	ADC4_ADC2_1						29
#define 	ADC5_ADC2_1						30


/**  Init ADC Driver**/
void ADC_init(void);

/**  This function is used to select the refernce voltage for ADC**/
void ADC_Configure_Reference(u8 Reference_Mode);

/**  This function is used to select the the cahnnel voltage for ADC**/
void ADC_Channel_Selection(u8 Channel_Number);

/**  Select the Prescalar
 * 2,4,8,16,32,64,128
 * All the data can be found in ADC.h
 * **/
void ADC_Configure_PRESCALAR(u8 Prescalar );

/**  Enable ADC **/
void ADC_Enable(void);

/**  Disable ADC **/
void ADC_Disable(void);

/**To start the first conversion**/
void ADC_start (void);

/*Get the status of flag ADC*/
u8 ADC_get_flag(void);

/*Enable ADC ISR*/
void ADC_Enable_ISR(void);

/*Disable ADC ISR*/
void ADC_Disable_ISR(void);

/*Enable ADATE(ADC Auto Trigger Source) mode*/
void ADC_Enable_ADATE(void);

/*Disable ADATE(ADC Auto Trigger Source)*/
void ADC_Disable_ADATE(void);

/**Select the mode of ADATE(ADC Auto Trigger Source)
 * FreeRunningMode, Analog_Comparator,	ExternalInterruptRequest0,
 * Timer_Counter0_CompareMatch ,Timer_Counter0_Overflow , Timer_Counter1_CompareMatchB
 * Timer_Counter1_Overflow , Timer_Counter1_CaptureEvent
 * All the data can be found in ADC.h
 * **/
void ADC_Configure_ADATE (u8 Adate_Mode);

/**To read from ADC channel**/
u8 ADC_read_8bits (u8 Channel_Number );

/**To read from ADC channel**/
u16 ADC_read_16bits (u8 Channel_Number );










#endif /* ADC_H_ */
