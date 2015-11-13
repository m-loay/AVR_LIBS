/*
 * avr_comm.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Mohamed
 */

#ifndef AVR_COMM_H_
#define AVR_COMM_H_

#include "avr_comm_CFG.h"
/*****************I/O registers ****************/

/****************PORTS & PINS*******************/
#if AVR_DIO_MODULE==1
#define PORT0_DIR				(*(volatile u8*) 0x37)//DDRB
#define PORT1_DIR				(*(volatile u8*) 0x34)//DDRC
#define PORT2_DIR				(*(volatile u8*) 0x31)//DDRD
#define PORT3_DIR				(*(volatile u8*) 0x3A)//DDRA

#define PORT0_OUTPUT_VALUE		(*(volatile u8*) 0x38)//PORTB
#define PORT1_OUTPUT_VALUE		(*(volatile u8*) 0x35)//PORTC
#define PORT2_OUTPUT_VALUE		(*(volatile u8*) 0x32)//PORTD
#define PORT3_OUTPUT_VALUE		(*(volatile u8*) 0x3B)//PORTA

#define PORT0_INPUT_VALUE		(*(volatile u8*) 0x36)//PINB
#define PORT1_INPUT_VALUE		(*(volatile u8*) 0x33)//PINC
#define PORT2_INPUT_VALUE		(*(volatile u8*) 0x30)//PIND
#define PORT3_INPUT_VALUE		(*(volatile u8*) 0x39)//PINA

/*PORTB pins B0 to B7*/
#define		PIN0				0
#define		PIN1				1
#define		PIN2				2
#define		PIN3				3
#define		PIN4				4
#define		PIN5				5
#define		PIN6				6
#define		PIN7				7

/*PORTC pins C0 to C7*/
#define		PIN8				8
#define		PIN9				9
#define		PIN10				10
#define		PIN11				11
#define		PIN12				12
#define		PIN13				13
#define		PIN14				14
#define		PIN15				15

/*PORTD pins D0 to D7*/
#define		PIN16				16
#define		PIN17				17
#define		PIN18				18
#define		PIN19				19
#define		PIN20				20
#define		PIN21				21
#define		PIN22				22
#define		PIN23				23

/*PORTA pins A0 to A7*/
#define		PIN24				24
#define		PIN25				25
#define		PIN26				26
#define		PIN27				27
#define		PIN28				28
#define		PIN29				29
#define		PIN30				30
#define		PIN31				31


/*PORTB*/
#define		PORT0				0
/*PORTC*/
#define		PORT1				1
/*PORTD*/
#define		PORT2				2
/*PORTA*/
#define		PORT3				3


/*AVR Status PORT*/
#define		INPUT				0
#define		OUTPUT				1
#define		HIGH_IMPEDENCE 		0
#define 	PULLUP				1
#define		LOW					0
#define		HIGH				1
#endif
/****************External Interrupts*******************/
#if AVR_EXTERNAL_INTERRUPT_MODULE==1
#define		 MCUCR		(*(volatile u8 *)0x55)			//MCU Control Register
#define		 MCUCSR		(*(volatile u8 *)0x54)			//MCU Control and Status Register
#define 	 GICR		(*(volatile u8 *)0x5B)			//General Interrupt Control Register
#define		 GIFR		(*(volatile u8 *)0x5A)			//General Interrupt Flag Register
/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* MCUCSR */
#define JTD     7
#define ISC2    6
/* bit 5 reserved */
#define JTRF    4
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0
/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* GIFR */
#define INTF1   7
#define INTF0   6
#define INTF2   5

/* External Interrupt Request 0 */
#define INT0_vect			_VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
#define INT1_vect			_VECTOR(2)
#define SIG_INTERRUPT1			_VECTOR(2)

/* External Interrupt Request 2 */
#define INT2_vect			_VECTOR(3)
#define SIG_INTERRUPT2			_VECTOR(3)

#endif
/****************TIMER*******************/
#define		TIMSK					(*(volatile u8 *)0x59)
#define		TIFR					(*(volatile u8 *)0x58)
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0


/****************TIMER0*******************/
#if AVR_TIMER0_MODULE==1
#define		TCCR0					(*(volatile u8 *)0x53)
#define		TCNT0					(*(volatile u8 *)0x52)
#define		OCR0					(*(volatile u8 *)0x5C)


/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		_VECTOR(10)
#define SIG_OUTPUT_COMPARE0		_VECTOR(10)

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			_VECTOR(11)
#define SIG_OVERFLOW0			_VECTOR(11)

#endif

