/*
 * ADC.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Rahma Abdelkader
 */

#include <avr/io.h>
#include "ADC.h"
#include "common_macros.h"

void ADC_init(const ADC_Configtype * Config_Ptr)
{
	SET_BIT(ADCSRA,ADEN);
    ADMUX=(ADMUX & 0x3F)|(Config_Ptr->ref_volt<<6);
    ADCSRA=(ADCSRA & 0xF8)|(Config_Ptr->prescalar);
}
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07;//ADC2
	ADMUX &= 0xE0;
	ADMUX = ADMUX | channel_num;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC; //Read the digital value
}
