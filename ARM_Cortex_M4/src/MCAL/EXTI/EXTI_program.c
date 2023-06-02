/*
 * EXTI_program.c
 *
 *  Created on: May 22, 2023
 *      Author: mohnd
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"EXIT_interface.h"
#include"EXTI_private.h"


/*Global variable*/
Ptr_Func _EXTI[16]={NULL};





/**************************************************Function implemintation****************/
void EXTI_voidEnableInt(u8 Copy_u8IntID,Ptr_Func Copy_CallBACk){


	SET_BIT(EXTI->IMR,Copy_u8IntID);
	if(Copy_CallBACk!=NULL){

	_EXTI[Copy_u8IntID]=Copy_CallBACk;

		}

}
void EXTI_voidDisableInt(u8 Copy_u8IntID){
	CLR_BIT(EXTI->IMR,Copy_u8IntID);


}
void EXTI_voidSetSensSignal(u8 Copy_u8SensSignal,u8 Copy_u8IntID){

	switch(Copy_u8SensSignal){
	case RISING_EDGE:
		CLR_BIT(EXTI->FSTR,Copy_u8IntID);
		SET_BIT(EXTI->RSTR,Copy_u8IntID);

		break;
	case FALLING_EDGE:
		CLR_BIT(EXTI->RSTR,Copy_u8IntID);
		SET_BIT(EXTI->FSTR,Copy_u8IntID);
		break;
	case ON_CHANGE:
		SET_BIT(EXTI->RSTR,Copy_u8IntID);
		SET_BIT(EXTI->FSTR,Copy_u8IntID);
		break;

	}


}
void EXTI_voidSetLinePort(u8 Copy_u8IntID,u8 Copy_u8PortID){
// apply equation to map the value to registers
EXTILR->EXTICR[Copy_u8IntID/4]&=~(0b1111<<((Copy_u8IntID%4)*4));
EXTILR->EXTICR[Copy_u8IntID/4]|=(Copy_u8PortID<<((Copy_u8IntID%4)*4));
}


static void EXTI_voidClearPendingflag(u8 Copy_u8IntID){
	SET_BIT(EXTI->PR,Copy_u8IntID);
}

void EXTI0_IRQHandler(void){

	if(_EXTI[0]!=NULL){

		_EXTI[0]();


	}
	EXTI_voidClearPendingflag(EXTI_LINE0);

}
void EXTI1_IRQHandler(void){

	if(_EXTI[1]!=NULL){

		_EXTI[1]();


	}
	EXTI_voidClearPendingflag(EXTI_LINE1);

}

