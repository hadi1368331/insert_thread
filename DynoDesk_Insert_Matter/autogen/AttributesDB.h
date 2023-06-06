#ifndef ATTRIBUTESDB_H
#define ATTRIBUTESDB_H
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "HAP.h"

/**
 * Accessory description
 */
extern HAPAccessory accessory;

/**
 * Total number of services and characteristics contained in the accessory.
 */
enum {kAttributeCount = 39 };

// -------------------------------
/**
 * Characteristics declaration
 */
/**
 * The 'lightBulbServiceSignatureCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
extern const HAPDataCharacteristic lightBulbServiceSignatureCharacteristic;  
/**
 * The 'lightBulbNameCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
extern const HAPStringCharacteristic lightBulbNameCharacteristic;  
/**
 * The 'lightBulbOnCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
extern const HAPBoolCharacteristic lightBulbOnCharacteristic;  
/**
 * The 'lightBulbBrightnessCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
extern const HAPIntCharacteristic lightBulbBrightnessCharacteristic;  
/**
 * The 'accessoryRuntimeInformationServiceSignatureCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
extern const HAPDataCharacteristic accessoryRuntimeInformationServiceSignatureCharacteristic;  
/**
 * The 'accessoryRuntimeInformationSleepIntervalCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
extern const HAPUInt32Characteristic accessoryRuntimeInformationSleepIntervalCharacteristic;  
/**
 * The 'accessoryRuntimeInformationPingCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
extern const HAPDataCharacteristic accessoryRuntimeInformationPingCharacteristic;  
/**
 * The 'accessoryRuntimeInformationHeartBeatCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
extern const HAPUInt32Characteristic accessoryRuntimeInformationHeartBeatCharacteristic;  
/**
 * The 'accessoryInformationIdentifyCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPBoolCharacteristic accessoryInformationIdentifyCharacteristic;  
/**
 * The 'accessoryInformationManufacturerCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPStringCharacteristic accessoryInformationManufacturerCharacteristic;  
/**
 * The 'accessoryInformationModelCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPStringCharacteristic accessoryInformationModelCharacteristic;  
/**
 * The 'accessoryInformationNameCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPStringCharacteristic accessoryInformationNameCharacteristic;  
/**
 * The 'accessoryInformationSerialNumberCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPStringCharacteristic accessoryInformationSerialNumberCharacteristic;  
/**
 * The 'accessoryInformationFirmwareRevisionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPStringCharacteristic accessoryInformationFirmwareRevisionCharacteristic;  
/**
 * The 'accessoryInformationHardwareRevisionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPStringCharacteristic accessoryInformationHardwareRevisionCharacteristic;  
/**
 * The 'accessoryInformationADKVersionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPStringCharacteristic accessoryInformationADKVersionCharacteristic;  
/**
 * The 'accessoryInformationProductDataCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
extern const HAPDataCharacteristic accessoryInformationProductDataCharacteristic;  
/**
 * The 'pairingPairSetupCharacteristic' characteristic of the 'pairingService' service.
 */
extern const HAPTLV8Characteristic pairingPairSetupCharacteristic;  
/**
 * The 'pairingPairVerifyCharacteristic' characteristic of the 'pairingService' service.
 */
extern const HAPTLV8Characteristic pairingPairVerifyCharacteristic;  
/**
 * The 'pairingPairingFeaturesCharacteristic' characteristic of the 'pairingService' service.
 */
extern const HAPUInt8Characteristic pairingPairingFeaturesCharacteristic;  
/**
 * The 'pairingPairingPairingsCharacteristic' characteristic of the 'pairingService' service.
 */
extern const HAPTLV8Characteristic pairingPairingPairingsCharacteristic;  
/**
 * The 'hapProtocolInformationServiceSignatureCharacteristic' characteristic of the 'hapProtocolInformationService' service.
 */
extern const HAPDataCharacteristic hapProtocolInformationServiceSignatureCharacteristic;  
/**
 * The 'hapProtocolInformationVersionCharacteristic' characteristic of the 'hapProtocolInformationService' service.
 */
extern const HAPStringCharacteristic hapProtocolInformationVersionCharacteristic;  
/**
 * The 'SiliconLabsOTAControlCharacteristic' characteristic of the 'siliconLabsOTAService' service.
 */
extern const HAPDataCharacteristic SiliconLabsOTAControlCharacteristic;  
/**
 * The 'SiliconLabsOTADataCharacteristic' characteristic of the 'siliconLabsOTAService' service.
 */
extern const HAPDataCharacteristic SiliconLabsOTADataCharacteristic;  
/**
 * The 'SiliconLabsOTAServiceSignatureCharacteristic' characteristic of the 'siliconLabsOTAService' service.
 */
