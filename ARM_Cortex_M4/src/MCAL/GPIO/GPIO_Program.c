/*
 * GPIO_Program.c
 *
 *  Created on: May 11, 2023
 *      Author: mohnd
 */
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"GPIO_interface.h"
#include"GPIO_private.h"
#include"GPIO_config.h"


/*this fin is to initialize any pin to be an Out pin*/
void GPIO_voidInitOutputPin(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinTYPES,u8 Copy_u8PinSpeed){
	switch (Copy_u8PortID){
	case GPIO_PORTA:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		GPIOA->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOA->ModeR |=(0b01<<(Copy_u8PinID*2));
		/*set the SPEED of the pin to be output*/
		/*bit masking*/
		GPIOA->OSPEEDR &=~(0b11<<(Copy_u8PinID*2));
		GPIOA->OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));
		/*Set type of output pin*/
		WR_BIT(GPIOA->OTYPER,Copy_u8PinID,Copy_u8PinTYPES);

		break;
	case GPIO_PORTB:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		GPIOB->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOB->ModeR |=(0b01<<(Copy_u8PinID*2));
		/*set the SPEED of the pin to be output*/
		/*bit masking*/
		GPIOB->OSPEEDR &=~(0b11<<(Copy_u8PinID*2));
		GPIOB->OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));
		/*Set type of output pin*/
		WR_BIT(GPIOB->OTYPER,Copy_u8PinID,Copy_u8PinTYPES);

		break;
	case GPIO_PORTC:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		GPIOC->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOC->ModeR |=(0b01<<(Copy_u8PinID*2));
		/*set the SPEED of the pin to be output*/
		/*bit masking*/
		GPIOC->OSPEEDR &=~(0b11<<(Copy_u8PinID*2));
		GPIOC->OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));
		/*Set type of output pin*/
		WR_BIT(GPIOC->OTYPER,Copy_u8PinID,Copy_u8PinTYPES);

		break;
	}
}

