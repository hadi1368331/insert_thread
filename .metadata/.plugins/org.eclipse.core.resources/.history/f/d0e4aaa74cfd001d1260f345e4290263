// Disclaimer: IMPORTANT: This Apple software is supplied to you, by Apple Inc. ("Apple"), in your
// capacity as a current, and in good standing, Licensee in the MFi Licensing Program. Use of this
// Apple software is governed by and subject to the terms and conditions of your MFi License,
// including, but not limited to, the restrictions specified in the provision entitled "Public
// Software", and is further subject to your agreement to the following additional terms, and your
// agreement that the use, installation, modification or redistribution of this Apple software
// constitutes acceptance of these additional terms. If you do not agree with these additional terms,
// you may not use, install, modify or redistribute this Apple software.
//
// Subject to all of these terms and in consideration of your agreement to abide by them, Apple grants
// you, for as long as you are a current and in good-standing MFi Licensee, a personal, non-exclusive
// license, under Apple's copyrights in this Apple software (the "Apple Software"), to use,
// reproduce, and modify the Apple Software in source form, and to use, reproduce, modify, and
// redistribute the Apple Software, with or without modifications, in binary form, in each of the
// foregoing cases to the extent necessary to develop and/or manufacture "Proposed Products" and
// "Licensed Products" in accordance with the terms of your MFi License. While you may not
// redistribute the Apple Software in source form, should you redistribute the Apple Software in binary
// form, you must retain this notice and the following text and disclaimers in all such redistributions
// of the Apple Software. Neither the name, trademarks, service marks, or logos of Apple Inc. may be
// used to endorse or promote products derived from the Apple Software without specific prior written
// permission from Apple. Except as expressly stated in this notice, no other rights or licenses,
// express or implied, are granted by Apple herein, including but not limited to any patent rights that
// may be infringed by your derivative works or by other works in which the Apple Software may be
// incorporated. Apple may terminate this license to the Apple Software by removing it from the list
// of Licensed Technology in the MFi License, or otherwise in accordance with the terms of such MFi License.
//
// Unless you explicitly state otherwise, if you provide any ideas, suggestions, recommendations, bug
// fixes or enhancements to Apple in connection with this software ("Feedback"), you hereby grant to
// Apple a non-exclusive, fully paid-up, perpetual, irrevocable, worldwide license to make, use,
// reproduce, incorporate, modify, display, perform, sell, make or have made derivative works of,
// distribute (directly or indirectly) and sublicense, such Feedback in connection with Apple products
// and services. Providing this Feedback is voluntary, but if you do provide Feedback to Apple, you
// acknowledge and agree that Apple may exercise the license granted above without the payment of
// royalties or further consideration to Participant.

// The Apple Software is provided by Apple on an "AS IS" basis. APPLE MAKES NO WARRANTIES, EXPRESS OR
// IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR
// IN COMBINATION WITH YOUR PRODUCTS.
//
// IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION
// AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
// (INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (C) 2015-2020 Apple Inc. All Rights Reserved.

// The most basic HomeKit example: an accessory that represents a light bulb that
// only supports switching the light on and off.
//
// This implementation can work for upto two LEDs and upto 4 buttons.
//
// To enable user interaction, buttons and LEDs on the development board are used:
//
// - LED 1 is used to simulate the light bulb.
// - LED 2, if available, is switched on during identify.
//
// - Button 1 or signal `SIGUSR1` to clear pairings.
// - Button 2 or signal `SIGUSR2` to trigger a factory reset.
// - Button 3 or signal `SIGTERM` to toggle the light bulb.
//
// The code consists of multiple parts:
//
//   1. The definition of the accessory configuration and its internal state.
//
//   2. Helper functions to load and save the state of the accessory.
//
//   3. The setup of the accessory HomeKit and the bridged accessories attribute database.
//
//   4. Device specific configuration, callbacks and LED switches.
//
//   5. Signal handlers.
//
//   6. The callbacks that implement the actual behavior of the accessory. If the
//      accessory state has changed, the corresponding device functions are called.
//
//   7. The initialization of the accessory state.
//
//   8. A callback that gets called when the server state is updated.

#include "HAP.h"

