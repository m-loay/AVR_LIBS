/*
 * SPI_Pivate.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Mohamed
 */

#ifndef SPI_PIVATE_H_
#define SPI_PIVATE_H_
#include "common.h"

/*Select mode of operation*/
static void SPI_Configure_Mode (u8 Mode);

/*Select the presca;a 2,4,8,16,32,64,128*/
static void SPI_Configure_Prescalar (u8 Prescalar);

#endif /* SPI_PIVATE_H_ */
