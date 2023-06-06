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
// Copyright (C) 2015-2021 Apple Inc. All Rights Reserved.

// The most basic HomeKit example: an accessory that represents a light bulb that
// only supports switching the light on and off. Actions are exposed as individual
// functions below.
//
// This header file is platform-independent.

#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "HAP.h"

#include "ApplicationFeatures.h"
#include "sl_simple_button_instances.h"
#if __has_feature(nullability)
#pragma clang assume_nonnull begin
#endif

/**
 * Feature Configuration for accessory
 */
#if (HAVE_FIRMWARE_UPDATE == 1)
// Each application needs to define this in order to use data stream so undef any previous definitions
#undef HAP_APP_USES_HDS
#define HAP_APP_USES_HDS 1

// Each application needs to define this in order use stream protocol so undef any previous definitions
#undef HAP_APP_USES_HDS_STREAM
#define HAP_APP_USES_HDS_STREAM 1
#endif

#if (HAVE_ACCESSORY_REACHABILITY == 1)
/**
 * Sleep interval for this application
 */
#define kAccessorySleepInterval ((HAPTime) 0)
#endif

#if (HAVE_THREAD == 1)
/**
 * Thread device type:  MTD = Minimal / Sleepy device
 *                      FTD = Full thread device (Non sleepy)
 */
#define kThreadDeviceType (kHAPPlatformThreadDeviceCapabilities_FTD)
#endif

/**
 * Handle read request to the 'On' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbOnRead(
        HAPAccessoryServer* server,
        const HAPBoolCharacteristicReadRequest* request,
        bool* value,
        void* _Nullable context);

/**
 * Handle write request to the 'On' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbOnWrite(
        HAPAccessoryServer* server,
        const HAPBoolCharacteristicWriteRequest* request,
        bool value,
        void* _Nullable context);

/**
 * Handle read request to the 'Hue' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbHueRead(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPFloatCharacteristicReadRequest* request HAP_UNUSED,
        float* value,
        void* _Nullable context HAP_UNUSED);

/**
 * Handle write request to the 'Hue' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbHueWrite(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPFloatCharacteristicWriteRequest* request HAP_UNUSED,
        float value,
        void* _Nullable context HAP_UNUSED);

/**
 * Handle read request to the 'Brightness' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbBrightnessRead(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPIntCharacteristicReadRequest* request HAP_UNUSED,
        int32_t* value,
        void* _Nullable context HAP_UNUSED);

/**
 * Handle write request to the 'Brightness' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbBrightnessWrite(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPIntCharacteristicWriteRequest* request HAP_UNUSED,
        int32_t value,
        void* _Nullable context HAP_UNUSED);

/**
 * Handle read request to the 'Saturation' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbSaturationRead(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPFloatCharacteristicReadRequest* request HAP_UNUSED,
        float* value,
        void* _Nullable context HAP_UNUSED);

/**
 * Handle write request to the 'Saturation' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbSaturationWrite(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPFloatCharacteristicWriteRequest* request HAP_UNUSED,
        float value,
        void* _Nullable context HAP_UNUSED);

/**
 * Handle read request to the 'Color Temperature' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbColorTemperatureRead(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPUInt32CharacteristicReadRequest* request HAP_UNUSED,
        uint32_t* value,
        void* _Nullable context HAP_UNUSED);

/**
 * Handle write request to the 'Color Temperature' characteristic of the Light Bulb service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbColorTemperatureWrite(
        HAPAccessoryServer* server HAP_UNUSED,
        const HAPUInt32CharacteristicWriteRequest* request HAP_UNUSED,
        uint32_t value,
        void* _Nullable context HAP_UNUSED);

#if (HAP_TESTING == 1) || (SL_SIMPLE_BUTTON_COUNT >= 1)
/**
 * Toggle the light bulb
 */
static void timecaallback(HAPPlatformTimerRef timer, void* _Nullable context);

void ToggleLightBulbState(void);

void IncreaseBrightness(void);
void DecreaseBrightness(void);

void PCNT0_IRQHandler(void);
void setupPcnt(void);
void setupPrs(void);
void setupNvic(void);

#endif

#if __has_feature(nullability)
#pragma clang assume_nonnull end
#endif

#ifdef __cplusplus
}
#endif

#endif
