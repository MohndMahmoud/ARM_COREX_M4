/*
 * LED_interface.h
 *
 *  Created on: May 13, 2023
 *      Author: mohnd
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_


void LED_voidInit(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin);
void LED_voidON(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin);
void LED_voidOFF(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin);
void LED_voidTGL(u8 Copy_u8LEDPort,u8 Copy_u8LEDPin);


#endif /* HAL_LED_LED_INTERFACE_H_ */
