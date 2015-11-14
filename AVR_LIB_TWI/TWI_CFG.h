/*
 * TWI_CFG.h

 *
 *  Created on: Nov 14, 2015
 *      Author: Mohamed
 */

#ifndef TWI_CFG_H_
#define TWI_CFG_H_

#define MASTER			1
#define SLAVE			0

#if MASTER==1

#define PRESCALAR     	1
#define BIT_RATE	  	0x47

#endif

#if SLAVE==1
#define SLAVE_ADD		60
#endif



#endif /* TWI_CFG_H_ */
