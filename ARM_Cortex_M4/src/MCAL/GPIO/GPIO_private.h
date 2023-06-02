/*
 * GPIO_private.h
 *
 *  Created on: May 11, 2023
 *      Author: mohnd
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

typedef struct {
	u32 ModeR;   // this reg to set the mode for any pin
	u32 OTYPER; // the reg to set the type of any out pin (push pull/oen drain)
	u32 OSPEEDR;// this reg is to set the speed of outputs pins.
	u32 PUPDR;// this reg to select the pin to pull up or pull down
	u32 IDR;// this reg to read the value of an input pin
	u32 ODR;// this reg is to set the value of output pins
	u32 BSRR; // this reg is to set and Clear the value of OUTPUt PINS with atomic instruction
	u32 LCKR; // This reg to lock a behaver of  a  any GPIO pin
	u32 AFRL; // This reg to set the alternate function of Pins From 0 to 7 on any Port
	u32 AFRH;// This reg to set the alternate function of Pins From 8 to 15 on any Port

}GPIO_REG_t;
#define GPIOA   ((GPIO_REG_t*)(0x40020000))
#define GPIOB   ((GPIO_REG_t*)(0x40020400))
#define GPIOC   ((GPIO_REG_t*)(0x40020800))

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
