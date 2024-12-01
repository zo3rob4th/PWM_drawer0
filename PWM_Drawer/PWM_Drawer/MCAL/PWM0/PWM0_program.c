/*
 * ATmega32A_Config.h
 *
 * Created: 1/12/2024
 *  Author:Ahmed Yasser
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "PWM0_interface.h"
#include "PWM0_config.h"
#include "PWM0_private.h"
#include "PWM0_register.h"


void PWM0_voidInit(void)
{
	//Select Mode = fast PWM Mode
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);

#if PWM0_OUTPUT_MODE == PWM0_NONINVERTING
	// Select Non Inverting Output
	CLR_BIT(TCCR0_REG, COM00);
	SET_BIT(TCCR0_REG, COM01);

#elif PWM0_OUTPUT_MODE == PWM0_INVERTING

#endif
}


void PWM0_voidGeneratePWM(uint8 copy_uint8DutyCycle)
{
	if(copy_uint8DutyCycle <= 100)
	{
#if PWM0_OUTPUT_MODE == PWM0_NONINVERTING
		OCR0_REG = ((copy_uint8DutyCycle * 256) / 100) - 1;

#elif PWM0_OUTPUT_MODE == PWM0_INVERTING

#endif

		//Select prescaler Value = 64
		SET_BIT(TCCR0_REG, CS00);
		SET_BIT(TCCR0_REG, CS01);
		CLR_BIT(TCCR0_REG, CS02);
	}
}


void PWM0_voidStop(void)
{
	CLR_BIT(TCCR0_REG, CS00);
	CLR_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);
}
