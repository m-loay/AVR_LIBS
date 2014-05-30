/*
 * SPI_Master.h
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */

#ifndef SPI_H_
#define SPI_H_

#include"SPI_CFG.h"

#if SPI_Master_Mode_Enable==1
void SPI_MasterInit(void);
void SPI_MasterSend(char data);
void SPI_MasterSend_String (unsigned char *str);
#endif

#if SPI_Slave_mode_Enable==1
void SPI_SlaveInit(void);
#endif

#endif /* SPI_H_ */