/****************TIMER1*******************/
#if AVR_TIMER1_MODULE==1
#define		TCCR1A					(*(volatile u8 *)0x4F)
#define		TCCR1B					(*(volatile u8 *)0x4E)
#define		TCNT1H					(*(volatile u8 *)0x4D)
#define		TCNT1L					(*(volatile u8 *)0x4C)
#define		TCNT1					(*(volatile u16 *)0x4C)
#define		OCR1AH					(*(volatile u8 *)0x4B)
#define		OCR1AL					(*(volatile u8 *)0x4A)
#define		OCR1A					(*(volatile u16 *)0x4A)
#define		OCR1BH					(*(volatile u8 *)0x49)
#define		OCR1BL					(*(volatile u8 *)0x48)
#define		OCR1B					(*(volatile u16 *)0x48)
#define		ICR1H					(*(volatile u8 *)0x47)
#define		ICR1L					(*(volatile u8 *)0x46)
#define		ICR1					(*(volatile u16 *)0x46)

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		_VECTOR(6)
#define SIG_INPUT_CAPTURE1		_VECTOR(6)

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		_VECTOR(7)
#define SIG_OUTPUT_COMPARE1A		_VECTOR(7)

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		_VECTOR(8)
#define SIG_OUTPUT_COMPARE1B		_VECTOR(8)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			_VECTOR(9)
#define SIG_OVERFLOW1			_VECTOR(9)

#endif
/****************TIMER2*******************/
#if AVR_TIMER2_MODULE
#define		TCCR2					(*(volatile u8 *)0x45)
#define		TCNT2					(*(volatile u8 *)0x44)
#define		OCR2					(*(volatile u8 *)0x43)
#define		ASSR					(*(volatile u8 *)0x42)

/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

/* bits 7-4 reserved */
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		_VECTOR(4)
#define SIG_OUTPUT_COMPARE2		_VECTOR(4)

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			_VECTOR(5)
#define SIG_OVERFLOW2			_VECTOR(5)
#endif
/****************SPI*******************/
#if AVR_SPI_MODULE==1
#define		SPCR					(*(volatile u8 *)0x2D)
#define		SPSR					(*(volatile u8 *)0x2E)
#define		SPDR					(*(volatile u8 *)0x2F)

/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0

/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0

/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0

/* Serial Transfer Complete */
#define SPI_STC_vect			_VECTOR(12)
#define SIG_SPI				_VECTOR(12)

#endif
/****************USART*******************/
#if AVR_USART_MODULE==1
#define		UDR					(*(volatile u8 *)0x2C)
#define		UCSRA				(*(volatile u8 *)0x2B)
#define		UCSRB				(*(volatile u8 *)0x2A)
#define		UCSRC				(*(volatile u8 *)0x40)
#define		UBRRH				(*(volatile u8 *)0x40)
#define		UBRRL				(*(volatile u8 *)0x29)

/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0

/* USART, Rx Complete */
#define USART_RXC_vect			_VECTOR(13)
#define SIG_USART_RECV			_VECTOR(13)
#define SIG_UART_RECV			_VECTOR(13)

/* USART Data Register Empty */
#define USART_UDRE_vect			_VECTOR(14)
#define SIG_USART_DATA			_VECTOR(14)
#define SIG_UART_DATA			_VECTOR(14)

/* USART, Tx Complete */
#define USART_TXC_vect			_VECTOR(15)
#define SIG_USART_TRANS			_VECTOR(15)
#define SIG_UART_TRANS			_VECTOR(15)
#endif
/****************I2C*******************/
#if AVR_I2C_MODULE==1
#define		TWBR				(*(volatile u8 *)0x20)
#define		TWCR				(*(volatile u8 *)0x56)
#define		TWSR				(*(volatile u8 *)0x21)
#define		TWDR				(*(volatile u8 *)0x23)
#define		TWAR				(*(volatile u8 *)0x22)

/* TWBR */
#define		TWBR7	7
#define		TWBR6	6
#define		TWBR5	5
#define		TWBR4	4
#define		TWBR3	3
#define		TWBR2	2
#define		TWBR1	1
#define		TWBR0	0

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* 2-wire Serial Interface */
#define TWI_vect			_VECTOR(19)
#define SIG_2WIRE_SERIAL		_VECTOR(19)

/* Store Program Memory Ready */
#define SPM_RDY_vect			_VECTOR(20)
#define SIG_SPM_READY			_VECTOR(20)
#endif
/****************ADC*******************/
#if AVR_ADC_MODULE==1
#define		ADMUX				(*(volatile u8 *)0x27)
#define		ADCSRA				(*(volatile u8 *)0x26)
#define		ADCH				(*(volatile u8 *)0x25)
#define		ADCL				(*(volatile u8 *)0x24)
#define		ADC					(*(volatile u16 *)0x24)

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADC Conversion Complete */
#define ADC_vect			_VECTOR(16)
#define SIG_ADC				_VECTOR(16)
#endif
/****************SFIOR Register*******************/
#define		SFIOR				(*(volatile u8 *)0x50)
/* SFIOR */
#define ADTS2   7
#define ADTS1   6
#define ADTS0   5
/* bit 4 reserved */
#define ACME    3
#define PUD     2
#define PSR2    1
#define PSR10   0

/****************SREG Register*******************/
#define		SREG				(*(volatile u8 *)0x5f)
/* SREG */
#define I_SREG    7
#define T_SREG    6
#define H_SREG    5
#define S_SREG    4
#define V_SREG    3
#define N_SREG    2
#define Z_SREG    1
#define C_SREG    0


#endif /* AVR_COMM_H_ */
