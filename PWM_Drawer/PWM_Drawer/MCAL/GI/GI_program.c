/*
 * GI_program.c
 *
  * Created: 1/12/2024
  *  Author:Ahmed Yasser
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GI_interface.h"
#include "GI_register.h"


void GI_voidEnable(void)
{
	SET_BIT(SREG_REG, I);
}

void GI_voidDisable(void)
{
	CLR_BIT(SREG_REG, I);
}
