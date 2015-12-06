/*
 * USART.c
 *
 *  Created on: Nov 11, 2015
 *      Author: Mohamed
 */

#include "common.h"
#include "USART_Private.h"
u8 data;
/*Init the module of the USART*/
void USART_init (void)
{
	/*Clear all the data in registers*/
	UCSRA=FUN_HELPER(0,0,1,0,0,0,0,0);
	CLEAR_REG(UCSRB);
	CLEAR_REG(UCSRC);

	/*set the value of UBRR according the frequency of crystal*/
	UBRRH = (u8)(UBRR_VALUE>>8);
	UBRRL = (u8)(UBRR_VALUE);

	SET_BIT(UCSRC,URSEL);

	/*Set the mode of USART*/
	USART_Configure_data(NUMBER_OF_BITS);
	USART_Configure_mode(USART_MODE);
	USART_Configure_stop_mode(STOP_BITS);
	USART_Configure_parity_mode(PARITY);
	/*Configuring U2x mode*/
#if U2X_MODE==1
	SET_BIT(UCSRA,U2X);
#endif
	/*Enable transmitting and receiving data*/
	USART_Enable_Transmitting();
	USART_Enable_Receiving();
}

/*Select the packet of data
 * 5,6,7,8,9
 * */
static void USART_Configure_data (u8 Number_of_bits)
{
	switch (Number_of_bits)
	{

	case 5:
		SET_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;

	case 6:
		SET_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;

	case 7:
		CLEAR_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;

	case 8:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;

	case 9:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRC,UCSZ2);
		break;

	default:break;
	}
}

/*Select USART Mode
 * ASYNCHRONOUS or SYNCHRONOUS
 * */
static void USART_Configure_mode (u8 Mode)
{
	if(Mode==ASYNCHRONOUS)
		CLEAR_BIT(UCSRC,UMSEL);
	else
	SET_BIT(UCSRC,UMSEL);
}

/*Select Stop_Mode
 * 1 or 2
 * */
static void USART_Configure_stop_mode (u8 Stop_Mode)
{
	if(Stop_Mode==1)
		CLEAR_BIT(UCSRC,USBS);
	else
		SET_BIT(UCSRC,USBS);
}

/*Select parity_mode
 * DISABLED,EVEN,ODD
 * */
static void USART_Configure_parity_mode (u8 Parity_Mode)
{
	switch (Parity_Mode)
	{
	case DISABLED:
		CLEAR_BIT(UCSRC,UPM0);
		CLEAR_BIT(UCSRC,UPM1);
		break;

	case EVEN:
		CLEAR_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;

	case ODD:
		SET_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;

	default:break;
	}
}


/*Enable Transmitting*/
void USART_Enable_Transmitting (void)
{
	SET_BIT(UCSRB , TXEN);
}

/*Disable Transmitting*/
void USART_Disable_Transmitting (void)
{
	CLEAR_BIT(UCSRB , TXEN);
}

/*Enable Receiving*/
void USART_Enable_Receiving (void)
{
	SET_BIT(UCSRB , RXEN);
}

/*Disable Receiving*/
void USART_Disable_Receiving (void)
{
	CLEAR_BIT(UCSRB , RXEN);
}

/*Enable Transmitting ISR*/
void USART_Enable_Transmit_Complete_ISR (void)
{
	SET_BIT(UCSRB , TXCIE);
}

/*Disable Transmitting ISR*/
void USART_Disable_Transmit_Complete_ISR (void)
{
	CLEAR_BIT(UCSRB , TXCIE);
}

/*Enable Receiving ISR*/
void USART_Enable_Receive_Complete_ISR (void)
{
	SET_BIT(UCSRB , RXCIE);
}

/*Disable Receiving ISR*/
void USART_Disable_Receive_Complete_ISR (void)
{
	CLEAR_BIT(UCSRB , RXCIE);
}

/*Transmitting data*/
/*Function to transmit a char*/
void USART_Transmit_data( u8 data )
{
	/* Wait for empty transmit buffer */
	while((GET_BIT(UCSRA ,UDRE)) == 0);
	/* Put data into buffer, sends the data */
	UDR = data;
}


/*Receiving data*/
u8 USART_Receiving_data (void)
{
	//u8 data;
	/* Wait for data to be received */
	while((GET_BIT(UCSRA ,RXC)) == 0);

	/* Get and return received data from buffer */
	data=UDR;
	return data;
}

u8 *USART_Receiving_string (void)
{
	u8 counter=0;
	u8 *arr = calloc(3, sizeof(u8));

	do
	{
		data=USART_Receiving_data();
		arr[counter++]=data;
	} while (data!=13 && counter!=4);
	arr[counter]='\n';
	return(arr);
}

s16 USART_arr_to_int (u8 *input_arr)
{
	s16 number;
	number=atoi((const char *)input_arr);
	free(input_arr);
	return(number);
}
