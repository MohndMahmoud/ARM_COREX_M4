/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Zyad Ahmed	   		******************/
/******************			File Name: RCC_program.c        ******************/
/******************								     	    ******************/
/*****************************************************************************/
/*****************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"

#include "KPD_private.h"

/*this function should initialize the keypad*/
void KPD_voidInit(void)
{
	GPIO_voidInitInputPin(KPD_PORT, KPD_ROW0, GPIO_PULL_UP);
	GPIO_voidInitInputPin(KPD_PORT, KPD_ROW1, GPIO_PULL_UP);
	GPIO_voidInitInputPin(KPD_PORT, KPD_ROW2, GPIO_PULL_UP);
	GPIO_voidInitInputPin(KPD_PORT, KPD_ROW3, GPIO_PULL_UP);

GPIO_voidInitOutputPin(KPD_PORT, KPD_COL0, GPIO_PUSH_PULL, GPIO_LOW_SPEED);
GPIO_voidSetPinValue(KPD_PORT, KPD_COL0, GPIO_OUTPUT_HIGH);
	GPIO_voidInitOutputPin(KPD_PORT, KPD_COL1, GPIO_PUSH_PULL, GPIO_LOW_SPEED);
	GPIO_voidSetPinValue(KPD_PORT, KPD_COL1, GPIO_OUTPUT_HIGH);
	GPIO_voidInitOutputPin(KPD_PORT, KPD_COL2, GPIO_PUSH_PULL, GPIO_LOW_SPEED);
	GPIO_voidSetPinValue(KPD_PORT, KPD_COL2, GPIO_OUTPUT_HIGH);
	GPIO_voidInitOutputPin(KPD_PORT, KPD_COL3, GPIO_PUSH_PULL, GPIO_LOW_SPEED);
	GPIO_voidSetPinValue(KPD_PORT, KPD_COL3, GPIO_OUTPUT_HIGH);
}

u8 KPD_u8GetValue(void)
{
	u8 Local_u8RowIterator;
	u8 Local_u8ColIterator;

	u8 Local_u8State;
	u8 Local_u8Var = KPD_STATE;

	u8 Local_au8Col[COL_NUM] = {KPD_COL0, KPD_COL1, KPD_COL2, KPD_COL3};

	u8 Local_au8Row[ROW_NUM] = {KPD_ROW0, KPD_ROW1, KPD_ROW2, KPD_ROW3};

	u8 Local_au8KPD[COL_NUM][ROW_NUM] = KPD_ARR

			for(Local_u8ColIterator= 0 ; Local_u8ColIterator < COL_NUM; Local_u8ColIterator++)
			{
				GPIO_voidSetPinValue(KPD_PORT, Local_au8Col[Local_u8ColIterator], GPIO_OUTPUT_LOW);

				for(Local_u8RowIterator = 0; Local_u8RowIterator < ROW_NUM; Local_u8RowIterator++)
				{
					Local_u8State = GPIO_u8GetPinValue(KPD_PORT, Local_au8Row[Local_u8RowIterator]);

					if (Local_u8State == 0)
					{
						Local_u8Var = Local_au8KPD[Local_u8ColIterator][Local_u8RowIterator];

						while (Local_u8State == 0)
						{
							Local_u8State = GPIO_u8GetPinValue(KPD_PORT, Local_au8Row[Local_u8RowIterator]);
						}

						return Local_u8Var;
					}
				}
				GPIO_voidSetPinValue(KPD_PORT, Local_au8Col[Local_u8ColIterator], GPIO_OUTPUT_HIGH);
			}
	return Local_u8Var;

}
