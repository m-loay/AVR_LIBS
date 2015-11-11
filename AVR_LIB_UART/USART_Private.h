/*
 * USART_Private.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Mohamed
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#include "USART_Private.h"

/*Select the packet of data
 * 5,6,7,8,9
 * */
static void USART_Configure_data (u8 Number_of_bits);

/*Select USART Mode
 * ASYNCHRONOUS or SYNCHRONOUS
 * */
static void USART_Configure_mode (u8 Mode);

/*Select Stop_Mode
 * 1 or 2
 * */
static void USART_Configure_stop_mode (u8 Stop_Mode);

/*Select parity_mode
 * DISABLED,EVEN,ODD
 * */
static void USART_Configure_parity_mode (u8 Parity_Mode);




#endif /* USART_PRIVATE_H_ */
