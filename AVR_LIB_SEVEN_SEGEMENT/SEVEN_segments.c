/*
 * SEVEN_segments.c
 *
 *  Created on: Nov 8, 2015
 *      Author: Mohamed
 */

/*
 * Seven Segments Driver using 7447 which takes BCD corresponding to number form 0 to 9
 * and the convert it to Binary
 * So it needs 4 pins for data and 4 pins for control which be can configured in
 * SEVEN_segments_CFG.h
 * */
#include "common.h"

u8  data[DATA_LINES]={DATA_LINE1,DATA_LINE2,DATA_LINE3,DATA_LINE4};
u8  control[CONTROL_LINES]={CONTROL_LINE1,CONTROL_LINE2,CONTROL_LINE3,CONTROL_LINE4};
u8  counter;
u8  counter_2;

/**  This function is used to initialize the micro to use 7-segments
 * The function can be edited in SEVEN_segments_CFG.h
 * **/
void SEVEN_SEGMENTS_init (void)
{
	/*Set the data direction of Data lines and initial state*/
	for(counter=0;counter<DATA_LINES;counter++)
	{
		DIO_set_pin_direction(data[counter],OUTPUT);
		DIO_set_pin(data[counter],LOW);
	}

	/*Set the control direction of Data lines and initial state*/
	for(counter=0;counter<CONTROL_LINES;counter++)
	{
		DIO_set_pin_direction(control[counter],OUTPUT);
		DIO_set_pin(control[counter],HIGH);
	}/**  This functions is used to write on the 7-segments**/


}

/**  This functions is used to write on the 7-segments**/
void SEVEN_SEGMENTS_write(u32 number)
{

	if(number>9999)number=9999;
	u8 loop_counter=number_of_digits(number);
	u8 *digits=toArray(number,loop_counter);

	for(counter_2=0;counter_2<loop_counter;counter_2++)
	{
		DIO_set_pin(control[counter_2],LOW);
		for (counter=0;counter<DATA_LINES;counter++)
		{
			DIO_set_pin(data[counter],GET_BIT(digits[counter_2],counter));
		}
		_delay_ms(10);
		DIO_set_pin(control[counter_2],HIGH);
	}
	free(digits);

}

/**To get the number of digits **/
u8 number_of_digits(u32 number)
{
	u8 digits_number=0;
	while(number!=0)
	{
		number/=10;
		digits_number++;
	}
	return(digits_number);
}

/**To get an U8 into array**/
u8 *toArray(u32 number , u8 digits_number)
{

	u8 *numberArray = calloc(digits_number, sizeof(u8));
	for ( counter = 0; counter<digits_number ;counter++, number /= 10 )
	{
		numberArray[counter] = number % 10;
	}
	return (numberArray);
}


