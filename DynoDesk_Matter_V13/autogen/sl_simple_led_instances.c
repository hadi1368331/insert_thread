/***************************************************************************//**
 * @file
 * @brief LED Driver Instances
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.  This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "sl_simple_led.h"
#include "em_gpio.h"
#include "sl_simple_led_LEDGreen_config.h"
#include "sl_simple_led_LEDRed_config.h"

sl_simple_led_context_t simple_ledgreen_context = {
  .port = SL_SIMPLE_LED_LEDGREEN_PORT,
  .pin = SL_SIMPLE_LED_LEDGREEN_PIN,
  .polarity = SL_SIMPLE_LED_LEDGREEN_POLARITY,
};

const sl_led_t sl_led_ledgreen = {
  .context = &simple_ledgreen_context,
  .init = sl_simple_led_init,
  .turn_on = sl_simple_led_turn_on,
  .turn_off = sl_simple_led_turn_off,
  .toggle = sl_simple_led_toggle,
  .get_state = sl_simple_led_get_state,
};
sl_simple_led_context_t simple_ledred_context = {
  .port = SL_SIMPLE_LED_LEDRED_PORT,
  .pin = SL_SIMPLE_LED_LEDRED_PIN,
  .polarity = SL_SIMPLE_LED_LEDRED_POLARITY,
};

const sl_led_t sl_led_ledred = {
  .context = &simple_ledred_context,
  .init = sl_simple_led_init,
  .turn_on = sl_simple_led_turn_on,
  .turn_off = sl_simple_led_turn_off,
  .toggle = sl_simple_led_toggle,
  .get_state = sl_simple_led_get_state,
};

const sl_led_t *sl_simple_led_array[] = {
  &sl_led_ledgreen,
  &sl_led_ledred
};

void sl_simple_led_init_instances(void)
{
  sl_led_init(&sl_led_ledgreen);
  sl_led_init(&sl_led_ledred);
}
