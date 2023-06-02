/*
 * UART_private.h
 *
 *  Created on: May 21, 2023
 *      Author: mohnd
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_
typedef struct{
	u32 UART_SR;// UART  status register
	u32 UART_DR;// UART Data reg
	u32 UART_BRR;//UART doud rate reg
	u32 UART_CR1;
	u32 UART_CR2;
	u32 UART_CR3;
	u32 UART_GPTR;


}UART_REG_t;

#define UART1  ((UART_REG_t *)(0x40011000))
#define UE_CR1 13 //UART enable
#define M_CR1  12
#define PCE_CR1 10
#define PS_CR1  9
#define TE_CR1  3
#define RE_CR1  2

#endif /* MCAL_UART_UART_PRIVATE_H_ */
