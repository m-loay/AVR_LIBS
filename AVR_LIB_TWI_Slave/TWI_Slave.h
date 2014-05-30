/*
 * TWI_Slave.h
 *
 *  Created on: Jan 20, 2014
 *      Author: mody
 */

#ifndef TWI_SLAVE_H_
#define TWI_SLAVE_H_
#include"TWI_Slave_CFG.h"

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
#define	SRX_GCALL_ACK	        0x90		//Previously addressed with General
                                            //Call.Data byte has been received
											//and ACK returned
#define	SRX_GCALL_NACK	        0x98		//Previously addressed with General
                                            //Call. Data byte has been received
                                            //and NACK returned
#define	SRX_STOP	            0xA0		//A STOP condition or repeated START
                                            //condition has been received while
                                            //still addressed as a slave
/*Function Prototypes*/
void TWI_Slave_Init (void);


#endif /* TWI_SLAVE_H_ */
