/*
 * TWI_Master.h
 *
 *  Created on: Jan 20, 2014
 *      Author: mody
 */

#ifndef TWI_MASTER_H_
#define TWI_MASTER_H_
#include"TWI_Master_CFG.h"
/*Commonly Used Bits*/
#define W 				0					//Data transfer direction WRITE
#define R 				1					//Data transfer direction READ
#define address(x,RW) (x##RW)				//Write down the address and select the mode
#define SUCCESS 		0xFF

/*TWI Stautus register definitions*/
/*General Master staus codes*/
#define START		0x08					//START has been transmitted
#define	REP_START	0x10					//Repeated START has been
											//transmitted
/*Master Transmitter staus codes*/

#define	MTX_ADR_ACK		0x18				//SLA+W has been tramsmitted
											//and ACK received
#define	MTX_ADR_NACK	0x20				//SLA+W has been tramsmitted
											//and NACK received
#define	MTX_DATA_ACK	0x28				//Data byte has been tramsmitted
											//and ACK received
#define	MTX_DATA_NACK	0x30				//Data byte has been tramsmitted
											//and NACK received
#define	MTX_ARB_LOST	0x38				//Arbitration lost in SLA+W or
											//data bytes
/*Master Receiver staus codes*/
#define	MRX_ARB_LOST	0x38				//Arbitration lost in SLA+R or
											//NACK bit
#define	MRX_ADR_ACK		0x40				//SLA+R has been tramsmitted
											//and ACK received
#define	MRX_ADR_NACK	0x48				//SLA+R has been tramsmitted
											//and NACK received
#define	MRX_DATA_ACK	0x50				//Data byte has been received
											//and ACK tramsmitted
#define	MRX_DATA_NACK	0x58				//Data byte has been received
											//and NACK tramsmitted

/*Global variable to save the Contents of TWDR*/
unsigned char data_recevied;
/*Function prototypes*/
void TWI_Init (void);
void Wait_TWI_int(void);
unsigned char Send_start (void);
void Send_stop(void);
unsigned char Send_Address (unsigned char adr);
unsigned char Send_byte (unsigned char data);
unsigned char Get_byte (unsigned char last_byte);


#endif /* TWI_MASTER_H_ */
