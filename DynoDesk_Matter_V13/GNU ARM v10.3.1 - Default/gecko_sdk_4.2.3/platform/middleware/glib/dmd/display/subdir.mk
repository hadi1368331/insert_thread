################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk/platform/middleware/glib/dmd/display/dmd_memlcd.c 

OBJS += \
./gecko_sdk_4.2.3/platform/middleware/glib/dmd/display/dmd_memlcd.o 

C_DEPS += \
./gecko_sdk_4.2.3/platform/middleware/glib/dmd/display/dmd_memlcd.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.2.3/platform/middleware/glib/dmd/display/dmd_memlcd.o: C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk/platform/middleware/glib/dmd/display/dmd_memlcd.c gecko_sdk_4.2.3/platform/middleware/glib/dmd/display/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DBLE_ADV_INTERVAL_MS=417.5f' '-DHAVE_ACCESSORY_REACHABILITY=1' '-DOPENTHREAD_CONFIG_NUM_MESSAGE_BUFFERS=64' '-DHOMEKIT_ACCESSORY_INFORMATION_SERVICE=1' '-DHOMEKIT_ACCESSORY_RUNTIME_INFORMATION_SERVICE=1' '-DHOMEKIT_APP_LED=1' '-DHOMEKIT_APP_USER_INPUT=1' '-DHOMEKIT_ATTRIBUTE_CHECK=1' '-DHOMEKIT_DEBUG_COMMAND=1' '-DHAVE_DISPLAY=1' '-DHAP_BUILD=e6e82026' '-DHAP_COMPILER_VERSION=GCC __VERSION__' '-DHAP_VERSION=6.3' '-DHOMEKIT_HAP_PROTOCOL_INFORMATION_SERVICE=1' '-DSILICON_LABS_HOMEKIT_OTA=1' '-DHOMEKIT_PAIRING_SERVICE=1' '-DBLE=1' '-DHAP_FEATURE_BLE=1' '-DHAVE_BLE=1' '-DHAVE_CUSTOM_SINGLE_SHOT_CHACHA20_POLY1305=1' '-DNVM3_DEFAULT_MAX_OBJECT_SIZE=1188' '-DHAP_FEATURE_THREAD=1' '-DHAP_THREAD=1' '-DHAVE_THREAD=1' '-DTHREAD_DEVKIT_ADK=1' '-DSL_ENABLE_MULTI_RX_BUFFER_SUPPORT=1' '-DMGM12P32F1024GA=1' '-DSL_APP_PROPERTIES=1' '-DSL_BOARD_NAME="BRD4304A"' '-DSL_BOARD_REV="A03"' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DOPENTHREAD_CONFIG_ENABLE_BUILTIN_MBEDTLS=0' '-DRADIO_CONFIG_DMP_SUPPORT=1' '-DOPENTHREAD_CORE_CONFIG_PLATFORM_CHECK_FILE="openthread-core-efr32-config-check.h"' '-DOPENTHREAD_PROJECT_CORE_CONFIG_FILE="openthread-core-efr32-config.h"' '-DOPENTHREAD_CONFIG_FILE="sl_openthread_generic_config.h"' '-DOPENTHREAD_FTD=1' '-DSL_OPENTHREAD_STACK_FEATURES_CONFIG_FILE="sl_openthread_features_config.h"' '-DBUFFER_SIZE_DOWN=0' '-DBUFFER_SIZE_UP=768' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=1' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' -I"C:\Users\IT\SimplicityStudio\v5_workspace\DynoDesk_Matter_V13\config" -I"C:\Users\IT\SimplicityStudio\v5_workspace\DynoDesk_Matter_V13\config\hkconf" -I"C:\Users\IT\SimplicityStudio\v5_workspace\DynoDesk_Matter_V13\config\btconf" -I"C:\Users\IT\SimplicityStudio\v5_workspace\DynoDesk_Matter_V13" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/Applications" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/Applications/Common/DB" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/Applications/Common/Helper" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/PAL/SiliconLabs" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/External/mdnsresponder/mDNSShared" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/Applications/Common/Platform" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/app/common/display" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/HAP" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/HAP/Thread" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/External/Base64" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/External/HTTP" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/External/JSON" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/Applications/Lightbulb" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/Applications/Common/Platform/SiliconLabs" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/PAL" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/PAL/SiliconLabs/Crypto/CommonWithPSACrypto" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/PAL/SiliconLabs/Crypto/CommonWithPSACrypto/Ed25519" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/PAL/Thread" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/PAL/Mock" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/External/mdnsresponder/ServiceRegistration" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//extension/homekit/adk/PAL/Thread/OpenThread" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/MGM12/Include" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/driver/button/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib/dmd" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/fem_util" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib/glib" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/src/ls013b7dh03" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/config" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/include" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/library" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/inc/memlcd_usart" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/src" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/src/cli" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/include" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/include/openthread" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/src/core" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/third_party/tcplp" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/examples/platforms" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/openthread/examples/platforms/utils" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//protocol/openthread/platform-abstraction/efr32" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_psa_driver/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_psa_driver/inc/public" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg1x" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg1x" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_rssi" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/plugin/security_manager" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//protocol/openthread/include" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_protocol_crypto/src" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -I"C:/Users/IT/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\IT\SimplicityStudio\v5_workspace\DynoDesk_Matter_V13\autogen" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacroshomekit_lightbulb_config.h -imacroshomekit_pal_common_config.h -imacroshomekit_pal_thread_config.h -imacrossl_openthread_ble_cli_config.h -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Wno-sign-compare -Wno-unused-parameter --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.2.3/platform/middleware/glib/dmd/display/dmd_memlcd.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