#include "HAPPlatform+Init.h"
#include "HAPPlatformAccessorySetup+Init.h"

#include "app.h"
#include "AppBase.h"
#include "AppLED.h"
#include "AppUserInput.h"
#include "AttributesDB.h"

#if (SILICON_LABS_HOMEKIT_OTA == 1)
#include "SiliconLabsHomekitOTA_handlers.h"
#endif




#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "em_adc.h"
#include "em_cmu.h"
#include "sl_bt_api.h"
#include "sl_sleeptimer.h"
#include "sl_status.h"
#include "em_pcnt.h"
#include "em_prs.h"
#include "uartdrv.h"
#include "sl_uartdrv_instances.h"
#include "em_chip.h"
#include "em_emu.h"
#include "em_cmu.h"
// Size of the buffer for received data
#define BUFLEN  254

// Receive data buffer
uint8_t UART_buffer[BUFLEN];

// Current position ins buffer
uint32_t inpos = 0;
uint32_t outpos = 0;

// True while receiving data (waiting for CR or BUFLEN characters)
bool receive = true;
bool ledstatus=false;
#define adcFreq   16000000
volatile uint32_t sample;
volatile uint32_t millivolts;
void formatNumberToString(uint8_t *dataOut, uint16_t value, uint8_t thenumber);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Key used in the key value store to store the configuration state.
 *
 * Purged: On factory reset.
 */
#define kAppKeyValueStoreKey_Configuration_State ((HAPPlatformKeyValueStoreKey) 0x00)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
    AppLEDIdentifier lightBulbPin;
    AppLEDIdentifier identifyPin;
} Device;

/**
 * Global accessory configuration.
 */
typedef struct {
    struct {
        bool lightBulbOn;
        int32_t brightness;
        float hue;
        float saturation;
        uint32_t colorTemperature;
    } state;
    struct {
        int32_t brightness;
    uint32_t colorTemperature;
    } prevNotificationValue;
    Device device;
    HAPPlatformTimerRef identifyTimer;
    HAPAccessoryServer* server;
    HAPPlatformKeyValueStoreRef keyValueStore;
} AccessoryConfiguration;

static AccessoryConfiguration accessoryConfiguration;

/**
 * Manufacturer data for accessory.
 */
static char serialNumber[SERIAL_NUMBER_MAX_SIZE];
static char productData[PRODUCT_DATA_MAX_SIZE];

#if (HAVE_ACCESSORY_REACHABILITY == 1)
HAPAccessoryReachabilityConfiguration accessoryReachabilityConfig = {
    .sleepIntervalInMs = kAccessorySleepInterval,
};
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------------------------------------

#if (HAVE_ADAPTIVE_LIGHT == 1)
static AdaptiveLightTransitionStorage adaptiveLightStorage;
#endif

/**
 * Initialize the default accessory state
 */
static void SetupDefaultAccessoryState(void) {
    HAPRawBufferZero(&accessoryConfiguration.state, sizeof accessoryConfiguration.state);
    accessoryConfiguration.state.brightness = 0;
    accessoryConfiguration.state.hue = 0.0F;
    accessoryConfiguration.state.saturation = 0.0F;
#if (HAVE_ADAPTIVE_LIGHT == 1)
    // Adaptive Light feature requires different range for Color Temperature
    accessoryConfiguration.state.colorTemperature = 166;
#else
    accessoryConfiguration.state.colorTemperature = 50;
#endif
    accessoryConfiguration.prevNotificationValue.colorTemperature = accessoryConfiguration.state.colorTemperature;
    accessoryConfiguration.prevNotificationValue.brightness = accessoryConfiguration.state.brightness;
}

//----------------------------------------------------------------------------------------------------------------------
/**
 * Init the accessory state for the lightBulb example
 */
static void InitAccessoryStateParameters(void)
{
    accessory.cameraStreamConfigurations = NULL;
#if (HAVE_ACCESSORY_REACHABILITY == 1)
    accessory.reachabilityConfiguration = &accessoryReachabilityConfig;
#endif
    accessory.callbacks.identify = IdentifyAccessory;
}

/**
 * Load the accessory state from persistent memory.
 */