extern const HAPDataCharacteristic SiliconLabsOTAServiceSignatureCharacteristic;  
/**
 * The 'threadManagementServiceSignatureCharacteristic' characteristic of the 'threadManagementService' service.
 */
extern const HAPDataCharacteristic threadManagementServiceSignatureCharacteristic;  
/**
 * The 'threadManagementOpenThreadVersionCharacteristic' characteristic of the 'threadManagementService' service.
 */
extern const HAPStringCharacteristic threadManagementOpenThreadVersionCharacteristic;  
/**
 * The 'threadManagementControlCharacteristic' characteristic of the 'threadManagementService' service.
 */
extern const HAPTLV8Characteristic threadManagementControlCharacteristic;  
/**
 * The 'threadManagementNodeCapabilitiesCharacteristic' characteristic of the 'threadManagementService' service.
 */
extern const HAPUInt16Characteristic threadManagementNodeCapabilitiesCharacteristic;  
/**
 * The 'threadManagementStatusCharacteristic' characteristic of the 'threadManagementService' service.
 */
extern const HAPUInt16Characteristic threadManagementStatusCharacteristic;  
/**
 * The 'threadManagementCurrentTransportCharacteristic' characteristic of the 'threadManagementService' service.
 */
extern const HAPBoolCharacteristic threadManagementCurrentTransportCharacteristic;  
// -------------------------------
/**
 * Callback declaration 
 */

