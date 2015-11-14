/*
 * TWI.h
 *
 *  Created on: Nov 14, 2015
 *      Author: Mohamed
 */

#ifndef TWI_H_
#define TWI_H_

#include "common.h"
#include "TWI_CFG.h"
#define W 				0					//Data transfer direction WRITE
#define R 				1					//Data transfer direction READ
#define address(x,RW) (x##RW)				//Write down the address and select the mode
#define SUCCESS 		0xFF
/*TWI Stautus register definitions*/
/*General Master staus codes*/
#define START		0x08					//START has been transmitted
#define	REP_START	0x10					//Repeated START has been
											//transmitted

#if MASTER==1
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

/**  Initialization of MASTER TWI**/
void TWI_MASTER_init (void);

/**  Configure of MASTER TWI Prescalar
 * 1 ,4,16,64
 * **/
void TWI_MASTER_Configure_Prescalar (u8 Prescalar);

/**  Configure of MASTER TWI Frequency
 * SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
 * SCL freq should be less than 400 KHZ
 * Select a suitable value for TWBR then load to the function
 * **/
void TWI_MASTER_Configure_Frequency(u8 Bit_rate);

/*Send a start condition*/
u8 TWI_MASTER_Send_START (void);

/*Send an ADDRESS*/
u8 TWI_MASTER_Send_Address(u8 SLA_RW);

/*Send an byte*/
u8 TWI_MASTER_Send_Byte (u8 data);

/*GET an byte*/
u8 TWI_MASTER_Get_Byte (u8 last_Byte,u8 *ptr_data);

/*Send a stop condition*/
void TWI_MASTER_Send_Stop(void);

#endif

#if SLAVE==1
/*Slave Transmitter staus codes*/
#define	STX_ADR_ACK		        0xA8		//Own SLA+R has been received
											//and ACK returned
#define	ARB_LOST_STX_ADR_ACK    0xB0		//Arbitration lost in SLA+R/W as
                                            //a Master. Own SLA+W has been
                                            //received and ACK returned
#define	STX_DATA_ACK	        0xB8		//Data byte has been tramsmitted
											//and ACK received
#define	STX_DATA_NACK	        0xC0		//Data byte has been tramsmitted
											//and NACK received
#define	STX_LAST_DATA 	        0xC8		//Last byte un I2DR has been
                                            //transmitted(TWEA = '0') ACK has
                                            //been received
/*Slave Receiver staus codes*/
#define	SRX_ADR_ACK		        0x60		//SLA+R has been received
											//and ACK returned
#define	ARB_LOST_SRX_ADR_ACK	0x68		//Arbitration lost in SLA+R/W as
                                            //a Master. Own SLA+R has been
                                            //received and ACK returned
#define	SRX_GCALL_ACK	        0x70		//Generall call has been received
											//and ACK returned
#define	ARB_LOST_SRX_GCALL_ACK	0x78		//Arbitration lost in SLA+R/W as
                                            //a Master. General Call has been
                                            //received and ACK returned
#define	SRX_DATA_ACK	        0x80		//Previously addressed with own
                                            //SLA+W.Data byte has been received
											//and ACK returned
#define	SRX_DATA_NACK	        0x88		//Previously addressed with own
                                            //SLA+WData byte has been received
                                            //and NACK returned
//#define	SRX_GCALL_ACK	        0x90		//Previously addressed with General
                                            //Call.Data byte has been received
											//and ACK returned
#define	SRX_GCALL_NACK	        0x98		//Previously addressed with General
                                            //Call. Data byte has been received
                                            //and NACK returned
#define	SRX_STOP	            0xA0		//A STOP condition or repeated START
                                            //condition has been received while
                                            //still addressed as a slave

/**  Initialization of MASTER TWI**/
void TWI_Slave_init (void);

/**  Slave Send Byte**/
u8 TWI_SLAVE_Send_Byte (u8 data);

/**  Slave GET Byte**/
u8 TWI_Slave_Get_Byte(u8 last_Byte,u8 *ptr_data);



#endif
/*Enable TWI_module*/
void TWI_Enable (void);

/*Diable TWI Module*/
void TWI_Diable (void);

/*Enable TWI_module*/
void TWI_Enable_ISR (void);

/*Diable TWI Module*/
void TWI_Diable_ISR (void);

/*Wait for the flag*/
void TWI_Wait_Flag (void);

/*Clear the flag*/
void TWI_Clear_Flag (void);

/*Start*/
void TWI_START_Condition(void);

/*STOP_Condition*/
void TWI_STOP_Condition(void);


#endif /* TWI_H_ */
