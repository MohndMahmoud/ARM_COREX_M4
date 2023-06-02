/*
 * SSD_interface.h
 *
 *  Created on: May 13, 2023
 *      Author: mohnd
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_
/*SSD PIN Configurations*/
#define SSD_PORT GPIO_PORTA
#define SSD_PINS_START    0
#define SSD_PINS_END      7
#define SSD_COM_CATHOD    1
#define SSD_COM_ANODE     2
/*Com CATHOD NUM */
#define SSDcathod_0  0x3F
#define SSDcathod_1  0x06
#define SSDcathod_2  0x5B
#define SSDcathod_3  0x4F
#define SSDcathod_4  0x66
#define SSDcathod_5  0x6D
#define SSDcathod_6  0x7D
#define SSDcathod_7  0x07
#define SSDcathod_8  0x7F
#define SSDcathod_9  0x6F

void SSD_voidInit(u8 Copy_SSDPort,u8 Copy_u8SSDStartPins,u8 Copy_u8SSDEndPins);
void SSD_voidDisplay(u8 Copy_COM,u8 Copy_SSDPort,u8 Copy_u8SSDStartPins,u8 Copy_u8SSDEndPins,u8 Copy_u8Value);
void SSD_voidOF(u8 Copy_COM,u8 Copy_SSDPort,u8 Copy_u8SSDEndPins);
#endif /* HAL_SSD_SSD_INTERFACE_H_ */
