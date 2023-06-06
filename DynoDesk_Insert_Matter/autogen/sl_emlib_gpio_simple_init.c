#include "sl_emlib_gpio_simple_init.h"
#include "sl_emlib_gpio_init_CLC_config.h"
#include "sl_emlib_gpio_init_Data_Ready_config.h"
#include "sl_emlib_gpio_init_Read_Data_config.h"
#include "em_gpio.h"
#include "em_cmu.h"

void sl_emlib_gpio_simple_init(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_CLC_PORT,
                  SL_EMLIB_GPIO_INIT_CLC_PIN,
                  SL_EMLIB_GPIO_INIT_CLC_MODE,
                  SL_EMLIB_GPIO_INIT_CLC_DOUT);

  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_DATA_READY_PORT,
                  SL_EMLIB_GPIO_INIT_DATA_READY_PIN,
                  SL_EMLIB_GPIO_INIT_DATA_READY_MODE,
                  SL_EMLIB_GPIO_INIT_DATA_READY_DOUT);

  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_READ_DATA_PORT,
                  SL_EMLIB_GPIO_INIT_READ_DATA_PIN,
                  SL_EMLIB_GPIO_INIT_READ_DATA_MODE,
                  SL_EMLIB_GPIO_INIT_READ_DATA_DOUT);
}
