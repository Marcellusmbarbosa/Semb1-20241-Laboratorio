#include <stdint.h>
#include <stdlib.h>

#define STM32_RCC_BASE       0x40023800     /* 0x40023800-0x40023bff: Reset and Clock control RCC */

/* Register Offsets *********************************************************/

#define STM32_RCC_AHB1ENR_OFFSET  0x0030   /* AHB1 Peripheral Clock enable register */

#define RCC_AHB1ENR_GPIOCEN      (1 << 2)  /* Bit 2:  IO port C clock enable */

int main (int argc, char *argv[]) 
{

  uint32_t reg;

  uint32_t *pRCC_AHB1ENR = (uint32_t *) (STM32_RCC_AHB1ENR);
  reg = *pRCC_AHB1ENR;
  reg |= RCC_AHB1ENR_GPIOCEN; //reg = reg | (1 << 2);
  *pRCC_AHB1ENR = reg;


  while (1)
  {};

    /* Não deveria chegar aqui */

  return EXIT_SUCCESS;
}