#include "GPIO_DRIVER.h"
#include "STM32F407xx.h"  // assume CMSIS-like defines (GPIOA, NVIC_...)

/*
  Implémentation basique (register-level).
*/

void GPIO_PER_Cont(GPIO_REG *pGPIOx, uint8_t ENorDI)
{
    if (ENorDI == ENABLE)
    {
        if (pGPIOx == GPIOA) GPIOA_PCLK_ENA();
        else if (pGPIOx == GPIOB) GPIOB_PCLK_ENA();
        else if (pGPIOx == GPIOC) GPIOC_PCLK_ENA();
        else if (pGPIOx == GPIOD) GPIOD_PCLK_ENA();
        else if (pGPIOx == GPIOE) GPIOE_PCLK_ENA();
        else if (pGPIOx == GPIOF) GPIOF_PCLK_ENA();
        else if (pGPIOx == GPIOG) GPIOG_PCLK_ENA();
        else if (pGPIOx == GPIOH) GPIOH_PCLK_ENA();
        else if (pGPIOx == GPIOI) GPIOI_PCLK_ENA();
    }
    else /* DISABLE */
    {
        if (pGPIOx == GPIOA) GPIOA_PCLK_DIS();
        else if (pGPIOx == GPIOB) GPIOB_PCLK_DIS();
        else if (pGPIOx == GPIOC) GPIOC_PCLK_DIS();
        else if (pGPIOx == GPIOD) GPIOD_PCLK_DIS();
        else if (pGPIOx == GPIOE) GPIOE_PCLK_DIS();
        else if (pGPIOx == GPIOF) GPIOF_PCLK_DIS();
        else if (pGPIOx == GPIOG) GPIOG_PCLK_DIS();
        else if (pGPIOx == GPIOH) GPIOH_PCLK_DIS();
        else if (pGPIOx == GPIOI) GPIOI_PCLK_DIS();
    }
}

void GPIO_Init(GPIO_HANDLE *pGPIOHandle)
{
    uint32_t pinpos = pGPIOHandle->GPIO_PIN_CON.PIN_NUM;
    GPIO_REG *pGPIOx = pGPIOHandle->pGPIOx;
    uint32_t temp , temp1 , temp2;

    /*  MODE (MODER: 2 bits/pin) */
    pGPIOx->MODER &= ~(0x3u << (2 * pinpos));  // clear
    temp = (pGPIOHandle->GPIO_PIN_CON.PIN_MODE & 0x3u) << (2 * pinpos);
    pGPIOx->MODER |= temp;

    /*  OUTPUT TYPE (OTYPER: 1 bit/pin) */
    pGPIOx->OTYPER &= ~(0x1u << pinpos);
    pGPIOx->OTYPER |= ((pGPIOHandle->GPIO_PIN_CON.PIN_OP_TYPE & 0x1u) << pinpos);

    /*  SPEED (OSPEEDR: 2 bits/pin) */
    pGPIOx->OSPEEDR &= ~(0x3u << (2 * pinpos));
    temp = (pGPIOHandle->GPIO_PIN_CON.PIN_SPEED & 0x3u) << (2 * pinpos);
    pGPIOx->OSPEEDR |= temp;

    /*  PUPD (PUPDR: 2 bits/pin) */
    pGPIOx->PUPDR &= ~(0x3u << (2 * pinpos));
    temp = (pGPIOHandle->GPIO_PIN_CON.PIN_PUP_Control & 0x3u) << (2 * pinpos);
    pGPIOx->PUPDR |= temp;
if (pGPIOHandle->GPIO_PIN_CON.PIN_NUM == GPIO_Alternate_MODE)
{
temp1= pGPIOHandle->GPIO_PIN_CON.PIN_NUM / 8 ;
temp2= pGPIOHandle->GPIO_PIN_CON.PIN_NUM % 8 ;
pGPIOHandle->pGPIOx->AFR[temp1] |=(pGPIOHandle->GPIO_PIN_CON.GPIO_Alternate_MODE)<<(2*GPIO_PIN_CON.PIN_NUM));
pGPIOHandle ->pGPIOx->MODER =~(0x3 << pGPIOHandle-> GPIO_PIN_CON.PIN_NUM ); //clear

pGPIOHandle ->pGPIOx->MODER =|temp; //set
}
else
{

}
}

void GPIO_DeInit(GPIO_REG *pGPIOx)
{
    if (pGPIOx == GPIOA) { RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0); }
    else if (pGPIOx == GPIOB) { RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1); }
    else if (pGPIOx == GPIOC) { RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2); }
    else if (pGPIOx == GPIOD) { RCC->AHB1RSTR |= (1 << 3); RCC->AHB1RSTR &= ~(1 << 3); }
    else if (pGPIOx == GPIOE) { RCC->AHB1RSTR |= (1 << 4); RCC->AHB1RSTR &= ~(1 << 4); }
    else if (pGPIOx == GPIOF) { RCC->AHB1RSTR |= (1 << 5); RCC->AHB1RSTR &= ~(1 << 5); }
    else if (pGPIOx == GPIOG) { RCC->AHB1RSTR |= (1 << 6); RCC->AHB1RSTR &= ~(1 << 6); }
    else if (pGPIOx == GPIOH) { RCC->AHB1RSTR |= (1 << 7); RCC->AHB1RSTR &= ~(1 << 7); }
    else if (pGPIOx == GPIOI) { RCC->AHB1RSTR |= (1 << 8); RCC->AHB1RSTR &= ~(1 << 8); }
}

/* Ecrire un pin: utilise BSRR pour set/reset atomique */
void GPIO_WRITE_PIN(GPIO_REG *pGPIOx, uint8_t Pin_num, uint8_t Value)
{
    if (Value)
        pGPIOx->BSRR = (1u << Pin_num);            // set bit
    else
        pGPIOx->BSRR = (1u << (Pin_num + 16));    // reset bit
}

/* Ecrire tout le port (valeur 16 bits) */
void GPIO_WRITE_PORT(GPIO_REG *pGPIOx, uint16_t Value)
{
    pGPIOx->ODR = (uint32_t)Value;
}

/* Toggle : XOR sur ODR */
void GPIO_Toggel_OUT(GPIO_REG *pGPIOx, uint8_t Pin_num)
{
    pGPIOx->ODR ^= (1u << Pin_num);
}

/* Lecture d'un pin */
uint8_t GPIO_READ_PIN(GPIO_REG *pGPIOx, uint8_t Pin_num)
{
    return (uint8_t)((pGPIOx->IDR >> Pin_num) & 0x1u);
}

/* Lecture port */
uint8_t GPIO_READ_PORT(GPIO_REG *pGPIOx)
{
    return (uint8_t)(pGPIOx->IDR & 0xFFu); // retourne les 8 LSB, adapte si 16 bits voulu
}

/* NVIC IRQ config (utilise CMSIS si dispo) */
void IRQ_CONF(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI)
{
    if (ENorDI == ENABLE)
    {
        NVIC_EnableIRQ((IRQn_Type)IRQNumber);
        NVIC_SetPriority((IRQn_Type)IRQNumber, IRQPriority);
    }
    else
    {
        NVIC_DisableIRQ((IRQn_Type)IRQNumber);
    }
}

/* Handler générique EXTI : efface le flag EXTI (exemple pour pin X)
   (à personnaliser selon l'EXTI et ta logique) */
void IRQ_HANDLING(void)
{
    /* Exemple : si EXTI0 flag (PR bit) est set, clear it */
    if (EXTI->PR & (1u << 0))
    {
        EXTI->PR |= (1u << 0); // écrire 1 pour effacer
    }
}
