/*
 * main.c
 *
 *  Created on: Oct 12, 2021
 *      Author: DELL
 */
#include "ADC.H"
#include "LM35.h"
#include "LCD.h"
#include "DC_MOTOR.h"


int main(void){
	 LCD_init();
	 ADC_Configtype Config_ptr={internal,F_CPU_8};
	 ADC_init(&Config_ptr);
	 DcMotor_Init();
uint8 tempreture;
    LCD_moveCursor(1,1);
    LCD_displayString("temp =    c");

while(1){

	tempreture= LM35_getTemperature();
	LCD_moveCursor(0,7);
	if(tempreture<30){
		LCD_moveCursor(0,0);
		DcMotor_Rotate(STOP ,0);
		LCD_displayStringRowColumn(0,2,"FAN IS OFF");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1,7);
	    LCD_intgerToString(tempreture);
	    LCD_moveCursor(1,9);
	    LCD_displayCharacter(' ');

	}

		else if(tempreture>=30 &&(tempreture <60)){

		DcMotor_Rotate(CLOCK_WISE,25);
		LCD_displayStringRowColumn(0,2,"FAN IS ON");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1,7);
		LCD_intgerToString(tempreture);
		LCD_moveCursor(1,9);
		LCD_displayCharacter(' ');
		}
		else if((tempreture>=60)&& (tempreture <90)){
			DcMotor_Rotate(CLOCK_WISE,50);
			LCD_displayStringRowColumn(0,2,"FAN IS ON");
			LCD_displayCharacter(' ');
		    LCD_moveCursor(1,7);
		    LCD_intgerToString(tempreture);
		    LCD_moveCursor(1,9);
		    LCD_displayCharacter(' ');
		}
		else if((tempreture>=90) && (tempreture <120)){
			DcMotor_Rotate(CLOCK_WISE,75);
			LCD_displayStringRowColumn(0,2,"FAN IS ON");
			LCD_displayCharacter(' ');
					LCD_moveCursor(1,7);
					LCD_intgerToString(tempreture);
					//LCD_moveCursor(1,9);
					LCD_displayCharacter(' ');


		}
		else if (tempreture>=120){
			DcMotor_Rotate(CLOCK_WISE,100);
			LCD_displayStringRowColumn(0,2,"FAN IS ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,7);
				LCD_intgerToString(tempreture);

				LCD_displayCharacter(' ');

		}
	}

}
