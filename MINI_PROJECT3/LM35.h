/*
 * LM35.h
 *
 *  Created on: Oct 9, 2021
 *      Author: DELL
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"

//    **********def***********

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

//    *********Prototypes**********
uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
