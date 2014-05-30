/*
 * TWI_Master_CFG.h
 *
 *  Created on: Jan 20, 2014
 *      Author: mody
 */

#ifndef TWI_MASTER_CFG_H_
#define TWI_MASTER_CFG_H_

/*SCL Frequency=F_CPU/(16+2(TWBR).4^TWPS)*/
#define TWBR_Value 0x01
/*Set the Address of Master (as a slave in Master receiver mode)*/
#define OWN_ADR 		60  				//Own slave address


#endif /* TWI_MASTER_CFG_H_ */
