/*
 * LED_MATRIX_interface.h
 *
 *  Created on: May 27, 2023
 *      Author: mohnd
 */

#ifndef HAL_LED_MATRIX_LED_MATRIX_INTERFACE_H_
#define HAL_LED_MATRIX_LED_MATRIX_INTERFACE_H_


void LEDMATRIX_voidInit();
void LEDMATRIX_voidDisplayPattern(u8 Copy_au8PatternArray[],u8 Copy_Period);
// this function to deactivate all col and rows of led matrix
void LEDMATRIX_voidOff();
#endif /* HAL_LED_MATRIX_LED_MATRIX_INTERFACE_H_ */
