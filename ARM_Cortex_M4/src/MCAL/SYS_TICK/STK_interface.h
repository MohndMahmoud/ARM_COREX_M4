/*
 * STK_interface.h
 *
 *  Created on: May 25, 2023
 *      Author: mohnd
 */

#ifndef MCAL_SYS_TICK_STK_INTERFACE_H_
#define MCAL_SYS_TICK_STK_INTERFACE_H_

#define  Single     1
#define periodic    2
void STK_voidInit();
void STK_voidDelaySYNC(u32 Copy_DelayMS);
void STK_voidDelayAsync(u32 Copy_DelayMS,Ptr_Func APP);
void STK_voidDelayAsyncPER(u32 Copy_DelayMS,Ptr_Func APP);
u32 STK_u32GetRemaining();
 u32 STK_u32Getelibse();
#endif /* MCAL_SYS_TICK_STK_INTERFACE_H_ */
