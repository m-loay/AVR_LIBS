/*
 * SPI_CFG.h
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */

#ifndef SPI_CFG_H_
#define SPI_CFG_H_
/*Select the mode of operation*/
#define SPI_Master_Mode_Enable		1
#define SPI_Slave_mode_Enable		0

/*SPI Master mode paramters*/
#if SPI_Master_Mode_Enable==1

#define DDR_SPI  DDRB
#define PORT_SPI PORTB
#define MOSI     5
#define SCK      7
#define SS	     4

#endif

/*SPI Slave mode paramters*/
#if SPI_Slave_mode_Enable==1

#define DDR_SPI  DDRB
#define PORT_SPI PORTB
#define MISO     6
#define SCK      7
#define SS	     4

#endif


#endif /* SPICFG_H_ */