/*ths fun is to initialize and pin to be in pin*/
void GPIO_voidInitInputPin(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinMode){
	switch (Copy_u8PortID){
	case GPIO_PORTA:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		GPIOA->ModeR &=~(3<<(Copy_u8PinID*2));

		GPIOA->PUPDR&=~(3<<(Copy_u8PinID*2));
		GPIOA->PUPDR|=(Copy_u8PinMode<<(Copy_u8PinID*2));

		break;
	case GPIO_PORTB:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		GPIOB->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOB->PUPDR&=~(3<<(Copy_u8PinID*2));
		GPIOB->PUPDR|=(Copy_u8PinMode<<(Copy_u8PinID*2));

		break;
	case GPIO_PORTC:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		GPIOC->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOC->PUPDR&=~(3<<(Copy_u8PinID*2));
		GPIOC->PUPDR|=(Copy_u8PinMode<<(Copy_u8PinID*2));
		break;
	}
}
/*this fun is to set the value of any output pin[high/low]*/
void GPIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8value){
	switch (Copy_u8PortID){
	case GPIO_PORTA:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		WR_BIT(GPIOA->ODR,Copy_u8PinID,Copy_u8value);
		break;
	case GPIO_PORTB:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		WR_BIT(GPIOB->ODR,Copy_u8PinID,Copy_u8value);

		break;
	case GPIO_PORTC:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		WR_BIT(GPIOC->ODR,Copy_u8PinID,Copy_u8value);

		break;
	}
}
void GPIO_voidSetPinValueFAST(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8value){
	u32 Local_value=0;
	switch (Copy_u8PortID){
	case GPIO_PORTA:
		/*using the BSRR to make  atomic instructions */
		if(Copy_u8value==GPIO_OUTPUT_HIGH){
			Local_value=(1<<Copy_u8PinID);
		}
		else if (Copy_u8value==GPIO_OUTPUT_LOW){
			Local_value=(1<<(Copy_u8PinID+16));
		}
		GPIOA->BSRR=Local_value;
		break;
	case GPIO_PORTB:

		if(Copy_u8value==GPIO_OUTPUT_HIGH){
			Local_value=(1<<Copy_u8PinID);
		}
		else if (Copy_u8value==GPIO_OUTPUT_LOW){
			Local_value=(1<<(Copy_u8PinID+16));
		}
		GPIOB->BSRR=Local_value;
		break;
	case GPIO_PORTC:
		if(Copy_u8value==GPIO_OUTPUT_HIGH){
			Local_value=(1<<Copy_u8PinID);
		}
		else if (Copy_u8value==GPIO_OUTPUT_LOW){
			Local_value=(1<<(Copy_u8PinID+16));
		}
		GPIOC->BSRR=Local_value;
		break;
	}
}
/*This function set value for any 8 sequence pins in any port */
void GPIO_void_8_SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinsStarts,u8 Copy_u8value){
	switch(Copy_u8PortID){
	case GPIO_PORTA:
		/*set the VALue of the pin to be HIGH OR LOW*/
		/*bit masking*/
		GPIOA->ODR&=~(0xFF<<(Copy_u8PinsStarts*1));
		GPIOA->ODR|=Copy_u8value;
		break;
	case GPIO_PORTB:
		/*set the VALue of the pin to be HIGH OR LOW*/
		/*bit masking*/
		GPIOB->ODR&=~(0xFF<<(Copy_u8PinsStarts*1));
		GPIOB->ODR|=Copy_u8value;
		break;

	}
}
/*this fun is to read the value of any input pin[high/low]*/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID){
	u8 Local_Return=0;
	switch(Copy_u8PortID){
	case GPIO_PORTA:
		Local_Return=GET_BIT(GPIOA->IDR,Copy_u8PinID);
		break;
	case GPIO_PORTB:
		Local_Return=GET_BIT(GPIOB->IDR,Copy_u8PinID);
		break;
	case GPIO_PORTC:
		Local_Return=GET_BIT(GPIOC->IDR,Copy_u8PinID);
		break;
	}
	return Local_Return;
}
void GPIO_voidTGLPin(u8 Copy_u8PortID,u8 Copy_u8PinID){
	switch (Copy_u8PortID){
	case GPIO_PORTA:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		TGL_BIT(GPIOA->ODR,Copy_u8PinID);


		break;
	case GPIO_PORTB:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		TGL_BIT(GPIOB->ODR,Copy_u8PinID);
		break;
	case GPIO_PORTC:
		/*set the direction of the pin to be output*/
		/*bit masking*/
		TGL_BIT(GPIOC->ODR,Copy_u8PinID);
		break;
	}
}
/*This fun to set the alternative function of GPIO*/
void GPIO_voidSetAlternitiveFUNC(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8AlternitiveFUN){

	switch (Copy_u8PortID){
	case GPIO_PORTA:
		/*set the MOde of PIn TO BE ALternative */
		/*bit masking*/
		GPIOA->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOA->ModeR |=(0b10<<(Copy_u8PinID*2));
		GPIOA->AFRL&=~(0b1111 <<Copy_u8PinID*4);
		GPIOA->AFRL|=(Copy_u8AlternitiveFUN <<Copy_u8PinID*4);
		break;
	case GPIO_PORTB:
		/*set the MOde of PIn TO BE ALternative */
		/*bit masking*/
		GPIOB->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOB->ModeR |=(0b10<<(Copy_u8PinID*2));
		GPIOB->AFRL&=~(0b1111 <<Copy_u8PinID*4);
		GPIOB->AFRL|=(Copy_u8AlternitiveFUN <<Copy_u8PinID*4);
		break;
	case GPIO_PORTC:
		/*set the MOde of PIn TO BE ALternative */
		/*bit masking*/
		GPIOC->ModeR &=~(3<<(Copy_u8PinID*2));
		GPIOC->ModeR |=(0b10<<(Copy_u8PinID*2));
		GPIOC->AFRL&=~(0b1111 <<Copy_u8PinID*4);
		GPIOC->AFRL|=(Copy_u8AlternitiveFUN <<Copy_u8PinID*4);
		break;
	}
}
