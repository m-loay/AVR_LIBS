/*
 * SPI.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Mohamed
 */

#ifndef SPI_H_
#define SPI_H_

#include "common.h"
#include "SPI_CFG.h"

#if SPI_Master_Mode_Enable==1
#define SPI_MODE_OPT	SPI_Master_Mode_Enable
#endif

#if SPI_Slave_mode_Enable==1
#define SPI_MODE_OPT	SPI_Slave_mode_Enable
#endif

#define MOSI     	PIN5
#define MISO     	PIN6
#define SCK      	PIN7
#define SS	     	PIN4

/*SPI Init*/
void SPI_init (void);

/*Enable SPI*/
void SPI_Enable (void);

/*Disable SPI*/
void SPI_Disable (void);

/*Enable SPI ISR*/
void SPI_Enable_ISR (void);

/*Disable Disable ISR*/
void SPI_Disable_ISR(void);

/*Send byte*/
void SPI_send_byte (u8 data);

/*Send a string*/
void SPI_send_string (u8 *string);

/*Receive byte*/
u8 SPI_Receive (void);



#endif /* SPI_H_ */
