/*
 * EXIT_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: mohnd
 */

#ifndef MCAL_EXTI_EXIT_INTERFACE_H_
#define MCAL_EXTI_EXIT_INTERFACE_H_
#define FALLING_EDGE     1
#define RISING_EDGE      2
#define ON_CHANGE        3
#define EXTI_PORTA      0
#define EXTI_PORTB      1
#define EXTI_PORTC      2
//macros for lines /pins
#define EXTI_LINE0      0
#define EXTI_LINE1      1
#define EXTI_LINE2      2
#define EXTI_LINE3      3
#define EXTI_LINE4      4
#define EXTI_LINE5      5
#define EXTI_LINE6      6
#define EXTI_LINE7      7
#define EXTI_LINE8      8
#define EXTI_LINE9      9
#define EXTI_LINE10      10
#define EXTI_LINE11      11
#define EXTI_LINE12      12
#define EXTI_LINE13      13
#define EXTI_LINE14     14
#define EXTI_LINE15      15
void EXTI_voidEnableInt(u8 Copy_u8IntID,Ptr_Func Copy_CallBACk);
void EXTI_voidDisableInt(u8 Copy_u8IntID);
void EXTI_voidSetSensSignal(u8 Copy_u8SensSignal,u8 Copy_u8IntID);
void EXTI_voidSetLinePort(u8 Copy_u8IntID,u8 Copy_u8PortID);
static void EXTI_voidClearPendingflag(u8 Copy_u8IntID);
#endif /* MCAL_EXTI_EXIT_INTERFACE_H_ */
