/*
 * DC_MOTOR.c
 *
 *  Created on: Oct 11, 2021
 *      Author: DELL
 */
#include "common_macros.h"
#include "DC_MOTOR.h"
#include "PWM.h"
#include "gpio.h"

void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);//PB0
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);//PB1
	//STOP MOTOR
    GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_LOW);
    GPIO_writePin(PORTB_ID,PIN1_ID , LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 Duty_cycle;

	if(speed==100){
		Duty_cycle=255;

	}
	else
	{
		Duty_cycle=speed+(((speed/25)*39));
	}
	PWM_Timer0_Init( Duty_cycle);
	if(state==CLOCK_WISE){
		  GPIO_writePin(PORTB_ID,PIN1_ID , LOGIC_LOW);
		  GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_HIGH);
	}
	else if(state==ANTI_CLOCKWISE){
		  GPIO_writePin(PORTB_ID,PIN1_ID , LOGIC_HIGH);
		  GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_LOW);
	}
	else{
		   GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_LOW);
		    GPIO_writePin(PORTB_ID,PIN1_ID , LOGIC_LOW);
}
}
