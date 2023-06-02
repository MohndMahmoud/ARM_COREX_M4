/*
 * NVIC_private.h
 *
 *  Created on: May 22, 2023
 *      Author: mohnd
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_
/* ********************************************NVIC************************************************/
typedef struct{
	u32 ISER[8];
	u32 Reserved[24];
	u32 ICER[8];
	u32 Reserved1[24];
	u32 ISPR[32];
	u32 ICPR[32];
	u32 IABR[64];
	u8 IPR[240];



}NVIC_REG_t;
#define NVIC  ((NVIC_REG_t*)(0xE000E100))

#define SCB_AIRCR  *((volatile u32*)0xE000ED0C)
#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
