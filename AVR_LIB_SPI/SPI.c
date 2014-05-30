/*
 * SPI_Master.c
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */
#include<avr/io.h>
#include<util/delay.h>
#include"SPI.h"


#if SPI_Master_Mode_Enable==1

	void SPI_MasterInit(void)
	{
		/* Set MOSI and SCK output, all others input */
		DDR_SPI = (1<<MOSI)|(1<<SCK)|(1<<SS);
		/*set the the SS as an output*/
		PORT_SPI|=(1<<SS);
		/* Enable SPI, Master, set clock rate fck/16 */
		SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	}

	void SPI_MasterSend(char data)
	{
		/* select slave */
		PORT_SPI &= ~(1<<SS);
		/* send data */
		SPDR=data;
		/* wait for transmition complete*/
		while (!(SPSR &(1<<SPIF)));
		/* SS to high */
		PORT_SPI|= (1<<SS);
	}

	void SPI_MasterSend_String (unsigned char *str)
	{
		unsigned char i=0;
		while (str[i] !=0)
		{
			_delay_ms(200);
			SPI_MasterSend(str[i]);
			i++;
		}
	}

#endif

#if SPI_Slave_mode_Enable==1

	void SPI_SlaveInit(void)
	{
		/* set MISO as output */
		DDR_SPI |= (1<<SS);
		/*enable SPI and enable SPI interrupt*/
		SPCR = (1<<SPE)|(1<<SPIE);
	}

#endif
