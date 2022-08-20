/*
 * ADC.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Rahma abdelkader
 */
#include "std_types.h"

#ifndef ADC_H_
#define ADC_H_


 //       *********DEFINITIONS*******

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

//       *********PROTOTYPES*********
typedef enum{
	F_CPU_CLOCK_1,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescalar;
typedef enum{
	AVCC, AREF,RESERVED,internal
}ADC_ReferenceVoltage;
typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescalar prescalar;
}ADC_Configtype;

void ADC_init(const ADC_Configtype*config_ptr);
uint16 ADC_readChannel(uint8 channel_num);



#endif /* ADC_H_ */
