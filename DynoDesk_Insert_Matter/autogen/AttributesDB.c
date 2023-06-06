#include "AttributesDB.h"

// -------------------------------
/**
 * Accessory description
 */
HAPAccessory accessory = { 
        .aid = 1,
        .category = 5,
        .name = "HomeKit Accessory",
        .productData = "d1d2d3d4d5d6d7d8", 
        .manufacturer = "Silicon Labs",
        .model = "EFR32x",
        .serialNumber = "152405958", 
        .firmwareVersion = "1.0.1",
        .hardwareVersion = "1",
        .services = (const HAPService* const[]) { 
        &DynoDesk_Light,
        &accessoryRuntimeInformationService,
        &accessoryInformationService,
        &pairingService,
        &hapProtocolInformationService,
        &siliconLabsOTAService,
        &threadManagementService,
        NULL },
        .callbacks = {},
};

// -------------------------------
/**
 * Attribute UUUIDs
 */
const HAPUUID kHAPCharacteristicType_lightBulbServiceSignatureCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0xa5,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_lightBulbNameCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x23,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_lightBulbOnCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x25,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_lightBulbBrightnessCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x08,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryRuntimeInformationServiceSignatureCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0xa5,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryRuntimeInformationSleepIntervalCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x3a,0x02,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryRuntimeInformationPingCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x3c,0x02,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryRuntimeInformationHeartBeatCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x4a,0x02,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationIdentifyCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x14,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationManufacturerCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x20,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationModelCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x21,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationNameCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x23,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationSerialNumberCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x30,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationFirmwareRevisionCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x52,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationHardwareRevisionCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x53,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationADKVersionCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x37,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_accessoryInformationProductDataCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x20,0x02,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_pairingPairSetupCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x4c,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_pairingPairVerifyCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x4e,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_pairingPairingFeaturesCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x4f,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_pairingPairingPairingsCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x50,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_hapProtocolInformationServiceSignatureCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0xa5,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_hapProtocolInformationVersionCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x37,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_SiliconLabsOTAControlCharacteristic = { {0xf7,0xbf,0x35,0x64,0xfb,0x6d,0x4e,0x53,0x88,0xa4,0x5e,0x37,0xe0,0x32,0x60,0x63} };
const HAPUUID kHAPCharacteristicType_SiliconLabsOTADataCharacteristic = { {0x98,0x42,0x27,0xf3,0x34,0xfc,0x40,0x45,0xa5,0xd0,0x2c,0x58,0x1f,0x81,0xa1,0x53} };
const HAPUUID kHAPCharacteristicType_SiliconLabsOTAServiceSignatureCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0xa5,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_threadManagementServiceSignatureCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0xa5,0x00,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_threadManagementOpenThreadVersionCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x06,0x07,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_threadManagementControlCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x04,0x07,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_threadManagementNodeCapabilitiesCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x02,0x07,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_threadManagementStatusCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x03,0x07,0x00,0x00} };
const HAPUUID kHAPCharacteristicType_threadManagementCurrentTransportCharacteristic = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x2b,0x02,0x00,0x00} };
 

const HAPUUID kHAPServiceType_DynoDesk_Light = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x43,0x00,0x00,0x00} };
const HAPUUID kHAPServiceType_accessoryRuntimeInformationService = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x39,0x02,0x00,0x00} };
const HAPUUID kHAPServiceType_accessoryInformationService = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x3e,0x00,0x00,0x00} };
const HAPUUID kHAPServiceType_pairingService = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x55,0x00,0x00,0x00} };
const HAPUUID kHAPServiceType_hapProtocolInformationService = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0xa2,0x00,0x00,0x00} };
const HAPUUID kHAPServiceType_siliconLabsOTAService = { {0x1d,0x14,0xd6,0xee,0xfd,0x63,0x4f,0xa1,0xbf,0xa4,0x8f,0x47,0xb4,0x21,0x19,0xf0} };
const HAPUUID kHAPServiceType_threadManagementService = { {0x91,0x52,0x76,0xbb,0x26,0x00,0x00,0x80,0x00,0x10,0x00,0x00,0x01,0x07,0x00,0x00} };
 

// -------------------------------
/**
 * Characteristics - definition
 */

 
