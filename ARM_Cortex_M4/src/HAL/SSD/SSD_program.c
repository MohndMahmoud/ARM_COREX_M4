/*
 * SSD_program.c
 *
 *  Created on: May 13, 2023
 *      Author: mohnd
 */


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_interface.h"
#include"SSD_interface.h"

void SSD_voidInit(u8 Copy_SSDPort,u8 Copy_u8SSDStartPins,u8 Copy_u8SSDEndPins){
	for(u8 i=Copy_u8SSDStartPins;i<=Copy_u8SSDEndPins;i++){
	GPIO_voidInitOutputPin(Copy_SSDPort,i,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	}

}
void SSD_voidDisplay(u8 Copy_COM,u8 Copy_SSDPort,u8 Copy_u8SSDStartPins,u8 Copy_u8SSDEndPins,u8 Copy_u8Value){
	if(Copy_COM==SSD_COM_CATHOD){
    GPIO_voidSetPinValue(Copy_SSDPort,Copy_u8SSDEndPins,GPIO_OUTPUT_LOW);
    GPIO_void_8_SetPinValue(Copy_SSDPort,Copy_u8SSDStartPins,Copy_u8Value);


	}
	else if(Copy_COM==SSD_COM_ANODE){
		 GPIO_voidSetPinValue(Copy_SSDPort,Copy_u8SSDEndPins,GPIO_OUTPUT_HIGH);
		    GPIO_void_8_SetPinValue(Copy_SSDPort,Copy_u8SSDStartPins,Copy_u8Value);
	}


}
void SSD_voidOF(u8 Copy_COM,u8 Copy_SSDPort,u8 Copy_u8SSDEndPins){
	if(Copy_COM==SSD_COM_CATHOD){
	    GPIO_voidSetPinValue(Copy_SSDPort,Copy_u8SSDEndPins,GPIO_OUTPUT_HIGH);

		}
		else if(Copy_COM==SSD_COM_ANODE){
			 GPIO_voidSetPinValue(Copy_SSDPort,Copy_u8SSDEndPins,GPIO_OUTPUT_LOW);

		}

}