static void LoadAccessoryState(void) {
    HAPPrecondition(accessoryConfiguration.keyValueStore);

    HAPError err;

    // Load persistent state if available
    bool found;
    size_t numBytes;

    err = HAPPlatformKeyValueStoreGet(
            accessoryConfiguration.keyValueStore,
            kAppKeyValueStoreDomain_Configuration,
            kAppKeyValueStoreKey_Configuration_State,
            &accessoryConfiguration.state,
            sizeof accessoryConfiguration.state,
            &numBytes,
            &found);

    if (err) {
        HAPAssert(err == kHAPError_Unknown);
        HAPFatalError();
    }
    if (!found || numBytes != sizeof accessoryConfiguration.state) {
        if (found) {
            HAPLogError(&kHAPLog_Default, "Unexpected app state found in key-value store. Resetting to default.");
        }
        InitAccessoryStateParameters();
        SetupDefaultAccessoryState();
    }
}

/**
 * Save the accessory state to persistent memory.
 */
static void SaveAccessoryState(void) {
    HAPPrecondition(accessoryConfiguration.keyValueStore);

    HAPError err;
    err = HAPPlatformKeyValueStoreSet(
            accessoryConfiguration.keyValueStore,
            kAppKeyValueStoreDomain_Configuration,
            kAppKeyValueStoreKey_Configuration_State,
            &accessoryConfiguration.state,
            sizeof accessoryConfiguration.state);
    if (err) {
        HAPAssert(err == kHAPError_Unknown);
        HAPFatalError();
    }
}

//----------------------------------------------------------------------------------------------------------------------
/**
 * Control duration of Identify indication.
 */
static void IdentifyTimerExpired(HAPPlatformTimerRef timer, void* _Nullable context) {
    HAPLogInfo(&kHAPLog_Default, "%s", __func__);

    HAPPrecondition(!context);
    HAPPrecondition(timer == accessoryConfiguration.identifyTimer);

    accessoryConfiguration.identifyTimer = 0;

    AppLEDSet(accessoryConfiguration.device.identifyPin, false);
}

/**
 * Performs the Identify routine.
 */
static void DeviceIdentify(void) {
    HAPError err;

    if (accessoryConfiguration.identifyTimer) {
        HAPPlatformTimerDeregister(accessoryConfiguration.identifyTimer);
        accessoryConfiguration.identifyTimer = 0;
    }
    err = HAPPlatformTimerRegister(
            &accessoryConfiguration.identifyTimer,
            HAPPlatformClockGetCurrent() + 3 * HAPSecond,
            IdentifyTimerExpired,
            NULL);
    if (err) {
        HAPAssert(err == kHAPError_OutOfResources);
        HAPFatalError();
    }

    AppLEDSet(accessoryConfiguration.device.identifyPin, true);
}

/**
 * Enable LED on the device
 */
static void DeviceEnableLED(AppLEDIdentifier pin) {
    HAPLogInfo(&kHAPLog_Default, "%s", __func__);
    AppLEDSet(pin, true);
}

/**
 * Disable LED on the device
 */
static void DeviceDisableLED(AppLEDIdentifier pin) {
    HAPLogInfo(&kHAPLog_Default, "%s", __func__);
    AppLEDSet(pin, false);
}

/**
 * Turn the light bulb on.
 */
static void TurnOnLightBulb(void) {
    DeviceEnableLED(accessoryConfiguration.device.lightBulbPin);
    uint8_t data[]="250:000";
    UARTDRV_TransmitB(sl_uartdrv_usart_Xmega_USART_handle,data,7);
}

/**
 * Turn the light bulb off.
 */
static void TurnOffLightBulb(void) {
    DeviceDisableLED(accessoryConfiguration.device.lightBulbPin);
    uint8_t data[]="150:000";
    UARTDRV_TransmitB(sl_uartdrv_usart_Xmega_USART_handle,data,7);
}

//----------------------------------------------------------------------------------------------------------------------
/**
 * Global user input handler.
 *
 * Button and signal mapping to kAppUserInputIdentifier can be found at Applications/Common/AppUserInput.h
 */
