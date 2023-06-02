/*
 * STK_program.c
 *
 *  Created on: May 25, 2023
 *      Author: mohnd
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"STK_interface.h"
#include"STK_private.h"
#include"STK_config.h"

Ptr_Func STK_HANDELR=NULL;
//this flag to make the isr understand if we use async or async periodic
u8 Global_u8AsyncFlag=Single;
void STK_voidInit(){
	/*this module work on HSI FOR now */
	STK->CTRL=0;
	/*reset val and load reg*/
	STK->LOAD=0;
	STK->VAL=0;

}
void STK_voidDelaySYNC(u32 Copy_DelayMS){
	// make sure that interrupt is disable
	CLR_BIT(STK->CTRL,1);
	STK->LOAD=(Copy_DelayMS*2);

	// start systick
	SET_BIT(STK->CTRL,0);

	// polling and reading the flag to clera it
	while(GET_BIT(STK->CTRL,16)==0);

	CLR_BIT(STK->CTRL,0);
	STK->LOAD=0;
	STK->VAL=0;
}
void STK_voidDelayAsync(u32 Copy_DelayMS,Ptr_Func APP){
	Global_u8AsyncFlag=Single;
	// enable the interrupt
SET_BIT(STK->CTRL,1);
	STK->LOAD=(Copy_DelayMS*2);
	STK->VAL=0;
	if(APP!=NULL)
	{
		STK_HANDELR=APP;


	}
	// start systick
		SET_BIT(STK->CTRL,0);

}
void STK_voidDelayAsyncPER(u32 Copy_DelayMS,Ptr_Func APP){
	Global_u8AsyncFlag=periodic;
	// enable the interrupt
SET_BIT(STK->CTRL,1);
	STK->LOAD=(Copy_DelayMS*2);
	STK->VAL=0;
	if(APP!=NULL)
	{
		STK_HANDELR=APP;


	}
	// start systick
		SET_BIT(STK->CTRL,0);

}
u32 STK_u32GetRemaining(){

return STK->VAL;

}
u32 STK_u32Getelibse(){

	return (STK->LOAD - STK->VAL);


}
void SysTick_Handler(void){

   switch(Global_u8AsyncFlag){
   case Single:
	if(STK_HANDELR!=NULL){


		STK_HANDELR();
	}
	CLR_BIT(STK->CTRL,0);
break;
   case periodic:
	   if(STK_HANDELR!=NULL){
u8 clrflag;

	   		STK_HANDELR();
	   		clrflag=GET_BIT(STK->CTRL,16);
	   	}
	   break;


}
}

