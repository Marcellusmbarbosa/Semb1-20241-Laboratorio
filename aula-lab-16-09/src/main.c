#include <stdlib.h>

#include "config.h"


int main (int argc, char *argv[]) 
{
  uint32_t reg;
  uint32_t *pReg;

  uint32_t *pRCC_AH = (uint32_t *)STM32_RCC_AHB1;
  reg = *pRCC_AHB1ENR;
  reg |= RCC_AHB1ENR_GPIOAEN; // reg = reg | (1 << 2)
  *pRCC_AHB1ENR = reg;

  /* Configura PC13 como saida OD pull-down off e pull-up off*/

  pReg = (uint32_t *)STM32_GPIOC_AHB1ENR;
  reg = *pReg;
  reg &= ~(GPIO_MODER_MASK(13)); // reg = reg & ~(3 << 26)
  reg |= (GPIO_MODER_OUTPUT << GPIO_MODER_SHIFT(13)); // reg = reg
  *pReg = reg;

  pReg = (uint32_t *)STM32_GPIOC_OTYPER;
  pReg = *pReg;
  reg |= (GPIO_OTYPER_OD << GPIO_OT_SHIFT(13));
  *pReg = reg;

  pReg = (uint32_t *)STM32_GPIOC_PUPDR;
  reg = *pReg;
  reg &= ~(GPIO_PUPDR_MASK(13)); // reg = reg & ~(3 << 26)
  reg |= (GPIO_PUPDR_NONE << GPIO_PUPDR_SHIFT(13)); // reg = reg
  *pReg = reg;

  pReg = (uint32_t *)STM32_GPIOC_BSRR;


  while (1)
  {
    /* LED on */
    *pReg = GPIO_BSRR_RESET(13);
    for (int i = 0; i< 50000; i++);

    /* LED off */

    *pReg = GPIO_BSRR_SET(13);
    for (int i = 0; i< 50000; i++);

  }
  return EXIT_SUCCESS;
}