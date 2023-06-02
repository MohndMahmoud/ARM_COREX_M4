/*
 * NVIC_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: mohnd
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#define GROUP4_SUB0              (0)// Support 16 group and 0 sub
#define GROUP3_SUB1              (4)// support 8 group and 2 sub
#define GROUP2_SUB2              (5)// support 4 group and 4 sub
#define GROUP1_SUB3              (6)// support 2 group and 8 sub
#define GROUP0_SUB4              (7)//support 0 group and 16 sub
#define VECT_KEY            (0x05FA0000) /*this macro to combine with chosen priority from config*/
/******************************Prototype of function********************************************/
void NVIC_voidInit();
// this function to enable the interrupt
void NVIC_voidEnableInterrupt(u8 Copy_u8IntID);
//this function is to disable the interrupt
void NVIC_voidDisableInterrupt(u8 Copy_u8IntID);
// this function to active the pending flag
void NVIC_voidSetPendingFlag(u8 Copy_u8IntID);
// this function to Clear the peanding flag
void NVIC_voidClearpendingFlag(u8 Copy_u8IntID);
// this function to read the active flag
u8 NVIC_u8ReadActiveFlag(u8 Copy_u8IntID);
/*this function to Configure  the priority group*/
void NVIC_voidSetSoftwarePriority(u8 Copy_u8SWPriority,u8 Copy_u8IntID);
#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
