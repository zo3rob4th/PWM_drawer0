/*
 * ATmega32A_Config.h
 *
 * Created: 1/12/2024
 *  Author:Ahmed Yasser
 */ 

#include "App.h"

long long local_uint8Counter;
unsigned char EXT_state = 0;
unsigned long long Time_On;
unsigned long long Time_Off;
unsigned long long totalTime;
float duty_cycly;
float freq;



void MeasureSignal(){
	totalTime = Time_On + Time_Off;
	freq = 1000.0/(float)totalTime;
	duty_cycly = (float)(Time_On*100.0) /(float)(totalTime);
}


void Display_SignalMeasurement( ){
	
	char nummm[10];
	
	GLCD_ClearDisplay();

	/*************************************   DISPLAY FREQUENCY   *************************************/
	GLCD_GoToLine(0);
	sprintf(nummm,"freq=%0.2f",freq);
	GLCD_DisplayString(nummm);
	
	/*************************************   DISPLAY DUTY_CYCLE   *************************************/
	GLCD_GoToLine(2);
	sprintf(nummm,"duty=%0.1f%%",duty_cycly);
	GLCD_DisplayString(nummm);
	
	/*************************************   DISPLAY TOTAL_TIME   *************************************/
	GLCD_GoToLine(5);
	sprintf(nummm,"T=%0.2f ms",(float)(totalTime*0.001));
	GLCD_DisplayString(nummm);
}

void Display_Signal(void){
	
		/*************************************   DISPLAY Signal   *************************************/

	GLCD_GoToLine(6);
	GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_RISING_EDGE);
	int dutyRef = duty_cycly*(8.0/100.0);
	
	for(char index = 1; index < (dutyRef+1);index++){
		GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_HIGH_LINE);
	}
	GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_FALLING_EDGE);
	for(char index = 1; index<(9-dutyRef);index++){
		GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_LOW_LINE);
	}
	
	GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_RISING_EDGE);
	
	for(char index = 1; index < (dutyRef +1);index++){
		GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_HIGH_LINE);
	}
	GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_FALLING_EDGE);
	
	
	for(char index = 1; index < (9-dutyRef);index++){
		GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_LOW_LINE);
	}
	
	GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_RISING_EDGE);
	for(char index = 1; index < (dutyRef+1);index++){
		GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_HIGH_LINE);
	}
}

//ISR External Interrupt (normal mode0)
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	if(EXT_state == 0){
		//store timer value ---> TOFF
		Time_Off = (local_uint8Counter*65536+TCNT1_uint16_REG)*4;// time in microseconds
		// reset timer
		local_uint8Counter =0;
		TCNT1_uint16_REG =0;
		
	}
	else{
		//store timer value ---> TON
		Time_On = (local_uint8Counter*65536+TCNT1_uint16_REG)*4;// time in microseconds
		// reset timer
		local_uint8Counter =0;
		TCNT1_uint16_REG =0;
		
	}
	EXT_state = (!EXT_state);
	
	EXTI_voidInit(EXTI_INT0, EXT_state);
}




//ISR Timer1 OverFlow (normal mode0)
void __vector_9(void) __attribute__ ((signal));
void __vector_9(void)
{
	local_uint8Counter++;
}