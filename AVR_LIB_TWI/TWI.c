/*
 * TWI.c
 *
 *  Created on: Nov 14, 2015
 *      Author: Mohamed
 */
#include "TWI.h"

#if MASTER==1
/**  Initialization of MASTER TWI**/
void TWI_MASTER_init (void)
{
	/*Clear the registers*/
	CLEAR_REG(TWBR);
	CLEAR_REG(TWCR);
	CLEAR_REG(TWSR);
	CLEAR_REG(TWDR);

	/*Set the prescalar*/
	TWI_MASTER_Configure_Prescalar(PRESCALAR);
	/*Set the frequency */
	TWI_MASTER_Configure_Frequency(BIT_RATE);
	/*Enable TWI Module*/
	TWI_Enable();

}

/**  Configure of MASTER TWI Prescalar
 * 1 ,4,16,64
 * **/
void TWI_MASTER_Configure_Prescalar (u8 Prescalar)
{
	switch (Prescalar)
	{
	case 1:
		CLEAR_BIT(TWSR,TWPS0);
		CLEAR_BIT(TWSR,TWPS1);
		break;

	case 4:
		SET_BIT(TWSR,TWPS0);
		CLEAR_BIT(TWSR,TWPS1);
		break;

	case 16:
		CLEAR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break;

	case 64:
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break;

	default:break;
	}

}

/**  Configure of MASTER TWI Frequency
 * SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
 * SCL freq should be less than 400 KHZ
 * Select a suitable value for TWBR then load to the function
 * **/
void TWI_MASTER_Configure_Frequency(u8 Bit_rate)
{
	ASSIGN_REG(TWBR,Bit_rate);
}

/*Send a start condition*/
u8 TWI_MASTER_Send_START (void)
{
	TWI_Clear_Flag();
	TWI_START_Condition();
	TWI_Enable();

	TWI_Wait_Flag();

	if((TWSR!=START)|| (TWSR!=REP_START))
		return (TWSR);
	return(SUCCESS);
}

/*Send an ADDRESS*/
u8 TWI_MASTER_Send_Address(u8 SLA_RW)
{
	/*Put the Address of the Salve in the TWDR*/
	TWDR=SLA_RW;
	TWI_Clear_Flag();
	TWI_Enable();

	/*wait untin the TWINT hardware flag to be set*/
	TWI_Wait_Flag();

	/*If NACK received return  TWSR*/
	if((TWSR != MTX_ADR_ACK)&&(TWSR != MRX_ADR_ACK))
		return TWSR;

	return (SUCCESS);
}

/*Send an byte*/
u8 TWI_MASTER_Send_Byte (u8 data)
{
	TWI_Wait_Flag();
	TWDR=data;
	TWI_Clear_Flag();
	TWI_Enable();

	TWI_Wait_Flag();
	if(TWSR != MTX_DATA_ACK)
		return TWSR;
	return SUCCESS;
}

/*GET an byte*/
u8 TWI_MASTER_Get_Byte (u8 last_Byte,u8 *ptr_data)
{
	TWI_Wait_Flag();

	if(last_Byte==0)
	{
		TWI_Clear_Flag();
		TWI_Enable();
		SET_BIT(TWCR,TWEA);
	}
	else
	{
		TWI_Clear_Flag();
		TWI_Enable();
	}

	*ptr_data=TWDR;

	TWI_Wait_Flag();
 	if(((TWSR == MRX_DATA_NACK)&&(last_Byte == 0))||(TWSR == MRX_DATA_ACK))
		return SUCCESS;
	return TWSR;
}

/*Send a stop condition*/
void TWI_MASTER_Send_Stop(void)
{
	TWI_Clear_Flag();
	TWI_Enable();
	TWI_STOP_Condition();
}

#endif

#if SLAVE==1

/**  Initialization of MASTER TWI**/
void TWI_Slave_init (void)
{
	/*Clear the registers*/
	CLEAR_REG(TWBR);
	CLEAR_REG(TWCR);
	CLEAR_REG(TWSR);
	CLEAR_REG(TWDR);

	/*Set the slave address*/
	ASSIGN_REG(TWAR,SLAVE_ADD);
	TWI_Clear_Flag();
	TWI_Enable();
	SET_BIT(TWCR,TWEA);
}

/**  Slave Send Byte**/
u8 TWI_SLAVE_Send_Byte (u8 data)
{
	TWI_Wait_Flag();
	TWDR=data;
	TWI_Clear_Flag();
	TWI_Enable();

	TWI_Wait_Flag();
	if(TWSR != STX_DATA_NACK)
		return TWSR;
	return SUCCESS;
}

/**  Slave GET Byte**/
u8 TWI_Slave_Get_Byte(u8 last_Byte,u8 *ptr_data)
{

	TWI_Wait_Flag();

	if(last_Byte==0)
	{
		TWI_Clear_Flag();
		TWI_Enable();
		SET_BIT(TWCR,TWEA);
	}
	else
	{
		TWI_Clear_Flag();
		TWI_Enable();
	}

	TWI_Wait_Flag();
	*ptr_data= TWDR;

	if(TWSR != SRX_DATA_NACK)
		return TWSR;
	return SUCCESS;


}

#endif

/*Enable TWI_module*/
void TWI_Enable (void)
{
	SET_BIT(TWCR,TWEN);
}

/*Diable TWI Module*/
void TWI_Diable (void)
{
	CLEAR_BIT(TWCR,TWEN);
}

/*Enable TWI_module*/
void TWI_Enable_ISR (void)
{
	SET_BIT(TWCR,TWIE);
}

/*Diable TWI Module*/
void TWI_Diable_ISR (void)
{
	CLEAR_BIT(TWCR,TWIE);
}
/*Wait for the flag*/
void TWI_Wait_Flag (void)
{
	while((GET_BIT(TWCR,TWINT))==0);
}

/*Clear the flag*/
void TWI_Clear_Flag (void)
{
	SET_BIT(TWCR,TWINT);
}

/*START_Condition*/
void TWI_START_Condition(void)
{
	SET_BIT(TWCR,TWSTA);
}

/*STOP_Condition*/
void TWI_STOP_Condition(void)
{
	SET_BIT(TWCR,TWSTO);
}