/**
 * The 'lightBulbServiceSignatureCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
const HAPDataCharacteristic lightBulbServiceSignatureCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 65,
    .characteristicType = &kHAPCharacteristicType_lightBulbServiceSignatureCharacteristic,
    .debugDescription = "ServiceSignature",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 2097152,
    },  
    .callbacks = {
        .handleRead = HAPHandleServiceSignatureRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'lightBulbNameCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
const HAPStringCharacteristic lightBulbNameCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 66,
    .characteristicType = &kHAPCharacteristicType_lightBulbNameCharacteristic,
    .debugDescription = "Name",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleNameRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'lightBulbOnCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
const HAPBoolCharacteristic lightBulbOnCharacteristic = {
    .format = kHAPCharacteristicFormat_Bool,
    .iid = 67,
    .characteristicType = &kHAPCharacteristicType_lightBulbOnCharacteristic,
    .debugDescription = "On",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = true,
        .supportsEventNotification = true,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = true,
            .supportsDisconnectedNotification = true,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },   
    .callbacks = {
        .handleRead = HandleLightBulbOnRead,
        .handleWrite = HandleLightBulbOnWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'lightBulbBrightnessCharacteristic' characteristic of the 'DynoDesk_Light' service.
 */
const HAPIntCharacteristic lightBulbBrightnessCharacteristic = {
    .format = kHAPCharacteristicFormat_Int,
    .iid = 68,
    .characteristicType = &kHAPCharacteristicType_lightBulbBrightnessCharacteristic,
    .debugDescription = "Brightness",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = true,
        .supportsEventNotification = true,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = true,
            .supportsDisconnectedNotification = true,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },
    .units = kHAPCharacteristicUnits_Percentage,
     
    .constraints = {
        .minimumValue = 0,
        .maximumValue = 100,
        .stepValue = 1,
    },  
    .callbacks = {
        .handleRead = HandleLightBulbBrightnessRead,
        .handleWrite = HandleLightBulbBrightnessWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryRuntimeInformationServiceSignatureCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
const HAPDataCharacteristic accessoryRuntimeInformationServiceSignatureCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 301,
    .characteristicType = &kHAPCharacteristicType_accessoryRuntimeInformationServiceSignatureCharacteristic,
    .debugDescription = "ServiceSignature",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 2097152,
    },  
    .callbacks = {
        .handleRead = HAPHandleServiceSignatureRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryRuntimeInformationSleepIntervalCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
const HAPUInt32Characteristic accessoryRuntimeInformationSleepIntervalCharacteristic = {
    .format = kHAPCharacteristicFormat_UInt32,
    .iid = 302,
    .characteristicType = &kHAPCharacteristicType_accessoryRuntimeInformationSleepIntervalCharacteristic,
    .debugDescription = "AccessoryRuntimeInformationSleepInterval",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },
    .units = kHAPCharacteristicUnits_None,
     
    .constraints = {
        .minimumValue = 0,
        .maximumValue = 67108863,
        .stepValue = 1,
    },  
    .callbacks = {
        .handleRead = HandleAccessoryRuntimeInformationSleepIntervalRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryRuntimeInformationPingCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
const HAPDataCharacteristic accessoryRuntimeInformationPingCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 303,
    .characteristicType = &kHAPCharacteristicType_accessoryRuntimeInformationPingCharacteristic,
    .debugDescription = "AccessoryRuntimeInformationPing",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = true,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 0,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryRuntimeInformationPingRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryRuntimeInformationHeartBeatCharacteristic' characteristic of the 'accessoryRuntimeInformationService' service.
 */
const HAPUInt32Characteristic accessoryRuntimeInformationHeartBeatCharacteristic = {
    .format = kHAPCharacteristicFormat_UInt32,
    .iid = 304,
    .characteristicType = &kHAPCharacteristicType_accessoryRuntimeInformationHeartBeatCharacteristic,
    .debugDescription = "AccessoryRuntimeInformationHeartBeat",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = true,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = true,
            .supportsDisconnectedNotification = true,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },
    .units = kHAPCharacteristicUnits_None,
     
    .constraints = {
        .minimumValue = 0,
        .maximumValue = 4294967295,
        .stepValue = 1,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryRuntimeInformationHeartBeatRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationIdentifyCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPBoolCharacteristic accessoryInformationIdentifyCharacteristic = {
    .format = kHAPCharacteristicFormat_Bool,
    .iid = 201,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationIdentifyCharacteristic,
    .debugDescription = "Identify",
    .manufacturerDescription = "",
    .properties = {
        .readable = false,
        .writable = true,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },   
    .callbacks = {
        .handleRead = NULL,
        .handleWrite = HAPHandleAccessoryInformationIdentifyWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationManufacturerCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPStringCharacteristic accessoryInformationManufacturerCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 202,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationManufacturerCharacteristic,
    .debugDescription = "Manufacturer",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationManufacturerRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationModelCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPStringCharacteristic accessoryInformationModelCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 203,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationModelCharacteristic,
    .debugDescription = "Model",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationModelRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationNameCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPStringCharacteristic accessoryInformationNameCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 204,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationNameCharacteristic,
    .debugDescription = "variableName",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationNameRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationSerialNumberCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPStringCharacteristic accessoryInformationSerialNumberCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 205,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationSerialNumberCharacteristic,
    .debugDescription = "SerialNumber",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationSerialNumberRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationFirmwareRevisionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPStringCharacteristic accessoryInformationFirmwareRevisionCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 206,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationFirmwareRevisionCharacteristic,
    .debugDescription = "FirmwareRevision",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationFirmwareRevisionRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationHardwareRevisionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPStringCharacteristic accessoryInformationHardwareRevisionCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 207,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationHardwareRevisionCharacteristic,
    .debugDescription = "HardwareRevision",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationHardwareRevisionRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationADKVersionCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPStringCharacteristic accessoryInformationADKVersionCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 208,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationADKVersionCharacteristic,
    .debugDescription = "ADKVersion",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = true,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationADKVersionRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'accessoryInformationProductDataCharacteristic' characteristic of the 'accessoryInformationService' service.
 */
const HAPDataCharacteristic accessoryInformationProductDataCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 209,
    .characteristicType = &kHAPCharacteristicType_accessoryInformationProductDataCharacteristic,
    .debugDescription = "ProductData",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = true,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 8,
    },  
    .callbacks = {
        .handleRead = HAPHandleAccessoryInformationProductDataRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'pairingPairSetupCharacteristic' characteristic of the 'pairingService' service.
 */
const HAPTLV8Characteristic pairingPairSetupCharacteristic = {
    .format = kHAPCharacteristicFormat_TLV8,
    .iid = 401,
    .characteristicType = &kHAPCharacteristicType_pairingPairSetupCharacteristic,
    .debugDescription = "PairSetup",
    .manufacturerDescription = "",
    .properties = {
        .readable = false,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = true,
            .writableWithoutSecurity = true 
        },
    },   
    .callbacks = {
        .handleRead = HAPHandlePairingPairSetupRead,
        .handleWrite = HAPHandlePairingPairSetupWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'pairingPairVerifyCharacteristic' characteristic of the 'pairingService' service.
 */
const HAPTLV8Characteristic pairingPairVerifyCharacteristic = {
    .format = kHAPCharacteristicFormat_TLV8,
    .iid = 402,
    .characteristicType = &kHAPCharacteristicType_pairingPairVerifyCharacteristic,
    .debugDescription = "PairVerify",
    .manufacturerDescription = "",
    .properties = {
        .readable = false,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = true,
            .writableWithoutSecurity = true 
        },
    },   
    .callbacks = {
        .handleRead = HAPHandlePairingPairVerifyRead,
        .handleWrite = HAPHandlePairingPairVerifyWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'pairingPairingFeaturesCharacteristic' characteristic of the 'pairingService' service.
 */
const HAPUInt8Characteristic pairingPairingFeaturesCharacteristic = {
    .format = kHAPCharacteristicFormat_UInt8,
    .iid = 403,
    .characteristicType = &kHAPCharacteristicType_pairingPairingFeaturesCharacteristic,
    .debugDescription = "PairingFeatures",
    .manufacturerDescription = "",
    .properties = {
        .readable = false,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = true,
            .writableWithoutSecurity = false 
        },
    },
    .units = kHAPCharacteristicUnits_None,
     
    .constraints = {
        .minimumValue = 0,
        .maximumValue = 255,
        .stepValue = 0, 
    },  
    .callbacks = {
        .handleRead = HAPHandlePairingPairingFeaturesRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'pairingPairingPairingsCharacteristic' characteristic of the 'pairingService' service.
 */
const HAPTLV8Characteristic pairingPairingPairingsCharacteristic = {
    .format = kHAPCharacteristicFormat_TLV8,
    .iid = 404,
    .characteristicType = &kHAPCharacteristicType_pairingPairingPairingsCharacteristic,
    .debugDescription = "PairingPairings",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = true,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },   
    .callbacks = {
        .handleRead = HAPHandlePairingPairingPairingsRead,
        .handleWrite = HAPHandlePairingPairingPairingsWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'hapProtocolInformationServiceSignatureCharacteristic' characteristic of the 'hapProtocolInformationService' service.
 */
const HAPDataCharacteristic hapProtocolInformationServiceSignatureCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 501,
    .characteristicType = &kHAPCharacteristicType_hapProtocolInformationServiceSignatureCharacteristic,
    .debugDescription = "ServiceSignature",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 2097152,
    },  
    .callbacks = {
        .handleRead = HAPHandleServiceSignatureRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'hapProtocolInformationVersionCharacteristic' characteristic of the 'hapProtocolInformationService' service.
 */
const HAPStringCharacteristic hapProtocolInformationVersionCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 502,
    .characteristicType = &kHAPCharacteristicType_hapProtocolInformationVersionCharacteristic,
    .debugDescription = "Version",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 64,
    },  
    .callbacks = {
        .handleRead = HAPHandleHAPProtocolInformationVersionRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'SiliconLabsOTAControlCharacteristic' characteristic of the 'siliconLabsOTAService' service.
 */
const HAPDataCharacteristic SiliconLabsOTAControlCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 901,
    .characteristicType = &kHAPCharacteristicType_SiliconLabsOTAControlCharacteristic,
    .debugDescription = "SiliconLabsOTAControl",
    .manufacturerDescription = "",
    .properties = {
        .readable = false,
        .writable = true,
        .supportsEventNotification = false,
        .hidden = true,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 1,
    },  
    .callbacks = {
        .handleRead = NULL,
        .handleWrite = HandleSiliconLabsHomekitOTAControlWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'SiliconLabsOTADataCharacteristic' characteristic of the 'siliconLabsOTAService' service.
 */
const HAPDataCharacteristic SiliconLabsOTADataCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 902,
    .characteristicType = &kHAPCharacteristicType_SiliconLabsOTADataCharacteristic,
    .debugDescription = "SiliconLabsOTAData",
    .manufacturerDescription = "",
    .properties = {
        .readable = false,
        .writable = true,
        .supportsEventNotification = false,
        .hidden = true,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 17,
    },  
    .callbacks = {
        .handleRead = NULL,
        .handleWrite = HandleSiliconLabsHomekitOTADataWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'SiliconLabsOTAServiceSignatureCharacteristic' characteristic of the 'siliconLabsOTAService' service.
 */
const HAPDataCharacteristic SiliconLabsOTAServiceSignatureCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 903,
    .characteristicType = &kHAPCharacteristicType_SiliconLabsOTAServiceSignatureCharacteristic,
    .debugDescription = "ServiceSignature",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = true,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 2097152,
    },  
    .callbacks = {
        .handleRead = HAPHandleServiceSignatureRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'threadManagementServiceSignatureCharacteristic' characteristic of the 'threadManagementService' service.
 */
const HAPDataCharacteristic threadManagementServiceSignatureCharacteristic = {
    .format = kHAPCharacteristicFormat_Data,
    .iid = 601,
    .characteristicType = &kHAPCharacteristicType_threadManagementServiceSignatureCharacteristic,
    .debugDescription = "ThreadManagement",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 2097152,
    },  
    .callbacks = {
        .handleRead = HAPHandleServiceSignatureRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'threadManagementOpenThreadVersionCharacteristic' characteristic of the 'threadManagementService' service.
 */
const HAPStringCharacteristic threadManagementOpenThreadVersionCharacteristic = {
    .format = kHAPCharacteristicFormat_String,
    .iid = 602,
    .characteristicType = &kHAPCharacteristicType_threadManagementOpenThreadVersionCharacteristic,
    .debugDescription = "ThreadManagementOpenThreadVersion",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = true,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    }, 
    .constraints = {
        .maxLength = 128,
    },  
    .callbacks = {
        .handleRead = HAPPlatformSetupHandleOpenThreadVersionRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'threadManagementControlCharacteristic' characteristic of the 'threadManagementService' service.
 */
const HAPTLV8Characteristic threadManagementControlCharacteristic = {
    .format = kHAPCharacteristicFormat_TLV8,
    .iid = 603,
    .characteristicType = &kHAPCharacteristicType_threadManagementControlCharacteristic,
    .debugDescription = "ThreadManagementControl",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = true,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = true,
        .writeRequiresAdminPermissions = true,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = true,
            .supportsWriteResponse = true,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },   
    .callbacks = {
        .handleRead = HAPHandleThreadManagementControlRead,
        .handleWrite = HAPHandleThreadManagementControlWrite,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'threadManagementNodeCapabilitiesCharacteristic' characteristic of the 'threadManagementService' service.
 */
const HAPUInt16Characteristic threadManagementNodeCapabilitiesCharacteristic = {
    .format = kHAPCharacteristicFormat_UInt16,
    .iid = 604,
    .characteristicType = &kHAPCharacteristicType_threadManagementNodeCapabilitiesCharacteristic,
    .debugDescription = "ThreadManagementNodeCapabilities",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = true,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },
    .units = kHAPCharacteristicUnits_None,
     
    .constraints = {
        .minimumValue = 0,
        .maximumValue = 31,
        .stepValue = 1,
    },  
    .callbacks = {
        .handleRead = HAPHandleThreadManagementNodeCapabilitiesRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'threadManagementStatusCharacteristic' characteristic of the 'threadManagementService' service.
 */
const HAPUInt16Characteristic threadManagementStatusCharacteristic = {
    .format = kHAPCharacteristicFormat_UInt16,
    .iid = 605,
    .characteristicType = &kHAPCharacteristicType_threadManagementStatusCharacteristic,
    .debugDescription = "ThreadManagementStatus",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = true,
        .hidden = false,
        .readRequiresAdminPermissions = true,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = true,
            .supportsDisconnectedNotification = true,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },
    .units = kHAPCharacteristicUnits_None,
     
    .constraints = {
        .minimumValue = 0,
        .maximumValue = 127,
        .stepValue = 1,
    },  
    .callbacks = {
        .handleRead = HAPHandleThreadManagementStatusRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};

 
/**
 * The 'threadManagementCurrentTransportCharacteristic' characteristic of the 'threadManagementService' service.
 */
const HAPBoolCharacteristic threadManagementCurrentTransportCharacteristic = {
    .format = kHAPCharacteristicFormat_Bool,
    .iid = 606,
    .characteristicType = &kHAPCharacteristicType_threadManagementCurrentTransportCharacteristic,
    .debugDescription = "CurrentTransport",
    .manufacturerDescription = "",
    .properties = {
        .readable = true,
        .writable = false,
        .supportsEventNotification = false,
        .hidden = false,
        .readRequiresAdminPermissions = false,
        .writeRequiresAdminPermissions = false,
        .requiresTimedWrite = false,
        .supportsAuthorizationData = false,
        .ip = {
            .controlPoint = false,
            .supportsWriteResponse = false,
        },
        .ble = {
            .supportsBroadcastNotification = false,
            .supportsDisconnectedNotification = false,
            .readableWithoutSecurity = false,
            .writableWithoutSecurity = false 
        },
    },   
    .callbacks = {
        .handleRead = HAPHandleThreadManagementCurrentTransportRead,
        .handleWrite = NULL,
        .handleSubscribe = NULL,
        .handleUnsubscribe = NULL,
    }
};


//-----------------------------------
/**
 * Services - definition
 */

/**
 * The DynoDesk_Light service.
 */
const HAPService DynoDesk_Light = {
    .iid = 60,
    .serviceType = &kHAPServiceType_DynoDesk_Light,
    .debugDescription = "LightBulb",
    .name = "DynoDesk_Light",
    .properties = {
        .primaryService = true,
        .hidden = false,
        .ble = {
            .supportsConfiguration = false,
        },
    },
    .linkedServices = (uint16_t const[]) {0},
    .characteristics = (const HAPCharacteristic* const[]) {
        &lightBulbServiceSignatureCharacteristic,
        &lightBulbNameCharacteristic,
        &lightBulbOnCharacteristic,
        &lightBulbBrightnessCharacteristic,
        NULL
    }
};

/**
 * The accessoryRuntimeInformationService service.
 */
const HAPService accessoryRuntimeInformationService = {
    .iid = 3,
    .serviceType = &kHAPServiceType_accessoryRuntimeInformationService,
    .debugDescription = "AccessoryRuntimeInformation",
    .name = "accessoryRuntimeInformationService",
    .properties = {
        .primaryService = false,
        .hidden = false,
        .ble = {
            .supportsConfiguration = false,
        },
    },
    .linkedServices = (uint16_t const[]) {0},
    .characteristics = (const HAPCharacteristic* const[]) {
        &accessoryRuntimeInformationServiceSignatureCharacteristic,
        &accessoryRuntimeInformationSleepIntervalCharacteristic,
        &accessoryRuntimeInformationPingCharacteristic,
        &accessoryRuntimeInformationHeartBeatCharacteristic,
        NULL
    }
};

/**
 * The accessoryInformationService service.
 */
const HAPService accessoryInformationService = {
    .iid = 1,
    .serviceType = &kHAPServiceType_accessoryInformationService,
    .debugDescription = "AccessoryInformation",
    .name = "accessoryInformationService",
    .properties = {
        .primaryService = false,
        .hidden = false,
        .ble = {
            .supportsConfiguration = false,
        },
    },
    .linkedServices = (uint16_t const[]) {0},
    .characteristics = (const HAPCharacteristic* const[]) {
        &accessoryInformationIdentifyCharacteristic,
        &accessoryInformationManufacturerCharacteristic,
        &accessoryInformationModelCharacteristic,
        &accessoryInformationNameCharacteristic,
        &accessoryInformationSerialNumberCharacteristic,
        &accessoryInformationFirmwareRevisionCharacteristic,
        &accessoryInformationHardwareRevisionCharacteristic,
        &accessoryInformationADKVersionCharacteristic,
        &accessoryInformationProductDataCharacteristic,
        NULL
    }
};

/**
 * The pairingService service.
 */
const HAPService pairingService = {
    .iid = 4,
    .serviceType = &kHAPServiceType_pairingService,
    .debugDescription = "Pairing",
    .name = "pairingService",
    .properties = {
        .primaryService = false,
        .hidden = false,
        .ble = {
            .supportsConfiguration = false,
        },
    },
    .linkedServices = (uint16_t const[]) {0},
    .characteristics = (const HAPCharacteristic* const[]) {
        &pairingPairSetupCharacteristic,
        &pairingPairVerifyCharacteristic,
        &pairingPairingFeaturesCharacteristic,
        &pairingPairingPairingsCharacteristic,
        NULL
    }
};

/**
 * The hapProtocolInformationService service.
 */
const HAPService hapProtocolInformationService = {
    .iid = 5,
    .serviceType = &kHAPServiceType_hapProtocolInformationService,
    .debugDescription = "HAPProtocolInformation",
    .name = "hapProtocolInformationService",
    .properties = {
        .primaryService = false,
        .hidden = false,
        .ble = {
            .supportsConfiguration = true,
        },
    },
    .linkedServices = (uint16_t const[]) {0},
    .characteristics = (const HAPCharacteristic* const[]) {
        &hapProtocolInformationServiceSignatureCharacteristic,
        &hapProtocolInformationVersionCharacteristic,
        NULL
    }
};

/**
 * The siliconLabsOTAService service.
 */
const HAPService siliconLabsOTAService = {
    .iid = 9,
    .serviceType = &kHAPServiceType_siliconLabsOTAService,
    .debugDescription = "SiliconLabsOTA",
    .name = "siliconLabsOTAService",
    .properties = {
        .primaryService = false,
        .hidden = true,
        .ble = {
            .supportsConfiguration = false,
        },
    },
    .linkedServices = (uint16_t const[]) {0},
    .characteristics = (const HAPCharacteristic* const[]) {
        &SiliconLabsOTAControlCharacteristic,
        &SiliconLabsOTADataCharacteristic,
        &SiliconLabsOTAServiceSignatureCharacteristic,
        NULL
    }
};

/**
 * The threadManagementService service.
 */
const HAPService threadManagementService = {
    .iid = 6,
    .serviceType = &kHAPServiceType_threadManagementService,
    .debugDescription = "ThreadManagement",
    .name = "threadManagementService",
    .properties = {
        .primaryService = false,
        .hidden = false,
        .ble = {
            .supportsConfiguration = false,
        },
    },
    .linkedServices = (uint16_t const[]) {0},
    .characteristics = (const HAPCharacteristic* const[]) {
        &threadManagementServiceSignatureCharacteristic,
        &threadManagementOpenThreadVersionCharacteristic,
        &threadManagementControlCharacteristic,
        &threadManagementNodeCapabilitiesCharacteristic,
        &threadManagementStatusCharacteristic,
        &threadManagementCurrentTransportCharacteristic,
        NULL
    }
};
 