static void HandleUserInputEventCallback(void* _Nullable context, size_t contextSize) {
    HAPPrecondition(context);
    if (contextSize != sizeof(AppUserInputEvent)) {
        HAPFatalError();
    }

    HAPLogInfo(&kHAPLog_Default, "%s", __func__);

    AppUserInputEvent buttonEvent = *((AppUserInputEvent*) context);
    switch (buttonEvent.id)
    {
        case kAppUserInputIdentifier_3:
          { // SIGTERM or Button 3
//            switch(HAPPlatformAccessorySetupDisplayGetMenuPoz(accessoryConfiguration.server->platform.setupDisplay))
//            {
//                case 0:
//                    FactoryReset();
//                    break;
//                case 1:
//                    ClearPairings();
//                    break;
//                case 2:
//                    ToggleLightBulbState();
//                    break;
//                case 3:
//                    IncreaseBrightness();
//                    break;
//                case 4:
//                    DecreaseBrightness();
//                    break;
//                case 5:
//                    break;
//                case 6:
//                    break;
//                case 7:
//                    IncreaseSaturation();
//                    break;
//                case 8:
//                    DecreaseSaturation();
//                    break;
//                default:
//                  break;
//            }
//            ToggleLightBulbState();
            break;
        }
        default:
        {
            break;
        }
    }
}

/**
 * Unconfigure platform specific IO.
 */
static void UnconfigureIO(void) {
    HAPLogInfo(&kHAPLog_Default, "%s", __func__);

    AppLEDDeinit();
}

/**
 * Toggle the light bulb.
 */
void ToggleLightBulbState(void) {
    accessoryConfiguration.state.lightBulbOn = !accessoryConfiguration.state.lightBulbOn;

    HAPLogInfo(&kHAPLog_Default, "%s: %s", __func__, accessoryConfiguration.state.lightBulbOn ? "true" : "false");

    if (accessoryConfiguration.state.lightBulbOn) {
        TurnOnLightBulb();
    } else {
        TurnOffLightBulb();
    }

    SaveAccessoryState();

    HAPAccessoryServerRaiseEvent(
            accessoryConfiguration.server, &lightBulbOnCharacteristic, &DynoDesk_Light, &accessory);
}

/**
 * Increase Brightness of the light bulb.
 */
void IncreaseBrightness(void) {

  if (accessoryConfiguration.state.brightness == lightBulbBrightnessCharacteristic.constraints.maximumValue){
      return;
  }
  accessoryConfiguration.state.brightness += lightBulbBrightnessCharacteristic.constraints.stepValue;

  uint8_t data[]="400:000";
  formatNumberToString(data, (uint16_t) accessoryConfiguration.state.brightness, 4);
  UARTDRV_TransmitB(sl_uartdrv_usart_Xmega_USART_handle,data,7);
  SaveAccessoryState();
  HAPAccessoryServerRaiseEvent(
          accessoryConfiguration.server, &lightBulbBrightnessCharacteristic, &DynoDesk_Light, &accessory);
}

/**
 * Decrease Brightness of the light bulb.
 */
void DecreaseBrightness(void) {

  if (accessoryConfiguration.state.brightness == lightBulbBrightnessCharacteristic.constraints.minimumValue){
      return;
  }
  accessoryConfiguration.state.brightness -= lightBulbBrightnessCharacteristic.constraints.stepValue;
  uint8_t data[]="300:000";
  formatNumberToString(data, (uint16_t) accessoryConfiguration.state.brightness, 4);
  UARTDRV_TransmitB(sl_uartdrv_usart_Xmega_USART_handle,data,7);
  SaveAccessoryState();
  HAPAccessoryServerRaiseEvent(
          accessoryConfiguration.server, &lightBulbBrightnessCharacteristic, &DynoDesk_Light, &accessory);
}

/**
 * Configure platform specific IO.
 */
static void ConfigureIO(void) {
    HAPLogInfo(&kHAPLog_Default, "%s", __func__);

    // Setup user input event handler
    AppUserInputRegisterCallback(HandleUserInputEventCallback);

    // Assign LEDs.
    accessoryConfiguration.device.lightBulbPin = kAppLEDIdentifier_1;
    accessoryConfiguration.device.identifyPin = kAppLEDIdentifier_2;

    // Initialize LED driver
    AppLEDInit();

}

