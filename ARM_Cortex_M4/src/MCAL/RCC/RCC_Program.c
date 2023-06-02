/*
 * RCC_Program.c
 *
 *  Created on: May 4, 2023
 *      Author: mohnd
 */
/***********************************************************************************/
// File Discretion : Program file for RCC Module
/**********************************************************************************/

// 1- set system control
// system clock source is a prebuild confg
// 2- set enable /disable Peripheral
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"RCC_interface.h"
#include"RCC_config.h"
#include"RCC_private.h"



void RCC_voidSetSystemClock(void){
#if SYSTEM_clk_src ==HSI
	SET_BIT(RCC_CR,0);
	CLR_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);// chossing HSC_RC what clock to operate in the system


#elif  SYSTEM_clk_src ==HSC_RC
	SET_BIT(RCC_CR,16);// enabe HSE CLOCK
	SET_BIT(RCC_CR,18; // CHOSE RC EXTERNAL CLOCK
	SET_BIT(RCC_CFGR,0);// chossing HSC_RC what clock to operate in the system
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_clk_src == HSC_CRYSTAL
	SET_BIT(RCC_CR,16);// enabe HSE CLOCK
	SET_BIT(RCC_CR,18); // CHOSE CRYstal EXTERNAL CLOCK
	SET_BIT(RCC_CFGR,0);// chossing HSC_RC what clock to operate in the system
	SET_BIT(RCC_CFGR,1);
#elif	 SYSTEM_clk_src ==PLL

#else
    #error("wrong system Clock configurations")
#endif

}


u8 RCC_u8enablePrepheralClock(u8 Copy_u8BUS_ID,u8 Copy_u8Peripheral_ID){
	switch(Copy_u8BUS_ID){

	case RCC_AHB1 :
		SET_BIT(RCC_AHB1ENR,Copy_u8Peripheral_ID);
		break;
	case RCC_AHB2 :
			SET_BIT(RCC_AHB2ENR,Copy_u8Peripheral_ID);
			break;
	case RCC_APB1 :
			SET_BIT(RCC_APB1ENR,Copy_u8Peripheral_ID);
			break;
	case RCC_APB2 :
			SET_BIT(RCC_APB2ENR,Copy_u8Peripheral_ID);
			break;
	default:
		return 1;

	}
	return 0;
}
u8 RCC_u8DisablePrepheralClock(u8 Copy_u8BUS_ID,u8 Copy_u8Peripheral_ID){
	switch(Copy_u8BUS_ID){

		case RCC_AHB1 :
			CLR_BIT(RCC_AHB1ENR,Copy_u8Peripheral_ID);
			break;
		case RCC_AHB2 :
				CLR_BIT(RCC_AHB2ENR,Copy_u8Peripheral_ID);
				break;
		case RCC_APB1 :
				CLR_BIT(RCC_APB1ENR,Copy_u8Peripheral_ID);
				break;
		case RCC_APB2 :
			CLR_BIT(RCC_APB2ENR,Copy_u8Peripheral_ID);
				break;
		default:
				return 1;


		}
		return 0;

}