/**
 * Handle read request to the 'lightBulbServiceSignatureCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleServiceSignatureRead(
        HAPAccessoryServer* server,
        const HAPDataCharacteristicReadRequest* request,
    void* valueBytes,
        size_t maxValueBytes,
        size_t* numValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'lightBulbNameCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleNameRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'lightBulbOnCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbOnRead(
        HAPAccessoryServer* server,
        const HAPBoolCharacteristicReadRequest* request,
    bool* value,
    void* _Nullable context);

/**
 * Handle write request to the 'lightBulbOnCharacteristic' callback of the 'DynoDesk_Light' service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbOnWrite(
        HAPAccessoryServer* server,
        const HAPBoolCharacteristicWriteRequest* request,
    bool value,
    void* _Nullable context);

/**
 * Handle read request to the 'lightBulbBrightnessCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbBrightnessRead(
        HAPAccessoryServer* server,
        const HAPIntCharacteristicReadRequest* request,
    int32_t* value,
    void* _Nullable context);

/**
 * Handle write request to the 'lightBulbBrightnessCharacteristic' callback of the 'DynoDesk_Light' service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleLightBulbBrightnessWrite(
        HAPAccessoryServer* server,
        const HAPIntCharacteristicWriteRequest* request,
    int32_t value,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryRuntimeInformationSleepIntervalCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleAccessoryRuntimeInformationSleepIntervalRead(
        HAPAccessoryServer* server,
        const HAPUInt32CharacteristicReadRequest* request,
    uint32_t* value,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryRuntimeInformationPingCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryRuntimeInformationPingRead(
        HAPAccessoryServer* server,
        const HAPDataCharacteristicReadRequest* request,
    void* valueBytes,
        size_t maxValueBytes,
        size_t* numValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryRuntimeInformationHeartBeatCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryRuntimeInformationHeartBeatRead(
        HAPAccessoryServer* server,
        const HAPUInt32CharacteristicReadRequest* request,
    uint32_t* value,
    void* _Nullable context);

/**
 * Handle write request to the 'accessoryInformationIdentifyCharacteristic' callback of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationIdentifyWrite(
        HAPAccessoryServer* server,
        const HAPBoolCharacteristicWriteRequest* request,
    bool value,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationManufacturerCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationManufacturerRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationModelCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationModelRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationNameCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationNameRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationSerialNumberCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationSerialNumberRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationFirmwareRevisionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationFirmwareRevisionRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationHardwareRevisionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationHardwareRevisionRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationADKVersionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationADKVersionRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'accessoryInformationProductDataCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleAccessoryInformationProductDataRead(
        HAPAccessoryServer* server,
        const HAPDataCharacteristicReadRequest* request,
    void* valueBytes,
        size_t maxValueBytes,
        size_t* numValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'pairingPairSetupCharacteristic' characteristic of the 'pairingService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandlePairingPairSetupRead(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicReadRequest* request,
    HAPTLVWriter* responseWriter,
    void* _Nullable context);

/**
 * Handle write request to the 'pairingPairSetupCharacteristic' callback of the 'pairingService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandlePairingPairSetupWrite(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicWriteRequest* request,
    HAPTLVReader* requestReader,
    void* _Nullable context);

/**
 * Handle read request to the 'pairingPairVerifyCharacteristic' characteristic of the 'pairingService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandlePairingPairVerifyRead(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicReadRequest* request,
    HAPTLVWriter* responseWriter,
    void* _Nullable context);

/**
 * Handle write request to the 'pairingPairVerifyCharacteristic' callback of the 'pairingService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandlePairingPairVerifyWrite(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicWriteRequest* request,
    HAPTLVReader* requestReader,
    void* _Nullable context);

/**
 * Handle read request to the 'pairingPairingFeaturesCharacteristic' characteristic of the 'pairingService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandlePairingPairingFeaturesRead(
        HAPAccessoryServer* server,
        const HAPUInt8CharacteristicReadRequest* request,
    uint8_t* value,
    void* _Nullable context);

/**
 * Handle read request to the 'pairingPairingPairingsCharacteristic' characteristic of the 'pairingService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandlePairingPairingPairingsRead(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicReadRequest* request,
    HAPTLVWriter* responseWriter,
    void* _Nullable context);

/**
 * Handle write request to the 'pairingPairingPairingsCharacteristic' callback of the 'pairingService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandlePairingPairingPairingsWrite(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicWriteRequest* request,
    HAPTLVReader* requestReader,
    void* _Nullable context);

/**
 * Handle read request to the 'hapProtocolInformationVersionCharacteristic' characteristic of the 'hapProtocolInformationService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleHAPProtocolInformationVersionRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle write request to the 'SiliconLabsOTAControlCharacteristic' callback of the 'siliconLabsOTAService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleSiliconLabsHomekitOTAControlWrite(
        HAPAccessoryServer* server,
        const HAPDataCharacteristicWriteRequest* request,
    const void* valueBytes,
        size_t numValueBytes,
    void* _Nullable context);

/**
 * Handle write request to the 'SiliconLabsOTADataCharacteristic' callback of the 'siliconLabsOTAService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HandleSiliconLabsHomekitOTADataWrite(
        HAPAccessoryServer* server,
        const HAPDataCharacteristicWriteRequest* request,
    const void* valueBytes,
        size_t numValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'threadManagementOpenThreadVersionCharacteristic' characteristic of the 'threadManagementService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPPlatformSetupHandleOpenThreadVersionRead(
        HAPAccessoryServer* server,
        const HAPStringCharacteristicReadRequest* request,
    char* value,
        size_t maxValueBytes,
    void* _Nullable context);

/**
 * Handle read request to the 'threadManagementControlCharacteristic' characteristic of the 'threadManagementService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleThreadManagementControlRead(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicReadRequest* request,
    HAPTLVWriter* responseWriter,
    void* _Nullable context);

/**
 * Handle write request to the 'threadManagementControlCharacteristic' callback of the 'threadManagementService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleThreadManagementControlWrite(
        HAPAccessoryServer* server,
        const HAPTLV8CharacteristicWriteRequest* request,
    HAPTLVReader* requestReader,
    void* _Nullable context);

/**
 * Handle read request to the 'threadManagementNodeCapabilitiesCharacteristic' characteristic of the 'threadManagementService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleThreadManagementNodeCapabilitiesRead(
        HAPAccessoryServer* server,
        const HAPUInt16CharacteristicReadRequest* request,
    uint16_t* value,
    void* _Nullable context);

/**
 * Handle read request to the 'threadManagementStatusCharacteristic' characteristic of the 'threadManagementService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleThreadManagementStatusRead(
        HAPAccessoryServer* server,
        const HAPUInt16CharacteristicReadRequest* request,
    uint16_t* value,
    void* _Nullable context);

/**
 * Handle read request to the 'threadManagementCurrentTransportCharacteristic' characteristic of the 'threadManagementService' service.
 */
HAP_RESULT_USE_CHECK
HAPError HAPHandleThreadManagementCurrentTransportRead(
        HAPAccessoryServer* server,
        const HAPBoolCharacteristicReadRequest* request,
    bool* value,
    void* _Nullable context);

// -------------------------------
/**
 * Service declaration
 */
/**
 * 'DynoDesk_Light' service.
 */
extern const HAPService DynoDesk_Light;        
/**
 * 'accessoryRuntimeInformationService' service.
 */
extern const HAPService accessoryRuntimeInformationService;        
/**
 * 'accessoryInformationService' service.
 */
extern const HAPService accessoryInformationService;        
/**
 * 'pairingService' service.
 */
extern const HAPService pairingService;        
/**
 * 'hapProtocolInformationService' service.
 */
extern const HAPService hapProtocolInformationService;        
/**
 * 'siliconLabsOTAService' service.
 */
extern const HAPService siliconLabsOTAService;        
/**
 * 'threadManagementService' service.
 */
extern const HAPService threadManagementService;        
#if __has_feature(nullability)
#pragma clang assume_nonnull end
#endif

#ifdef __cplusplus
}
#endif
