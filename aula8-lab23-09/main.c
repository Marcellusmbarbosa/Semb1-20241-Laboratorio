#include <stdlib.h>
#include <stdint.h>

#include "stm32f411_gpio.h"
#include "stm32f411_rcc.h"

#include "app.h"
#include "bsp.h"

 /****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: main
 ****************************************************************************/

int main(int argc, char *argv[])
{
  uint32_t reg;

  uint32_t configset;

  uint32_t *pRCC_

  bsp_init();
  /*configura pc13 como saida OD pull-up off e pull-down off*/

  configset = (GPIO_PIN13 | GPIO_PORTC | GPIO_OUTPUT | GPIO_OPENDRAIN | GPIO_FLOAT);

  /* Executa funcao setup() API do ARDUINO */

  setup();

  while(1)
    {
      loop();
    }

  /* Nao deveria chegar aqui */

  return EXIT_SUCCESS;
}