//----------------------------------------------------------------------------------------------------------------------

HAP_RESULT_USE_CHECK
HAPError IdentifyAccessory(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPAccessoryIdentifyRequest* request HAP_UNUSED,
        void* _Nullable context HAP_UNUSED) {
    HAPLogInfo(&kHAPLog_Default, "%s", __func__);
    DeviceIdentify();
    return kHAPError_None;
}

HAP_RESULT_USE_CHECK
HAPError HandleLightBulbOnRead(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPBoolCharacteristicReadRequest* request HAP_UNUSED,
        bool* value,
        void* _Nullable context HAP_UNUSED) {
    *value = accessoryConfiguration.state.lightBulbOn;
    HAPLogInfo(&kHAPLog_Default, "%s: %s", __func__, *value ? "true" : "false");
    return kHAPError_None;
}

HAP_RESULT_USE_CHECK
HAPError HandleLightBulbOnWrite(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPBoolCharacteristicWriteRequest* request HAP_UNUSED,
        bool value,
        void* _Nullable context HAP_UNUSED) {
    HAPLogInfo(&kHAPLog_Default, "%s: %s", __func__, value ? "true" : "false");
    if (accessoryConfiguration.state.lightBulbOn != value) {
        accessoryConfiguration.state.lightBulbOn = value;
        SaveAccessoryState();
        if (value) {
            TurnOnLightBulb();
        } else {
            TurnOffLightBulb();
        }

        HAPAccessoryServerRaiseEvent(server, request->characteristic, request->service, request->accessory);
    }
    return kHAPError_None;
}

HAP_RESULT_USE_CHECK
HAPError HandleLightBulbBrightnessRead(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPIntCharacteristicReadRequest* request HAP_UNUSED,
        int32_t* value,
        void* _Nullable context HAP_UNUSED) {
    *value = accessoryConfiguration.state.brightness;
    HAPLogInfo(&kHAPLog_Default, "%s: %d", __func__, (int) *value);
    return kHAPError_None;
}

HAP_RESULT_USE_CHECK
HAPError HandleLightBulbBrightnessWrite(
        HAPAccessoryServer* server,
        const HAPIntCharacteristicWriteRequest* request,
        int32_t value,
        void* _Nullable context HAP_UNUSED) {
    HAPError err = kHAPError_None;
    HAPLogInfo(&kHAPLog_Default, "%s: %d", __func__, (int) value);
    if (accessoryConfiguration.state.brightness != value) {
        int32_t test=0;
        test=accessoryConfiguration.state.brightness;
        accessoryConfiguration.state.brightness = value;
        SaveAccessoryState();

        if (test>value) {
            IncreaseBrightness();
        } else {
            DecreaseBrightness();
        }


        HAPAccessoryServerRaiseEvent(server, request->characteristic, request->service, request->accessory);
    }

    return err;
}



