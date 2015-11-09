/*
 * TIMER0_CFG.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Mohamed
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#define OVERFLOW_MODE				0
#define OUTPUT_COMPARE_MATCH_MODE	1

#if OVERFLOW_MODE == 1
#define TIMER0_VALUE				186
#define OCR0_VALUE					0x00
#define TIMER0_FLAG					T0V0
#endif

#if OUTPUT_COMPARE_MATCH_MODE==	1
#define OCR0_VALUE					69
#define TIMER0_VALUE				0x00
#define TIMER0_FLAG					OCF0
#endif

#define TIMER0_MODE					CTC
#define TIMER0_OUT_MODE				NORMAL
#define TIMER0_CLK					clk_8



#endif /* TIMER0_CFG_H_ */
