/***************************************************************************//**
 * @file
 * @brief Bluetooth side channel implementation example
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "sl_bluetooth.h"
#include "gatt_db.h"
#include "app_side_channel.h"
#include "HAP.h"

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
void app_side_channel_init(void)
{
  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application init code here!                         //
  // This is called once during start-up.                                    //
  /////////////////////////////////////////////////////////////////////////////
}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
void app_side_channel_process_action(void)
{
  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application code here!                              //
  // This is called infinitely.                                              //
  // Do not call blocking functions from here!                               //
  /////////////////////////////////////////////////////////////////////////////
}

// The side channel requires at least one extra connection and advertiser
// besides the ones used by the Homekit protocol.
#if (SL_BT_CONFIG_MAX_CONNECTIONS_SUM > 1) && (SL_BT_CONFIG_MAX_ADVERTISERS > 1)

#define ADVERTISING_DATA   { 0x02, 0x01, 0x06, 0x05, 0x09, 'T', 'e', 's', 't' }
#define INVALID_HANDLE     0xff

// The advertising set handle allocated from Bluetooth stack
static uint8_t advertising_set_handle = INVALID_HANDLE;

// Connection handle used by the side channel
static uint8_t conn_handle = INVALID_HANDLE;

// HAP log object and helper macros
static const HAPLogObject logObject = { .subsystem = kHAPPlatform_LogSubsystem, .category = "SideChannel" };

#define app_assert(cond, ...)               \
  do {                                      \
    if (!(cond)) {                          \
      HAPLogError(&logObject, __VA_ARGS__); \
      HAPFatalError();                      \
    }                                       \
  } while (0)

#define app_log(...)   HAPLogInfo(&logObject, __VA_ARGS__)

/**************************************************************************//**
 * Filter events based on connection handle.
 *****************************************************************************/
static bool connection_filter(sl_bt_msg_t* evt)
{
  bool ret = true;

  switch (SL_BT_MSG_ID(evt->header)) {
    case sl_bt_evt_connection_opened_id:
      ret = evt->data.evt_connection_opened.advertiser == advertising_set_handle;
      if (ret) {
        app_assert(conn_handle == INVALID_HANDLE,
                   "Only one side channel connection supported!");
        // store connection handle
        conn_handle = evt->data.evt_connection_opened.connection;
      }
      break;
    case sl_bt_evt_connection_closed_id:
      ret = evt->data.evt_connection_closed.connection == conn_handle;
      if (ret) {
        // reset connection handle
        conn_handle = INVALID_HANDLE;
      }
      break;
    case sl_bt_evt_gatt_server_user_read_request_id:
      ret = evt->data.evt_gatt_server_user_read_request.connection == conn_handle;
      break;
    case sl_bt_evt_gatt_server_user_write_request_id:
      ret = evt->data.evt_gatt_server_user_write_request.connection == conn_handle;
      break;
    case sl_bt_evt_gatt_server_characteristic_status_id:
      ret = evt->data.evt_gatt_server_characteristic_status.connection == conn_handle;
      break;
    ///////////////////////////////////////////////////////////////////////////
    // Add additional events here as your application requires!              //
    ///////////////////////////////////////////////////////////////////////////
    default:
      // Let's use the default return value, nothing to do
      break;
  }

  return ret;
}

/**************************************************************************//**
 * Bluetooth side channel event handler.
 * This overrides the dummy weak implementation.
 *****************************************************************************/
void sl_bt_on_event(sl_bt_msg_t* evt)
{
  sl_status_t sc;

  // Filter for side channel events
  if (!connection_filter(evt)) {
    return;
  }

  // Handle stack events
  switch (SL_BT_MSG_ID(evt->header)) {
    ///////////////////////////////////////////////////////////////////////////
    // This event indicates the device has started and the radio is ready.   //
    // Do not call any stack command before receiving this boot event!       //
    ///////////////////////////////////////////////////////////////////////////
    case sl_bt_evt_system_boot_id:
    {
      uint8_t advertising_data_frame[] = ADVERTISING_DATA;
      bd_addr random_address;

      // Create an advertising set.
      sc = sl_bt_advertiser_create_set(&advertising_set_handle);
      app_assert(sc == SL_STATUS_OK,
                 "sl_bt_advertiser_create_set failed: 0x%04x",
                 (int)sc);

      // Set private resolvable random address,
      // remove this code if you want to use public (identity) address - used by default
      sc = sl_bt_advertiser_set_random_address(advertising_set_handle,
                                               2,
                                               random_address,
                                               &random_address);
      app_assert(sc == SL_STATUS_OK,
                 "sl_bt_advertiser_set_random_address failed: 0x%04x",
                 (int)sc);
      app_log("Bluetooth address: %02X:%02X:%02X:%02X:%02X:%02X\n",
              random_address.addr[5],
              random_address.addr[4],
              random_address.addr[3],
              random_address.addr[2],
              random_address.addr[1],
              random_address.addr[0]);

      // Set advertising data
      sc = sl_bt_advertiser_set_data(advertising_set_handle,
                                     0,
                                     sizeof(advertising_data_frame),
                                     advertising_data_frame);
      app_assert(sc == SL_STATUS_OK,
                 "sl_bt_advertiser_set_data failed: 0x%04x",
                 (int)sc);

      // Set advertising interval to 100 ms
      sc = sl_bt_advertiser_set_timing(advertising_set_handle,
                                       160,
                                       160,
                                       0,
                                       0);
      app_assert(sc == SL_STATUS_OK,
                 "sl_bt_advertiser_set_timing failed: 0x%04x",
                 (int)sc);

      // Start advertising
      sc = sl_bt_advertiser_start(advertising_set_handle,
                                  advertiser_user_data,
                                  advertiser_connectable_scannable);
      app_assert(sc == SL_STATUS_OK,
                 "sl_bt_advertiser_start failed: 0x%04x",
                 (int)sc);
      break;
    }

    ///////////////////////////////////////////////////////////////////////////
    // This event indicates that a new connection was opened.                //
    ///////////////////////////////////////////////////////////////////////////
    case sl_bt_evt_connection_opened_id:
      app_log("sl_bt_evt_connection_opened_id: 0x%02x",
              evt->data.evt_connection_opened.connection);
      break;

    ///////////////////////////////////////////////////////////////////////////
    // This event indicates that a connection was closed.                    //
    ///////////////////////////////////////////////////////////////////////////
    case sl_bt_evt_connection_closed_id:
      app_log("sl_bt_evt_connection_closed_id: 0x%04x",
              evt->data.evt_connection_closed.reason);

      // Start advertising
      sc = sl_bt_advertiser_start(advertising_set_handle,
                                  advertiser_user_data,
                                  advertiser_connectable_scannable);
      app_assert(sc == SL_STATUS_OK,
                 "sl_bt_advertiser_start failed: 0x%04x",
                 (int)sc);

      break;

    ///////////////////////////////////////////////////////////////////////////
    // Add additional event handlers here as your application requires!      //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Default event handler.                                                //
    ///////////////////////////////////////////////////////////////////////////
    default:
      break;
  }
}

#endif
