/*
 * ATmega32A_Config.h
 *
 * Created: 1/12/2024
 *  Author:Ahmed Yasser
 */ 


#ifndef MCAL_PWM0_INC_PWM0_REGISTER_H_
#define MCAL_PWM0_INC_PWM0_REGISTER_H_


// Timer/Counter Control Register
#define TCCR0_REG			(*(volatile uint8*)0x53)
#define CS00                0
#define CS01                1
#define CS02                2
#define WGM01               3
#define COM00               4
#define COM01               5
#define WGM00               6
#define FOC0                7

// Timer/Counter Register
#define TCNT0_REG           (*(volatile uint8*)0x52)

// Output Compare Register
#define OCR0_REG            (*(volatile uint8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK_REG           (*(volatile uint8*)0x59)
#define TOIE0               0
#define OCIE0               1

// Timer/Counter Interrupt Flag Register
#define TIFR_REG            (*(volatile uint8*)0x58)
#define TOV0                0
#define OCF0                1


#endif /* MCAL_PWM0_INC_PWM0_REGISTER_H_ */
