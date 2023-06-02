/*
 * EXTI_private.h
 *
 *  Created on: May 22, 2023
 *      Author: mohnd
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


typedef struct{
	u32 EXTICR[4];

}LINE_REG_t;
typedef struct{
u32 IMR;
u32 EMR;
u32 RSTR;
u32 FSTR;
u32 SWIER;
u32 PR;

}EXTI_REG_t;

#define EXTILR  ((LINE_REG_t*)(0x40013808))
#define EXTI    ((EXTI_REG_t*)(0x40013C00))
#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
