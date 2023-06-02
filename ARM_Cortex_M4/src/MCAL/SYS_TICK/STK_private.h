/*
 * STK_private.h
 *
 *  Created on: May 25, 2023
 *      Author: mohnd
 */

#ifndef MCAL_SYS_TICK_STK_PRIVATE_H_
#define MCAL_SYS_TICK_STK_PRIVATE_H_
 typedef struct {
volatile u32 CTRL;
volatile u32  LOAD;
volatile u32 VAL;



 }STK_REG_t;


#define  STK    ((STK_REG_t*)(0xE000E010))


#endif /* MCAL_SYS_TICK_STK_PRIVATE_H_ */
