/*
 * LED_MATRIX_program.c
 *
 *  Created on: May 27, 2023
 *      Author: mohnd
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_interface.h"
#include"../../MCAL/SYS_TICK/STK_interface.h"
#include"LED_MATRIX_interface.h"
#include"LED_MATRIX_private.h"
#include"LED_MATRIX_config.h"

u8 Local_RowsArray[Row_NUM]={Row0,Row1,Row2,Row3,Row4,Row5,Row6,Row7};
u8 Local_COLSArray[COl_NUM]={COL0,COL1,COL2,COL3,COL4,COL5,COL6,COL7};
void LEDMATRIX_voidInit(){
	/*set all row and colums to be output push/pull*/
	u8 Local_u8Iteraror;

	for(Local_u8Iteraror=0;Local_u8Iteraror<8;Local_u8Iteraror++){

		GPIO_voidInitOutputPin(ROWPORT,Local_RowsArray[Local_u8Iteraror],GPIO_PUSH_PULL,GPIO_LOW_SPEED);
		GPIO_voidInitOutputPin(COLPORT,Local_COLSArray[Local_u8Iteraror],GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	}
	for(Local_u8Iteraror=0;Local_u8Iteraror<8;Local_u8Iteraror++){
		// set all col high to deactive them
		GPIO_voidSetPinValue(COLPORT,Local_COLSArray[Local_u8Iteraror],GPIO_OUTPUT_HIGH);
		// set all rows low to make led off
		GPIO_voidSetPinValue(ROWPORT,Local_RowsArray[Local_u8Iteraror],GPIO_OUTPUT_LOW);

	}
}
void LEDMATRIX_voidDisplayPattern(u8 Copy_au8PatternArray[],u8 Copy_Period){
	/*the principles is  we activate the first col then put the rows value then delay then
	 * the repeat the process with other cols*/

	u8 Local_u8ROWSIteraror;
	u8 Local_u8COLIterator;
for(u8 i=0;i<=Copy_Period;i++){
	for( Local_u8COLIterator=0;Local_u8COLIterator<COl_NUM;Local_u8COLIterator++){

		GPIO_voidSetPinValue(COLPORT,Local_COLSArray[Local_u8COLIterator],GPIO_OUTPUT_LOW);
		for( Local_u8ROWSIteraror=0;Local_u8ROWSIteraror<Row_NUM;Local_u8ROWSIteraror++){
			// Assign binaries value of first element of the input array to the rows pins with order
			GPIO_voidSetPinValue(ROWPORT,Local_RowsArray[Local_u8ROWSIteraror],GET_BIT(Copy_au8PatternArray[Local_u8COLIterator],Local_u8ROWSIteraror));


		}
		STK_voidDelaySYNC(2500);
		LEDMATRIX_voidOff();
	}

	}
}
void LEDMATRIX_voidOff(){
	u8 Local_u8Iteraror;
	for(Local_u8Iteraror=0;Local_u8Iteraror<8;Local_u8Iteraror++){
		// set all col high to deactive them
		GPIO_voidSetPinValue(COLPORT,Local_COLSArray[Local_u8Iteraror],GPIO_OUTPUT_HIGH);
		// set all rows low to make led off
		GPIO_voidSetPinValue(ROWPORT,Local_RowsArray[Local_u8Iteraror],GPIO_OUTPUT_LOW);

	}

}
