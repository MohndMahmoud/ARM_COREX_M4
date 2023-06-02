#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
/*******************************interfacing macros*******************************
 *control difrant buses*********************************************************/
#define RCC_AHB1    1
#define RCC_AHB2    2
#define RCC_APB1    3
#define RCC_APB2    4

/*                         peripheral connected on AHB1                           */
// GPIO:
#define GPIOAEN     0 // this macro to define GPIO port a enable bit.
#define GPIOBEN     1   // this macro to define GPIO port b enable bit.
#define GPIOCEN     2// this macro to define GPIO port c enable bit.
#define GPIODEN     3// this macro to define GPIO port d enable bit.
#define GPIOEEN     4// this macro to define GPIO port e enable bit.
#define GPIOHEN     7// this macro to define GPIO port H clock enable bit.

/*********************************************************************************/
//CRC:
#define CRCEN       12


/*********************************************************************************/


//DMA:
#define DMA1        21
#define DMA2        22

/*********************************************************************************/


/*                           peripheral connected on AHB2                         */

//OTG FS:
#define OTGFSEN     7

/*********************************************************************************/

/*                            peripheral connected on APB1                        */


//TIMERS:
#define TIM2EN     0  // timer 2 clock enable
#define TIM3EN     1  // timer 3 clock enable
#define TIM4EN     2  // timer 4 clock enable
#define TIM5EN     3  // timer 5 clock enable


/*********************************************************************************/

// WWDOG:
#define  WWDGEN    11 // window watch dog timer clock  enable

/*********************************************************************************/
//SPI :
#define SPI2EN     14
#define SPI3EN     15


/*********************************************************************************/
// UART:
#define  UART2EN   17

/*********************************************************************************/
// I2C :

#define I2C1EN     21
#define I2C2EN     22
#define I2C3EN     23

/*********************************************************************************/
// PWR:
#define PWREN      28


/*                           peripheral connected on APB2                         */

// TIMER:
#define TIM1EN      0
#define TIM9EN      16
#define TIM10EN     17
#define TIM11EN     18

/*********************************************************************************/
// UART:
#define UART1EN     4
#define UART6EN     5

/*********************************************************************************/
//ADC:
#define ADC1        8

/*********************************************************************************/
//SDIO:
#define SDIOEN     11

/*********************************************************************************/
// SPI:
#define SPI1EN     12

#define SPI4En     13

/*********************************************************************************/
//SYSCFGEN:
#define SYSCFGEN   14

/*********************************************************************************/

u8 RCC_u8enablePrepheralClock(u8 Copy_u8BUS_ID,u8 Copy_u8Peripheral_ID);
u8 RCC_u8DisablePrepheralClock(u8 Copy_u8BUS_ID,u8 Copy_u8Peripheral_ID);
void RCC_voidSetSystemClock(void);


#endif
