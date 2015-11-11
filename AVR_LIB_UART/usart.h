/*
 * USART.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Mohamed
 */

#ifndef USART_H_
#define USART_H_
#include "common.h"
#include "USART_CFG.h"

#define 	ASYNCHRONOUS	0
#define 	SYNCHRONOUS		1

#define 	EVEN			0
#define 	ODD				1
#define 	DISABLED		2

#define 	STOP_1			1
#define 	STOP_2			2


#if U2X_MODE!=9
#define 	UBRR_VALUE 		(((F_CLK / (USART_BAUDRATE * 16UL))) - 1)
#endif

#if U2X_MODE==9
#define 	UBRR_VALUE 		(((F_CLK / (USART_BAUDRATE * 8UL))) - 1)
#endif

/*Init the module of the USART*/
void USART_init (void);

/*Enable Transmitting*/
void USART_Enable_Transmitting (void);

/*Disable Transmitting*/
void USART_Disable_Transmitting (void);

/*Enable Receiving*/
void USART_Enable_Receiving (void);

/*Disable Receiving*/
void USART_Disable_Receiving (void);

/*Enable Transmitting ISR*/
void USART_Enable_Transmit_Complete_ISR (void);

/*Disable Transmitting ISR*/
void USART_Disable_Transmit_Complete_ISR (void);

/*Enable Receiving ISR*/
void USART_Enable_Receive_Complete_ISR (void);

/*Disable Receiving ISR*/
void USART_Disable_Receive_Complete_ISR (void);

/*Function to transmit a char*/
void USART_Transmit_data( u8 data );


/*Receiving data*/
u8 USART_Receiving_data (void);

#endif /* USART_H_ */
