/*
 * LED_program.c
 *
 *  Created on: May 13, 2023
 *      Author: mohnd
 */


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_interface.h"
#include"LED_interface.h"

void LED_voidInit(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin){
	/*Just calling GPIO peripheral*/
	GPIO_voidInitOutputPin(Copy_u8LEDPort,Copy_u8LEDPin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);


}
void LED_voidON(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin){
	GPIO_voidSetPinValue(Copy_u8LEDPort,Copy_u8LEDPin,GPIO_OUTPUT_HIGH);
}
void LED_voidOFF(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin){
	GPIO_voidSetPinValue(Copy_u8LEDPort,Copy_u8LEDPin,GPIO_OUTPUT_LOW);
}
void LED_voidTGL(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin){
	GPIO_voidTGLPin(Copy_u8LEDPort,Copy_u8LEDPin);


}
