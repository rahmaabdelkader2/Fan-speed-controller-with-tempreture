/*
 * DC_MOTOR.h
 *
 *  Created on: Oct 11, 2021
 *      Author: DELL
 */


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"

typedef enum
{
STOP,CLOCK_WISE,ANTI_CLOCKWISE
}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