//----------------------------------------------------------------------------------------------------------------------
HAPPlatformTimerRef identifyTimer=0;
void AppCreate(HAPAccessoryServer* server, HAPPlatformKeyValueStoreRef keyValueStore) {
    HAPPrecondition(server);
    HAPPrecondition(keyValueStore);

    bool isSerialNumberSet;
    bool isProductDataSet;

    HAPLogInfo(&kHAPLog_Default, "%s", __func__);

    HAPRawBufferZero(&accessoryConfiguration, sizeof accessoryConfiguration);
    accessoryConfiguration.server = server;
    accessoryConfiguration.keyValueStore = keyValueStore;

    ConfigureIO();

    HAPPlatformAccessorySetupLoadSerialNumber(server->platform.accessorySetup, serialNumber, &isSerialNumberSet);
    if(isSerialNumberSet){
        accessory.serialNumber = (const char*)serialNumber;
    }

    HAPPlatformAccessorySetupLoadProductData(server->platform.accessorySetup, productData, &isProductDataSet);
    if(isProductDataSet){
        accessory.productData = (const char*)productData;
    }

    LoadAccessoryState();

    if (accessoryConfiguration.state.lightBulbOn) {
        TurnOnLightBulb();
    } else {
        TurnOffLightBulb();
    }
    HAPError err;
    identifyTimer=0;
    err = HAPPlatformTimerRegister(
            &identifyTimer,
            HAPPlatformClockGetCurrent() + 1 * HAPSecond,
            timecaallback,
            NULL);
    if (err) {
        HAPAssert(err == kHAPError_OutOfResources);
        HAPFatalError();
    }

    /* Initialize PCNT */
    setupPcnt();

    /* Initialize PRS */
    setupPrs();

    /* Initialize NVIC */
    setupNvic();
    // Enable NVIC USART sources
    // Zero out buffer
    for (int i = 0; i < BUFLEN; i++)
      UART_buffer[i] = 0;
    NVIC_ClearPendingIRQ(USART1_RX_IRQn);
    NVIC_EnableIRQ(USART1_RX_IRQn);
    USART_IntEnable(USART1, USART_IEN_RXDATAV);


}
static void timecaallback(HAPPlatformTimerRef timer, void* _Nullable context)
{
  HAPPrecondition(!context);
  HAPPrecondition(timer == identifyTimer);
  HAPError err;
  identifyTimer=0;
  err = HAPPlatformTimerRegister(
          &identifyTimer,
          HAPPlatformClockGetCurrent() + 1 * HAPSecond,
          timecaallback,
          NULL);
  if (err) {
      HAPAssert(err == kHAPError_OutOfResources);
      HAPFatalError();
  }
//  if (ledstatus) {
//      TurnOnLightBulb();
//      ledstatus=false;
//  } else {
//      TurnOffLightBulb();
//      ledstatus=true;
//  }



}
void AppRelease(HAPAccessoryServer* _Nonnull server, void* _Nullable context) {
    (void)(context);
    (void)(server);
    UnconfigureIO();
}

void AppAccessoryServerStart(void) {
    HAPAccessoryServerStart(accessoryConfiguration.server, &accessory);
}

//----------------------------------------------------------------------------------------------------------------------

void AppHandleAccessoryServerStateUpdate(HAPAccessoryServer* server, void* _Nullable context) {
    (void)(context);
    (void)(server);
}

void AppHandleFactoryReset(HAPAccessoryServer* server, void* _Nullable context) {
    (void)(context);
    (void)(server);
    HAPLogInfo(&kHAPLog_Default, "Resetting accessory configuration.");
#if (HAVE_ADAPTIVE_LIGHT == 1)
    // Purge persistent state.
    HAPPlatformKeyValueStoreDomain domainsToPurge[] = { kAppKeyValueStoreDomain_AdaptiveLight };
    for (size_t i = 0; i < HAPArrayCount(domainsToPurge); i++) {
        HAPError err = HAPPlatformKeyValueStorePurgeDomain(accessoryConfiguration.keyValueStore, domainsToPurge[i]);
        if (err) {
            HAPAssert(err == kHAPError_Unknown);
            HAPFatalError();
        }
    }
    RemoveTransition(lightBulbBrightnessCharacteristic.iid);
    RemoveTransition(lightBulbColorTemperatureCharacteristic.iid);
#endif
}

void AppHandleUnpair(HAPAccessoryServer* server, void* _Nullable context) {
    (void)(context);
    (void)(server);
#if (HAVE_ADAPTIVE_LIGHT == 1)
    HAPPlatformKeyValueStoreDomain domainsToPurge[] = { kAppKeyValueStoreDomain_AdaptiveLight };
    for (size_t i = 0; i < HAPArrayCount(domainsToPurge); i++) {
        HAPError err = HAPPlatformKeyValueStorePurgeDomain(accessoryConfiguration.keyValueStore, domainsToPurge[i]);
        if (err) {
            HAPAssert(err == kHAPError_Unknown);
            HAPFatalError();
        }
    }
    RemoveTransition(lightBulbBrightnessCharacteristic.iid);
    RemoveTransition(lightBulbColorTemperatureCharacteristic.iid);
#endif
}

const HAPAccessory* AppGetAccessoryInfo(void) {
    return &accessory;
}

const HAPAccessory* _Nonnull const* _Nullable AppGetBridgeAccessoryInfo(void) {
    return NULL;
}

