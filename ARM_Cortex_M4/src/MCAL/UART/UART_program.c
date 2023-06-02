/*
 * UART_program.c
 *
 *  Created on: May 21, 2023
 *      Author: mohnd
 */
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"UART_interface.h"
#include"UART_config.h"
#include"UART_private.h"
//1.Enable the USART by writing the UE bit in USART_CR1 register to 1.
//2. Program the M bit in USART_CR1 to define the word length.
//3. Program the number of stop bits in USART_CR2.
//4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
//place. Configure the DMA register as explained in multibuffer communication.
//5. Select the desired baud rate using the USART_BRR register.
//6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
//7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
//for each data to be transmitted in case of single buffer.
//8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
//that the transmission of the last frame is complete. This is required for instance when
//the USART is disabled or enters the Halt mode to avoid corrupting the last
//transmission.
void UART_voidInit(){
	// step 1 enable UART
	UART1->UART_CR1|=(1<<M_CR1);
	UART1->UART_CR1|=(1<<PCE_CR1);
UART1->UART_CR1|=(1<<TE_CR1);
UART1->UART_CR1|=(1<<RE_CR1);
 UART1->UART_BRR =(u16)(25000000/(16*9600));
 UART1->UART_CR1|=(1<<UE_CR1);
}
void UART_voidSend(u8 Copy_u8Data){
	while(GET_BIT(UART1->UART_SR,7)==0);// polling over buffer empty
	UART1->UART_DR=Copy_u8Data;
	while(GET_BIT(UART1->UART_SR,6)==0);// polling over send complete flag
	CLR_BIT(UART1->UART_SR,6);


}
u8 UART_u8Recive(){

	while(GET_BIT(UART1->UART_SR,5)==0);

return UART1->UART_DR;



}
