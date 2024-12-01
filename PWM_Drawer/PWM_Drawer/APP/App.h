/*
 * ATmega32A_Config.h
 *
 * Created: 1/12/2024
 *  Author:Ahmed Yasser
 */ 


#ifndef APP_H_
#define APP_H_

#include "ATmega32A_Config.h"
#include "GLCD.h"
#include "TMR1_interface.h"
#include "TMR1_config.h"
#include "TMR1_private.h"
#include "TMR1_register.h"
#include "GI_interface.h"
#include "EXTI_interface.h"



#include <util/delay.h>
#include <string.h>
#include <stdio.h>


/******************   Signal Patterns Characters  = 5 x 8	************************/


#define PWM_DRAWER_GLCD_HIGH_LINE					(0x0202020202UL)
#define PWM_DRAWER_GLCD_LOW_LINE					(0x4040404040UL)
#define PWM_DRAWER_GLCD_RISING_EDGE					(0x02027E4040UL)
#define PWM_DRAWER_GLCD_FALLING_EDGE				(0x40407E0202UL)




/************************************************************************/
/*						Function Prototypes					            */
/************************************************************************/

void MeasureSignal(void);
void Display_SignalMeasurement(void);
void Display_Signal(void);



#endif 