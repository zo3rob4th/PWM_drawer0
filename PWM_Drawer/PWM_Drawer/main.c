/*
 * main.c
 *
 * Created: 1/12/2024
 *  Author:Ahmed Yasser 
 */ 

#include "ATmega32A_Config.h"

#include "App.h"

#include "GLCD.h"
#include "TMR1_interface.h"
#include "TMR1_config.h"
#include "TMR1_private.h"
#include "TMR1_register.h"
#include "GI_interface.h"
#include "EXTI_interface.h"
#include "PWM0_interface.h"
#include "PWM0_private.h"
#include "PWM0_register.h"

#include <util/delay.h>
#include <string.h>
#include <stdio.h>







int main(void)
{
	
	DIO_SetPinDirection(DIO_PORT_D,2,DIO_INPUT ); //Input
	DIO_SetPinDirection(DIO_PORT_B,3,DIO_OUTPUT); //OC0
	
	
	GI_voidEnable();
	
	
	EXTI_voidInit(EXTI_INT0, EXTI_RISING_EDGE);
	EXTI_voidEnable(EXTI_INT0);
	
	PWM0_voidInit();
	PWM0_voidGeneratePWM(80);
	
	TMR1_voidInit  ();
	TMR1_voidStart ();
	
	
	
	
	GLCD_Init();
	GLCD_ClearDisplay();

			
    while(1)
    {
       
		MeasureSignal();
		Display_SignalMeasurement();
		Display_Signal();
		
		_delay_ms(500);
		
    }
}

