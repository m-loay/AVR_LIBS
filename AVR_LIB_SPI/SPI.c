/*
 * SPI.c
 *
 *  Created on: Nov 11, 2015
 *      Author: Mohamed
 */

#include"SPI.h"

/*SPI Init*/
void SPI_init (void)
{
	CLEAR_REG(SPCR);
	CLEAR_BIT(SPCR,SPIF);
	CLEAR_BIT(SPCR,WCOL);
	CLEAR_BIT(SPCR,SPI2X);
	/* Set MOSI and SCK output, all others input */
#if SPI_Master_Mode_Enable==1
	DIO_set_pin_direction(MOSI,OUTPUT);
	DIO_set_pin_direction(MISO,INPUT);
	DIO_set_pin_direction(SCK,OUTPUT);
	DIO_set_pin_direction(SS,OUTPUT);
#endif

#if SPI_Slave_mode_Enable==1
	DIO_set_pin_direction(MOSI,INPUT);
	DIO_set_pin_direction(MISO,OUTPUT);
	DIO_set_pin_direction(SCK,INPUT);
	DIO_set_pin_direction(SS,INPUT);
#endif

	SPI_Configure_Prescalar(SPI_CLK);
	SPI_Configure_Mode(SPI_MODE_OPT);
	SPI_Enable();

}


/*Enable SPI*/
void SPI_Enable (void)
{
	SET_BIT(SPCR ,SPE);
}

/*Disable SPI*/
void SPI_Disable (void)
{
	CLEAR_BIT(SPCR ,SPE);
}

/*Enable SPI ISR*/
void SPI_Enable_ISR (void)
{
	SET_BIT(SPCR , SPIE);
}

/*Disable Disable ISR*/
void SPI_Disable_ISR(void)
{
	CLEAR_BIT(SPCR , SPIE);
}

/*Select mode of operation*/
 void SPI_Configure_Mode (u8 Mode)
{
	if (Mode==SPI_Master_Mode_Enable)
		SET_BIT(SPCR,MSTR);
	else
		CLEAR_BIT(SPCR,MSTR);
}

/*Select the presca;a 2,4,8,16,32,64,128*/
void SPI_Configure_Prescalar (u8 Prescalar)
{
	switch (Prescalar)
	{
		case 2:
			CLEAR_BIT(SPCR,SPR0);
			CLEAR_BIT(SPCR,SPR1);
			SET_BIT(SPSR,SPI2X);
			break;

		case 4:
			CLEAR_BIT(SPCR,SPR0);
			CLEAR_BIT(SPCR,SPR1);
			CLEAR_BIT(SPSR,SPI2X);
			break;

		case 8:
			SET_BIT(SPCR,SPR0);
			CLEAR_BIT(SPCR,SPR1);
			SET_BIT(SPSR,SPI2X);
			break;

		case 16:
			SET_BIT(SPCR,SPR0);
			CLEAR_BIT(SPCR,SPR1);
			CLEAR_BIT(SPSR,SPI2X);
			break;

		case 32:
			CLEAR_BIT(SPCR,SPR0);
			SET_BIT(SPCR,SPR1);
			SET_BIT(SPSR,SPI2X);
			break;

		case 64:
			CLEAR_BIT(SPCR,SPR0);
			SET_BIT(SPCR,SPR1);
			CLEAR_BIT(SPSR,SPI2X);
			break;

		case 128:
			SET_BIT(SPCR,SPR0);
			SET_BIT(SPCR,SPR1);
			CLEAR_BIT(SPSR,SPI2X);
			break;

		default:break;
	}
}

/*Send byte*/
void SPI_send_byte (u8 data)
{
	DIO_set_pin(SS,LOW);
	SPDR=data;
	while((GET_BIT(SPSR,SPIF))==0);
	DIO_set_pin(SS,HIGH);
}

/*Send a string*/
void SPI_send_string (u8 *string)
{
	unsigned char i=0;
	while (string[i] !=0)
	{
		SPI_send_byte(string[i]);
		i++;
	}
}

/*Receive byte*/
u8 SPI_Receive (void)
{
	while((GET_BIT(SPSR,SPIF))==0);
	return SPDR;
}
