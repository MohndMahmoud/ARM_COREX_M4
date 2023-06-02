/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Zyad Ahmed	   		******************/
/******************			File Name: RCC_config.h         ******************/
/******************								     	    ******************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef _KPD_CONFIG_H_
#define _KPD_CONFIG_H_
/***********************************************************************************/
/************************************ Macros **************************************/
/*********************************************************************************/

/*they port that connected to the keypad*/
/*available configuration : DIO_PORTA  DIO_PORTB  DIO_PORTC  DIO_PORTD*/
#define KPD_PORT     GPIO_PORTA


#define KPD_ROW0     GPIO_PIN4
#define KPD_ROW1     GPIO_PIN5
#define KPD_ROW2     GPIO_PIN6
#define KPD_ROW3     GPIO_PIN7



#define KPD_COL0     GPIO_PIN0
#define KPD_COL1     GPIO_PIN1
#define KPD_COL2     GPIO_PIN2
#define KPD_COL3     GPIO_PIN3

#define ROW_NUM     4
#define COL_NUM     4

#define KPD_STATE   1

#define KPD_COL     {DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7};

#define KPD_ARR    {{'A', 'B', 'C', 'D'}   \
                   ,{'E', 'F', 'G', 'H'},  \
					{'I', 'J', 'K', 'L'},  \
					{'M', 'N', 'O', 'P'}}; \

#endif
