#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_
#include <stdio.h>
#include "STM32F407xx.h"

#define GPIO_INPUT_MODE 0X00
#define GPIO_OUTPUT_MODE 0X01
#define GPIO_Alternate_MODE 0X10
#define GPIO_ANALOG_MODE 0X11
#define  GPIO_IT_MODE_FT 0X0100
#define  GPIO_IT_MODE_RT 0X0101
#define  GPIO_IT_MODE_FRT 0X0110

#define No_pull 00
#define Pull-up 01
#define Pull_down 10
#define Low speed 00
#define Medium_speed 01
#define High_speed 10
#define Very_high_speed 11
#define Output_push_pull 00
#define Output_open_drain 01

typedef struct
{
	uint8_t PIN_NUM ;
	uint8_t PIN_MODE;
	uint8_t PIN_SPEED;
	uint8_t PIN_AL_FUN_MODE;
	uint8_t PIN_PUP_CONTRol;
	uint8_t PIN_OPTYPE;

}GPIO_PIN_CON;
typedef struct
{
	GPIO_REG *pGPIOx ;
	GPIO_PIN_CON pin_conf ;
}GPIO_HANDLE;



								/****** API*******/



void GPIO_PER_Cont( GPIO_REG *pGPIOx ,uint8_t ENorDI); /*peripherique enable clock */


void GPIO_Init(GPIO_HANDLE  *pGPIOHandle );
void GPIO_DeInit(GPIO_REG *pGPIOx );
void GPIO_WRITE_PIN(GPIO_REG *pGPIOx , uint8_t Pin_num ,uint8_t Value);
void GPIO_WRITE_PORT(GPIO_REG *pGPIOx , uint8_t Pin_num);
void GPIO_Toggel_OUT(GPIO_REG *pGPIOx , uint8_t Pin_num);
uint8_t GPIO_READ_PIN(GPIO_REG *pGPIOx , uint8_t Pin_num);
uint8_t GPIO_READ_PORT(GPIO_REG *pGPIOx );


void IRQ_CONF(uint8_t IRQNumbr , uint8_t IRQPriority , uint8_t ENorDI);
void IRQ_HANDLING(void);





#endif /* GPIO_DRIVER_H_ */