void AppInitialize(
        HAPAccessoryServerOptions* hapAccessoryServerOptions,
        HAPPlatform* hapPlatform,
        HAPAccessoryServerCallbacks* hapAccessoryServerCallbacks) {
    (void)(hapAccessoryServerCallbacks);
    (void)(hapAccessoryServerOptions);
    (void)(hapPlatform);
#if (HAP_TESTING == 1)
    RegisterDebugCommandCallback(&ProcessCommandLine);
#endif
#if (SILICON_LABS_HOMEKIT_OTA == 1)
    SiliconLabsHomekitOTAHandleAppCreate();
#endif
}



void AppDeinitialize(void) {
    /*no-op*/
}

void PCNT0_IRQHandler(void)
{
  /* Acknowledge interrupt */
  PCNT_IntClear(PCNT0, PCNT_IFC_OF);
  if (ledstatus) {
      TurnOnLightBulb();
      ledstatus=false;
  } else {
      TurnOffLightBulb();
      ledstatus=true;
  }

}
void setupPcnt(void)
{
  PCNT_Init_TypeDef pcntInit = PCNT_INIT_DEFAULT;

  CMU_ClockEnable(cmuClock_PCNT0, true);

  pcntInit.mode     = pcntModeExtSingle;        // Use Ecternal Clock source for S0
  pcntInit.top      = 5;                        // top counter overflow after 6 presses
  pcntInit.s1CntDir = false;                    // S1 does not affect counter direction, default count up
  pcntInit.s0PRS    = pcntPRSCh0;

  /* Init PCNT0 */
  PCNT_Init(PCNT0, &pcntInit);

  /* Enable PRS Channel 0 */
  PCNT_PRSInputEnable(PCNT0, pcntPRSInputS0, true);

  /* Enable Interrupt */
  PCNT_IntEnable(PCNT0, PCNT_IEN_OF);
}
void setupPrs(void)
{
  CMU_ClockEnable(cmuClock_PRS, true);

  /* Link PRS Channel 0 to GPIO PIN 6 */
  PRS_SourceAsyncSignalSet(0, PRS_CH_CTRL_SOURCESEL_GPIOL, PRS_CH_CTRL_SIGSEL_GPIOPIN13);
}
void setupNvic(void)
{
  /* Clear PCNT0 pending interrupt */
  NVIC_ClearPendingIRQ(PCNT0_IRQn);

  /* Enable PCNT0 interrupt in the interrupt controller */
  NVIC_EnableIRQ(PCNT0_IRQn);
}

void formatNumberToString(uint8_t *dataOut, uint16_t value, uint8_t thenumber)
{
  if (value == 100)
  {
    dataOut[thenumber] = 49;
    thenumber = thenumber + 1;
    dataOut[thenumber] = 48;
    thenumber = thenumber + 1;
    dataOut[thenumber] = 48;
    thenumber = thenumber + 1;
  }
  if (value == 10)
  {
    dataOut[thenumber] = 48;
    thenumber = thenumber + 1;
    dataOut[thenumber] = 49;
    thenumber = thenumber + 1;
    dataOut[thenumber] = 48;
    thenumber = thenumber + 1;
  }
  if (value > 10 && value < 99)
  {
    dataOut[thenumber] = 48;
    thenumber = thenumber + 1;
    dataOut[thenumber] = ((value - (value % 10)) / 10) + 48;
    thenumber = thenumber + 1;
    dataOut[thenumber] = (value % 10) + 48;
    thenumber = thenumber + 1;
  }
  if (value < 10)
  {
    dataOut[thenumber] = 48;
    thenumber = thenumber + 1;
    dataOut[thenumber] = 48;
    thenumber = thenumber + 1;
    dataOut[thenumber] = (value % 10) + 48;
    thenumber = thenumber + 1;
  }
}
void USART1_RX_IRQHandler(void)
{
  // Get the character just received
  UART_buffer[inpos] = USART1->RXDATA;

  // Exit loop on new line or buffer full
  if ((UART_buffer[inpos] != '\r') && (inpos < BUFLEN))
    {
    inpos++;
    }
  else
    {
    receive = false;   // Stop receiving on CR
    inpos=0;
    }
}










































