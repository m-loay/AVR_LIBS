/*
 * main.c
 *
 *  Created on: Dec 25, 2013
 *      Author: mody
 */

#include<avr/io.h>
#include<util/delay.h>
#include"DIO.h"

void atmega_Init(void);

int main(void)
{
	atmega_Init();
	while (1)
	{
		if (READ(B,0)==0)
		{
			SET(A,0);
		}
		else
			CLR(A,0);
	}
	return (0);
}

void atmega_Init(void)
{
	IN(B,0);
	SET(B,0);
	OUT(A,0);
}
