/*
 * ADC.c
 *
 *  Created on: Nov 9, 2015
 *      Author: Mohamed
 */
#include "ADC.h"

/**  Init ADC Driver**/
void ADC_init(void)
{
	CLEAR_REG(ADMUX);
	CLEAR_REG(ADCSRA);
	CLEAR_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
}

/**  This function is used to select the refernce voltage for ADC**/
void ADC_Configure_Reference(u8 Reference_Mode)
{
	switch (Reference_Mode)
	{
		case AREF_VOLTAGE:
			CLEAR_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;

		case AVCC_VOLTAGE:
			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;

		case INTERNAL_VOLTAGE:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
		default:break;
	}

}

/**  This function is used to select the the cahnnel voltage for ADC**/
void ADC_Channel_Selection(u8 Channel_Number)
{
	ASSIGN_REG(ADMUX,((GET_NIBBLE_HH(ADMUX))|(GET_NIBBLE_LL(Channel_Number))));
}


/**  Select the Prescalar
 * 2,4,8,16,32,64,128
 * All the data can be found in ADC.h
 * **/
void ADC_Configure_PRESCALAR(u8 Prescalar )
{
	switch (Prescalar)
	{
	case 2:
		SET_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;

	case 4:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;

	case 8:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;

	case 16:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;

	case 32:
		SET_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;

	case 64:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;

	case 128:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;

		default:break;
	}

}

/**  Enable ADC **/
void ADC_Enable(void)
{
	SET_BIT(ADCSRA,ADEN);
}

/**  Disable ADC **/
void ADC_Disable(void)
{
	CLEAR_BIT(ADCSRA,ADEN);
}

/**To start the first conversion**/
void ADC_start (void)
{
	SET_BIT(ADCSRA,ADSC);
}

/*Get the status of flag ADC*/
u8 ADC_get_flag(void)
{
	return(GET_BIT(ADCSRA,ADIF));
}

/*Enable ADC ISR*/
void ADC_Enable_ISR(void)
{
	SET_BIT(ADCSRA ,ADIE);
}

/*Disable ADC ISR*/
void ADC_Disable_ISR(void)
{
	CLEAR_BIT(ADCSRA ,ADIE);
}

/*Enable ADATE(ADC Auto Trigger Source) mode*/
void ADC_Enable_ADATE(void)
{
	SET_BIT(ADCSRA ,ADATE);
}

/*Disable ADATE(ADC Auto Trigger Source)*/
void ADC_Disable_ADATE(void)
{
	CLEAR_BIT(ADCSRA ,ADATE);
}


/**Select the mode of ADATE(ADC Auto Trigger Source)
 * FreeRunningMode, Analog_Comparator,	ExternalInterruptRequest0,
 * Timer_Counter0_CompareMatch ,Timer_Counter0_Overflow , Timer_Counter1_CompareMatchB
 * Timer_Counter1_Overflow , Timer_Counter1_CaptureEvent
 * All the data can be found in ADC.h
 * **/
void ADC_Configure_ADATE (u8 Adate_Mode)
{
	switch (Adate_Mode)
	{

	case FreeRunningMode:
		CLEAR_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;

	case Analog_Comparator:
		SET_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;

	case ExternalInterruptRequest0:
		CLEAR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;

	case Timer_Counter0_CompareMatch:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLEAR_BIT(SFIOR,ADTS2);
		break;

	case Timer_Counter0_Overflow	:
		CLEAR_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;

	case Timer_Counter1_CompareMatchB:
		SET_BIT(SFIOR,ADTS0);
		CLEAR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);

		break;

	case Timer_Counter1_Overflow:
		CLEAR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;

	case Timer_Counter1_CaptureEvent:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;

		default:break;
	}

}


/**To read from ADC channel**/
u8 ADC_read_8bits (u8 Channel_Number )
{
	ADC_Channel_Selection(Channel_Number);
	ADC_start();
#if ADC_INTERRUPT_ENABLE==0
	while (ADC_get_flag());
#endif
	SET_BIT(ADMUX,ADLAR);
	return ADCH;
}

/**To read from ADC channel**/
u16 ADC_read_16bits (u8 Channel_Number )
{

	ADC_Channel_Selection(Channel_Number);
	ADC_start();

#if ADC_INTERRUPT_ENABLE==0
	while (ADC_get_flag());
#endif

	return ADC;
}

