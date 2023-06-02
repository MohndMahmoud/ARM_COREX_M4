/*
 * NVIC_program.c
 *
 *  Created on: May 22, 2023
 *      Author: mohnd
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"NVIC_interface.h"
#include"NVIC_private.h"
#include"NVIC_config.h"



void NVIC_voidInit(){
	/*Local variable for the value of the AIRCR*/
	u32 Local_u32RegValue;
	/*set configurations os system software priorities*/
	Local_u32RegValue=VECT_KEY|(PRIORITY_CONFIG<<8);
	SCB_AIRCR=Local_u32RegValue;


}


void NVIC_voidEnableInterrupt(u8 Copy_u8IntID){
	/* divide the interrupt id on 32 to get the register related to the interrupt*/
	u8 Local_Reg_Num=Copy_u8IntID/32;
	/* divide the interrupt id on 32 to get the bit number related to the interrupt*/
	u8 Local_INT_Bit=Copy_u8IntID%32;
	Local_INT_Bit=1<<Local_INT_Bit;
	NVIC->ISER[Local_Reg_Num]=Local_INT_Bit;

}
void NVIC_voidDisableInterrupt(u8 Copy_u8IntID){
	/* divide the interrupt id on 32 to get the register related to the interrupt*/
		u8 Local_Reg_Num=Copy_u8IntID/32;
		/* divide the interrupt id on 32 to get the bit number related to the interrupt*/
		u8 Local_INT_Bit=Copy_u8IntID%32;
		Local_INT_Bit=1<<Local_INT_Bit;
		NVIC->ICER[Local_Reg_Num]=Local_INT_Bit;

}
void NVIC_voidSetPendingFlag(u8 Copy_u8IntID){
	/* divide the interrupt id on 32 to get the register related to the interrupt*/
		u8 Local_Reg_Num=Copy_u8IntID/32;
		/* divide the interrupt id on 32 to get the bit number related to the interrupt*/
		u8 Local_INT_Bit=Copy_u8IntID%32;
		Local_INT_Bit=1<<Local_INT_Bit;
		NVIC->ISPR[Local_Reg_Num]=Local_INT_Bit;

}
void NVIC_voidClearpendingFlag(u8 Copy_u8IntID){
	/* divide the interrupt id on 32 to get the register related to the interrupt*/
		u8 Local_Reg_Num=Copy_u8IntID/32;
		/* divide the interrupt id on 32 to get the bit number related to the interrupt*/
		u8 Local_INT_Bit=Copy_u8IntID%32;
		Local_INT_Bit=1<<Local_INT_Bit;
		NVIC->ICPR[Local_Reg_Num]=Local_INT_Bit;

}
u8 NVIC_u8ReadActiveFlag(u8 Copy_u8IntID){
	u8 Local_Active_Flag;
	/* divide the interrupt id on 32 to get the register related to the interrupt*/
			u8 Local_Reg_Num=Copy_u8IntID/32;
			/* divide the interrupt id on 32 to get the bit number related to the interrupt*/
			u8 Local_INT_Bit=Copy_u8IntID%32;

	Local_Active_Flag=GET_BIT(NVIC->ICPR[Local_Reg_Num],Local_INT_Bit);
	return Local_Active_Flag;
}
void NVIC_voidSetSoftwarePriority(u8 Copy_u8SWPriority,u8 Copy_u8IntID){
	NVIC->IPR[Copy_u8IntID]=Copy_u8SWPriority<<4;


}
