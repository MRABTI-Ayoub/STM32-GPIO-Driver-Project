/*
 * STM32F4xx.h
 *
 *  Created on: Oct 7, 2025
 *      Author: MRABTI Ayoub
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_
#include <stdio.h>

# define _VO volatile
#define BASEADD_FALASH 			 0x08000000U
#define BASEADD_SRAM1  			 0x20000000
#define BASEADD_SRAM2  			 0x2001C000U
#define BASEADD_SRAM3 		     0x20020000U
#define BASEADD_ROM   		     0x1FFF0000U


#define BASEADD_RCC             0x40023800U

#define BASEADD_AHB3 			0xA0000000U
#define BASEADD_AHB2 			0x50000000U
#define BASEADD_AHB1		    0x40020000U
#define BASEADD_APB2			0x40010000U
#define BASEADD_APB1 			0x40000000U


#define BASEADD_GPIO_A 			0x40020000U
#define BASEADD_GPIO_B 			(BASEADD_GPIO_A+0x0400)
#define BASEADD_GPIO_C 			(BASEADD_GPIO_B +0x0400)
#define BASEADD_GPIO_D 			(BASEADD_GPIO_C +0x0400)
#define BASEADD_GPIO_E 			(BASEADD_GPIO_D +0x0400)
#define BASEADD_GPIO_F 			(BASEADD_GPIO_E +0x0400)
#define BASEADD_GPIO_G 			(BASEADD_GPIO_F +0x0400)
#define BASEADD_GPIO_I 			(BASEADD_GPIO_G +0x0400)

#define BASEADD_TIM14			0x40002000U
#define BASEADD_TIM13			0x40001C00U
#define BASEADD_TIM12			0x40001800U
#define BASEADD_TIM11			0x40014800U
#define BASEADD_TIM10			0x40014400U
#define BASEADD_TIM9			0x40014000U
#define BASEADD_TIM8			0x40013C00U
#define BASEADD_TIM7			0x40001400U
#define BASEADD_TIM6		    0x40001000U
#define BASEADD_TIM5		    0x40000C00U
#define BASEADD_TIM4			0x40000800U
#define BASEADD_TIM3			0x40000400U
#define BASEADD_TIM2			0x40000000U
#define BASEADD_TIM1			0x40010000U

#define UART5  					0x40005000U
#define UART4					0x40004C00U


#define USART6  			  0x40011400U
#define USART3  			  0x40004800U
#define USART2                0x40004400U
#define USART1                0x40011000U


#define BASEADD_DMA1 			0x40026000U
#define BASEADD_DMA1 			BASEADD_DMA1+0x0400



typedef struct
{
	_VO uint8_t MODER ;
	_VO uint8_t OSPEEDR ;
	_VO uint8_t PUPDR ;
	_VO uint8_t IDR ;
	_VO uint8_t ODR ;
	_VO uint8_t BSRR ;
	_VO uint8_t LCKR ;
	_VO uint8_t AFRL ;
	_VO uint8_t AFRH ;

}GPIO_REG;

typedef struct
{
	_VO uint8_t CR ;
	_VO uint8_t PLLCFGR ;
	_VO uint8_t CFGR ;
	_VO uint8_t CIR ;
	_VO uint8_t AHB1RSTR ;
	_VO uint8_t AHB2RSTR ;
	_VO uint8_t AHB3RSTR ;
	_VO uint8_t APB1RSTR ;
	_VO uint8_t APB2RSTR ;
	_VO uint8_t AHB1ENR ;
	_VO uint8_t AHB2ENR ;
	_VO uint8_t AHB3ENR ;
	_VO uint8_t APB1ENR ;
	_VO uint8_t APB2ENR ;
	_VO uint8_t AHB1LPENR ;
	_VO uint8_t AHB2LPENR ;
	_VO uint8_t AHB3LPENR ;
	_VO uint8_t APB1LPENR ;
	_VO uint8_t APB2LPENR ;
	_VO uint8_t BDCR ;
	_VO uint8_t CSR ;
	_VO uint8_t SSCGR ;
	_VO uint8_t PLLI2SCFGR ;
	_VO uint8_t PLLSAICFGR ;
	_VO uint8_t DCKCFGR ;

}RCC_REG;
#define RCC ((RCC_REG*)BASEADD_RCC)
#define reset 0
#define SEt   1
#define ENABLE 1
#define DESABLE 0
/* enable GPIO*/
#define GPIOA_PCLK_ENA ()			(CRC->AHB1EN|=(1<<0))
#endif /* INC_STM32F4XX_H_ */
