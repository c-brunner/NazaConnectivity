//
//  F550DynamicFlightData.m
//  F550 Dynamic Flight Data
//
//  Created by Christian Brunner on 20/06/14.
//  Copyright (c) 2014 Christian Brunner. All rights reserved.
//

#import "F550DynamicFlightData.h"

#import <iOS-GPX-Framework/GPX.h>

#define F550DFD_GENERIC_ACCESS_SRV      @"1800"
    #define F550DFD_DEVICE_NAME_ATTR    @"2A00"
    #define F550DFD_APPEARANCE_ATTR     @"2A01"

#define F550DFD_DEVICE_INFORMATION_SRV          @"180A"
    #define F550DFD_MANUFACTURER_NAME_ATTR      @"2A29"
    #define F550DFD_MODEL_NUMBER                @"2A24"

#define F550DFD_DATA_TRANSCEIVER_SRV    @"195AE58A-437A-489B-B0CD-AABBCCDD0000"
    #define F550DFD_RX_ATTR             @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD0000"
    #define F550DFD_TX_ATTR             @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD0001"

#define F550DFD_DATA_GPS_SRV            @"195AE58A-437A-489B-B0CD-AABBCCDD1000"
    #define ATTR_LATITUDE               @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1000"
    #define ATTR_LONGITUDE              @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1001"
    #define ATTR_LATITUDE_HOME          @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1002"
    #define ATTR_LONGITUDE_HOME         @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1003"
    #define ATTR_ALTITUDE_HOME          @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1004"
    #define ATTR_ALTITUDE_BAROMETER     @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1005"
    #define ATTR_ALTITUDE_GPS           @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1006"
    #define ATTR_SPEED                  @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1007"
    #define ATTR_CLIMB_SPEED_BAROMETER  @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1008"
    #define ATTR_CLIMB_SPEED_GPS        @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1009"
    #define ATTR_SATELLITES_VISIBLE     @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1010"
    #define ATTR_FIX_TYPE               @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1011"
    #define ATTR_COURSE                 @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1012"
    #define ATTR_HEADING                @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1013"
    #define ATTR_HEADING_NC             @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1014"
    #define ATTR_HDOP                   @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1015"
    #define ATTR_VDOP                   @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1016"
    #define ATTR_PITCH                  @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1017"
    #define ATTR_ROLL                   @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1018"
    #define ATTR_VOLTAGE_BATTERY        @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1019"
    #define ATTR_CURRENT_BATTERY        @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1020"
    #define ATTR_CONSUMED_BATTERY       @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1021"
    #define ATTR_FLIGHT_MODE            @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD1022"
    #define ATTR_RC_INPUT               @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD2023"
    #define ATTR_MOTOR_OUTPUT           @"5FC569A0-74A9-4FA4-B8B7-AABBCCDD2024"


#define POLARH7_HRM_DEVICE_INFO_SERVICE_UUID @"180A"       // 180A = Device Information
#define POLARH7_HRM_HEART_RATE_SERVICE_UUID @"180D"        // 180D = Heart Rate Service
#define POLARH7_HRM_ENABLE_SERVICE_UUID @"2A39"
#define POLARH7_HRM_NOTIFICATIONS_SERVICE_UUID @"2A37"
#define POLARH7_HRM_BODY_LOCATION_UUID @"2A38"
#define POLARH7_HRM_MANUFACTURER_NAME_UUID @"2A29"


@implementation F550DynamicFlightData


#pragma mark Singleton Methods

+ (id)sharedDynamicFlightData {
    static F550DynamicFlightData *sharedDynamicFlightData = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedDynamicFlightData = [[self alloc] init];

    });
    return sharedDynamicFlightData;
}

- (id)init {
    if (self = [super init])
    {
        self.centralManager = [[CBCentralManager alloc] initWithDelegate:self queue:nil];

        self.synthesizer = [[AVSpeechSynthesizer alloc] init];
        
        self.isConnected = false;

        // service attr uuids
        self.attrLatitude = [CBUUID UUIDWithString:ATTR_LATITUDE];
        self.attrLongitude = [CBUUID UUIDWithString:ATTR_LONGITUDE];
        self.attrLatitudeHome = [CBUUID UUIDWithString:ATTR_LATITUDE_HOME];
        self.attrLongitudeHome = [CBUUID UUIDWithString:ATTR_LONGITUDE_HOME];
        self.attrAltitudeHome = [CBUUID UUIDWithString:ATTR_ALTITUDE_HOME];
        self.attrAltitudeBarometer = [CBUUID UUIDWithString:ATTR_ALTITUDE_BAROMETER];
        self.attrAltitudeGps = [CBUUID UUIDWithString:ATTR_ALTITUDE_GPS];
        self.attrSpeed = [CBUUID UUIDWithString:ATTR_SPEED];
        self.attrClimbSpeedBarometer = [CBUUID UUIDWithString:ATTR_CLIMB_SPEED_BAROMETER];
        self.attrClimbSpeedGps = [CBUUID UUIDWithString:ATTR_CLIMB_SPEED_GPS];
        self.attrSatellitesVisible = [CBUUID UUIDWithString:ATTR_SATELLITES_VISIBLE];
        self.attrFixType = [CBUUID UUIDWithString:ATTR_FIX_TYPE];
        self.attrCourse = [CBUUID UUIDWithString:ATTR_COURSE];
        self.attrHeading = [CBUUID UUIDWithString:ATTR_HEADING];
        self.attrHeadingNc = [CBUUID UUIDWithString:ATTR_HEADING_NC];
        self.attrHdop = [CBUUID UUIDWithString:ATTR_HDOP];
        self.attrVdop = [CBUUID UUIDWithString:ATTR_VDOP];
        self.attrPitch = [CBUUID UUIDWithString:ATTR_PITCH];
        self.attrRoll = [CBUUID UUIDWithString:ATTR_ROLL];
        self.attrVoltageBattery = [CBUUID UUIDWithString:ATTR_VOLTAGE_BATTERY];
        self.attrCurrentBattery = [CBUUID UUIDWithString:ATTR_CURRENT_BATTERY];
        self.attrConsumedBattery = [CBUUID UUIDWithString:ATTR_CONSUMED_BATTERY];
        self.attrFlightMode = [CBUUID UUIDWithString:ATTR_FLIGHT_MODE];
        self.attrRcInput = [CBUUID UUIDWithString:ATTR_RC_INPUT];
        self.attrMotorOutput = [CBUUID UUIDWithString:ATTR_MOTOR_OUTPUT];
        
        //
        self.voiceBattery = 0;
        self.voiceHeight = 0;
        self.voiceFlightMode = 0;
        self.voiceFix = 0;

    }
    return self;
}

- (void)dealloc {
    // Should never be called, but just here for clarity really.
}

-(void)scanForDynamicFlightData
{
	// Scan for all available CoreBluetooth LE devices
	
     NSArray *services = @[
                            [CBUUID UUIDWithString:F550DFD_DATA_TRANSCEIVER_SRV],
                            [CBUUID UUIDWithString:F550DFD_DATA_GPS_SRV]
                          ];
    
    [self.centralManager scanForPeripheralsWithServices:services options:nil];
}

// method called whenever the device state changes.
- (void)centralManagerDidUpdateState:(CBCentralManager *)central
{
	// Determine the state of the peripheral
	if ([central state] == CBCentralManagerStatePoweredOff)
    {
		NSLog(@"CoreBluetooth BLE hardware is powered off");
	}
	else if ([central state] == CBCentralManagerStatePoweredOn)
    {
		NSLog(@"CoreBluetooth BLE hardware is powered on and ready");
        [self scanForDynamicFlightData];
	}
	else if ([central state] == CBCentralManagerStateUnauthorized)
    {
		NSLog(@"CoreBluetooth BLE state is unauthorized");
	}
	else if ([central state] == CBCentralManagerStateUnknown)
    {
		NSLog(@"CoreBluetooth BLE state is unknown");
	}
	else if ([central state] == CBCentralManagerStateUnsupported)
    {
		NSLog(@"CoreBluetooth BLE hardware is unsupported on this platform");
	}
}

// method called whenever we have successfully connected to the BLE peripheral
- (void)centralManager:(CBCentralManager *)central didConnectPeripheral:(CBPeripheral *)peripheral
{
	[peripheral setDelegate:self];
    [peripheral discoverServices:nil];

    AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:@"drone connected"];
    utterance.rate = (AVSpeechUtteranceDefaultSpeechRate - AVSpeechUtteranceMinimumSpeechRate) / 2.0;

    [self.synthesizer speakUtterance:utterance];

    NSLog(@"device %@ disconnected", peripheral.identifier);
    
    self.isConnected = true;
}

- (void)centralManager:(CBCentralManager *)central didDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;
{
    self.isConnected = false;
    
    NSLog(@"device %@ connected", peripheral.identifier);
    
    AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:@"drone disconnected"];
    utterance.rate = (AVSpeechUtteranceDefaultSpeechRate - AVSpeechUtteranceMinimumSpeechRate) / 2.0;

    [self.synthesizer speakUtterance:utterance];

    [self scanForDynamicFlightData];
}

// CBPeripheralDelegate - Invoked when you discover the peripheral's available services.
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverServices:(NSError *)error
{
	for (CBService *service in peripheral.services)
    {
        NSLog(@"found service %@", service.UUID);
		[peripheral discoverCharacteristics:nil forService:service];
	}
}

// CBCentralManagerDelegate - This is called with the CBPeripheral class as its main input parameter. This contains most of the information there is to know about a BLE peripheral.
- (void)centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI
{
	NSString *localName = [advertisementData objectForKey:CBAdvertisementDataLocalNameKey];
	if (![localName isEqual:@""])
    {
		// We found the Heart Rate Monitor
		[self.centralManager stopScan];
		self.dynamicFlightDataPeripheral = peripheral;
		peripheral.delegate = self;
		[self.centralManager connectPeripheral:peripheral options:nil];
	}
}

// Invoked when you discover the characteristics of a specified service.
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverCharacteristicsForService:(CBService *)service error:(NSError *)error
{
    if ([service.UUID isEqual:[CBUUID UUIDWithString:F550DFD_DATA_GPS_SRV]])
    {
        for (CBCharacteristic *aChar in service.characteristics)
        {
            NSLog(@"uuid: %@", aChar.UUID);
            if ([aChar.UUID isEqual:[self attrLatitude]] ||
                [aChar.UUID isEqual:[self attrLongitude]] ||
                [aChar.UUID isEqual:[self attrLatitudeHome]] ||
                [aChar.UUID isEqual:[self attrLongitudeHome]] ||
                [aChar.UUID isEqual:[self attrAltitudeHome]] ||
                [aChar.UUID isEqual:[self attrAltitudeBarometer]] ||
                [aChar.UUID isEqual:[self attrAltitudeGps]] ||
                [aChar.UUID isEqual:[self attrSpeed]] ||
                [aChar.UUID isEqual:[self attrClimbSpeedBarometer]] ||
                [aChar.UUID isEqual:[self attrClimbSpeedGps]] ||
                [aChar.UUID isEqual:[self attrSatellitesVisible]] ||
                [aChar.UUID isEqual:[self attrFixType]] ||
                [aChar.UUID isEqual:[self attrCourse]] ||
                [aChar.UUID isEqual:[self attrHeading]] ||
                [aChar.UUID isEqual:[self attrHeadingNc]] ||
                [aChar.UUID isEqual:[self attrHdop]] ||
                [aChar.UUID isEqual:[self attrVdop]] ||
                [aChar.UUID isEqual:[self attrPitch]] ||
                [aChar.UUID isEqual:[self attrRoll]] ||
                [aChar.UUID isEqual:[self attrVoltageBattery]] ||
                [aChar.UUID isEqual:[self attrCurrentBattery]] ||
                [aChar.UUID isEqual:[self attrConsumedBattery]] ||
                [aChar.UUID isEqual:[self attrFlightMode]] ||
                [aChar.UUID isEqual:[self attrRcInput]] ||
                [aChar.UUID isEqual:[self attrMotorOutput]])
            {
                [self.dynamicFlightDataPeripheral readValueForCharacteristic:aChar];
                [self.dynamicFlightDataPeripheral setNotifyValue:YES forCharacteristic:aChar];
            }
        }
    }
	else if ([service.UUID isEqual:[CBUUID UUIDWithString:F550DFD_DEVICE_INFORMATION_SRV]])
    {
        for (CBCharacteristic *aChar in service.characteristics)
        {
            if ([aChar.UUID isEqual:[CBUUID UUIDWithString:F550DFD_MANUFACTURER_NAME_ATTR]] ||
                [aChar.UUID isEqual:[CBUUID UUIDWithString:F550DFD_MODEL_NUMBER]]) {
                [self.dynamicFlightDataPeripheral readValueForCharacteristic:aChar];
            }
        }
	}
    else if ([service.UUID isEqual:[CBUUID UUIDWithString:F550DFD_GENERIC_ACCESS_SRV]])
    {
        for (CBCharacteristic *aChar in service.characteristics)
        {
            if ([aChar.UUID isEqual:[CBUUID UUIDWithString:F550DFD_DEVICE_NAME_ATTR]] ||
                [aChar.UUID isEqual:[CBUUID UUIDWithString:F550DFD_APPEARANCE_ATTR]])
            {
                [self.dynamicFlightDataPeripheral readValueForCharacteristic:aChar];
            }
        }
    }
}

-(int32_t)getInt32FromData:(NSData *)data
{
    int32_t value;
    assert([data length] == sizeof(value));
    memcpy(&(value), [data bytes], sizeof(value));

    return value;
}

-(uint16_t)getUInt16FromData:(NSData *)data
{
    uint16_t value;
    assert([data length] == sizeof(value));
    memcpy(&(value), [data bytes], sizeof(value));
    
    return value;
}

-(uint8_t)getUInt8FromData:(NSData *)data
{
    uint8_t value;
    assert([data length] == sizeof(value));
    memcpy(&(value), [data bytes], sizeof(value));
    
    return value;
}

-(int16_t)getInt16FromData:(NSData *)data
{
    int16_t value;
    assert([data length] == sizeof(value));
    memcpy(&(value), [data bytes], sizeof(value));
    
    return value;
}

-(int16_t)getInt16FromData:(NSData *)data withIndex:(uint16_t)index
{
    int16_t value;
    memcpy(&(value), [data bytes] + sizeof(value) * index, sizeof(value));
        
    return value;
}

-(uint16_t)getUInt16FromData:(NSData *)data withIndex:(uint16_t)index
{
    uint16_t value;
    memcpy(&(value), [data bytes] + sizeof(value) * index, sizeof(value));
    
    return value;
}

-(int8_t)getInt8FromData:(NSData *)data
{
    int8_t value;
    assert([data length] == sizeof(value));
    memcpy(&(value), [data bytes], sizeof(value));
    
    return value;
}

// Invoked when you retrieve a specified characteristic's value, or when the peripheral device notifies your app that the characteristic's value has changed.
- (void)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error
{
    /*if ([characteristic.UUID isEqual:[self attrManufacturerName]])
    {
        self.manufacturerName = [[NSString alloc] initWithData:characteristic.value encoding:NSUTF8StringEncoding];
    }
    else if ([characteristic.UUID isEqual:[self attrModelNumber]])
    {
        self.modelNumber  = [[NSString alloc] initWithData:characteristic.value encoding:NSUTF8StringEncoding];
    }*/
    if ([characteristic.UUID isEqual:[self attrLatitude]])
    {
        int32_t value = [self getInt32FromData:characteristic.value];
        if (self.latitude != value)
            self.latitude = value;
    }
    else if ([characteristic.UUID isEqual:[self attrLongitude]])
    {
        int32_t value = [self getInt32FromData:characteristic.value];
        if (self.longitude != value)
            self.longitude = value;
    }
    else if ([characteristic.UUID isEqual:[self attrLatitudeHome]])
    {
        int32_t value = [self getInt32FromData:characteristic.value];
        if (self.latitudeHome != value)
            self.latitudeHome = value;
    }
    else if ([characteristic.UUID isEqual:[self attrLongitudeHome]])
    {
        int32_t value = [self getInt32FromData:characteristic.value];
        if (self.longitudeHome != value)
            self.longitudeHome = value;
    }
    else if ([characteristic.UUID isEqual:[self attrAltitudeHome]])
    {
        int32_t value = [self getInt32FromData:characteristic.value];
        if (self.altitudeHome != value)
            self.altitudeHome = value;
    }
    else if ([characteristic.UUID isEqual:[self attrAltitudeBarometer]])
    {
        int32_t value = [self getInt32FromData:characteristic.value];
        if (self.altitudeBarometer != value)
        {
            self.altitudeBarometer = value;
            self.altitudeRelative = self.altitudeBarometer - self.altitudeHome;
        }
        
        [self CheckAltitude];
    }
    else if ([characteristic.UUID isEqual:[self attrAltitudeGps]])
    {
        int32_t value = [self getInt32FromData:characteristic.value];
        if (self.altitudeGps != value)
            self.altitudeGps = value;
    }
    else if ([characteristic.UUID isEqual:[self attrSpeed]])
    {
        int16_t value = [self getInt16FromData:characteristic.value];
        if (self.speed != value)
            self.speed = value;
    }
    else if ([characteristic.UUID isEqual:[self attrClimbSpeedBarometer]])
    {
        int16_t value = [self getInt16FromData:characteristic.value];
        if (self.climbSpeedBarometer != value)
            self.climbSpeedBarometer = value;
    }
    else if ([characteristic.UUID isEqual:[self attrClimbSpeedGps]])
    {
        int16_t value = [self getInt16FromData:characteristic.value];
        if (self.climbSpeedGps != value)
            self.climbSpeedGps = value;
    }
    else if ([characteristic.UUID isEqual:[self attrSatellitesVisible]])
    {
        uint8_t value = [self getUInt8FromData:characteristic.value];
        if (self.satellitesVisible != value)
            self.satellitesVisible = value;
    }
    else if ([characteristic.UUID isEqual:[self attrFixType]])
    {
        uint8_t value = [self getUInt8FromData:characteristic.value];
        if (self.fixType != value)
            self.fixType = value;
        
        [self CheckFixType];
    }
    else if ([characteristic.UUID isEqual:[self attrCourse]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.course != value)
            self.course = value;
    }
    else if ([characteristic.UUID isEqual:[self attrHeading]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.heading != value)
            self.heading = value;
    }
    else if ([characteristic.UUID isEqual:[self attrHeadingNc]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.headingNc != value)
            self.headingNc = value;
    }
    else if ([characteristic.UUID isEqual:[self attrHdop]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.hdop != value)
            self.hdop = value;
    }
    else if ([characteristic.UUID isEqual:[self attrVdop]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.vdop != value)
            self.vdop = value;
    }
    else if ([characteristic.UUID isEqual:[self attrPitch]])
    {
        int8_t value = [self getInt8FromData:characteristic.value];
        if (self.pitch != value)
            self.pitch = value;
    }
    else if ([characteristic.UUID isEqual:[self attrRoll]])
    {
        int8_t value = [self getInt8FromData:characteristic.value];
        if (self.roll != value)
            self.roll = value;
    }
    else if ([characteristic.UUID isEqual:[self attrVoltageBattery]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.voltageBattery != value)
            self.voltageBattery = value;
        
        [self CheckVoltageBattery];
    }
    else if ([characteristic.UUID isEqual:[self attrCurrentBattery]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.currentBattery != value)
            self.currentBattery = value;
    }
    else if ([characteristic.UUID isEqual:[self attrConsumedBattery]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value];
        if (self.consumedBattery != value)
            self.consumedBattery = value;
    }
    else if ([characteristic.UUID isEqual:[self attrFlightMode]])
    {
        uint8_t value = [self getUInt8FromData:characteristic.value];
        if (self.flightMode != value)
            self.flightMode = value;
    }
    else if ([characteristic.UUID isEqual:[self attrRcInput]])
    {
        int16_t value = [self getInt16FromData:characteristic.value withIndex:0];
        if (self.rcA != value)
            self.rcA = value;

        value = [self getInt16FromData:characteristic.value withIndex:1];
        if (self.rcE != value)
            self.rcE = value;

        value = [self getInt16FromData:characteristic.value withIndex:2];
        if (self.rcR != value)
            self.rcR = value;

        value = [self getInt16FromData:characteristic.value withIndex:3];
        if (self.rcU != value)
            self.rcU = value;

        value = [self getInt16FromData:characteristic.value withIndex:4];
        if (self.rcT != value)
            self.rcT = value;

        value = [self getInt16FromData:characteristic.value withIndex:5];
        if (self.rcX1 != value)
            self.rcX1 = value;

        value = [self getInt16FromData:characteristic.value withIndex:6];
        if (self.rcX2 != value)
            self.rcX2 = value;
}
    else if ([characteristic.UUID isEqual:[self attrMotorOutput]])
    {
        uint16_t value = [self getUInt16FromData:characteristic.value withIndex:0];
        if (self.m1 != value)
            self.m1 = value;

        value = [self getUInt16FromData:characteristic.value withIndex:1];
        if (self.m2 != value)
            self.m2 = value;
        
        value = [self getUInt16FromData:characteristic.value withIndex:2];
        if (self.m3 != value)
            self.m3 = value;

        value = [self getUInt16FromData:characteristic.value withIndex:3];
        if (self.m4 != value)
            self.m4 = value;

        value = [self getUInt16FromData:characteristic.value withIndex:4];
        if (self.m5 != value)
            self.m5 = value;

        value = [self getUInt16FromData:characteristic.value withIndex:5];
        if (self.m6 != value)
            self.m6 = value;

        value = [self getUInt16FromData:characteristic.value withIndex:6];
        if (self.f1 != value)
            self.f1 = value;

        value = [self getUInt16FromData:characteristic.value withIndex:7];
        if (self.f2 != value)
            self.f2 = value;
}
}

-(void)CheckVoltageBattery
{
    if (self.voltageBattery < 11000)
    {
        time_t tmNow = (time_t) [[NSDate date] timeIntervalSince1970];
        if (tmNow - self.voiceBattery > 15)
        {
            AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:[[NSString alloc] initWithFormat:@"Low battery %.2f volt", self.voltageBattery / 1000.0f]];
            utterance.rate = (AVSpeechUtteranceDefaultSpeechRate - AVSpeechUtteranceMinimumSpeechRate) / 2.0;
            [self.synthesizer speakUtterance:utterance];
            
            self.voiceBattery = tmNow;
        }
    }
}


-(void)CheckAltitude
{
    time_t tmNow = (time_t) [[NSDate date] timeIntervalSince1970];
    if (tmNow - self.voiceHeight > 20)
    {
        AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:[[NSString alloc] initWithFormat:@"Altitude %.0f meter", self.altitudeRelative / 1000.0f]];
        utterance.rate = (AVSpeechUtteranceDefaultSpeechRate - AVSpeechUtteranceMinimumSpeechRate) / 2.0;
        [self.synthesizer speakUtterance:utterance];
        
        self.voiceHeight = tmNow;
    }
}

-(void)CheckFixType
{
    time_t tmNow = (time_t) [[NSDate date] timeIntervalSince1970];
    if (tmNow - self.voiceFix > 0)
    {
        NSString* fixText = @"Fix unknown";
        if (self.fixType == 0)
            fixText = @"No fix";
        else if (self.fixType == 2)
            fixText = @"Fix 2D";
        else if (self.fixType == 3)
            fixText = @"Fix 3D";
        else if (self.fixType == 4)
            fixText = @"Fix DGPS";

        AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:fixText];
        utterance.rate = (AVSpeechUtteranceDefaultSpeechRate - AVSpeechUtteranceMinimumSpeechRate) / 2.0;
        [self.synthesizer speakUtterance:utterance];
            
        self.voiceFix = tmNow;
    }
}


-(void)CheckFlightMode
{
    time_t tmNow = (time_t) [[NSDate date] timeIntervalSince1970];
    if (tmNow - self.voiceFlightMode > 0)
    {
        NSString* flightModeText = @"Flightmode unknown";
        if (self.flightMode == 0)
            flightModeText = @"Flightmode manual";
        else if (self.flightMode == 1)
            flightModeText = @"Flightmode GPS";
        else if (self.flightMode == 2)
            flightModeText = @"Flightmode failsafe";
        else if (self.flightMode == 3)
            flightModeText = @"Flightmode altitude";
            
        AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:flightModeText];
        utterance.rate = (AVSpeechUtteranceDefaultSpeechRate - AVSpeechUtteranceMinimumSpeechRate) / 2.0;
        [self.synthesizer speakUtterance:utterance];
            
        self.voiceFlightMode = tmNow;
    }
}

-(void)loadGPX:(NSString *)fileName
{
    self.fixType = 4;
    
    GPXRoot *root = [GPXParser parseGPXAtPath:fileName];
    for (unsigned long idxTrack = 0; idxTrack < root.tracks.count; idxTrack++)
    {
        GPXTrack* track = [root.tracks objectAtIndex:idxTrack];
        for (unsigned long idxTrackSegment = 0; idxTrackSegment < track.tracksegments.count; idxTrackSegment++)
        {
            GPXTrackSegment* trackSegment = [track.tracksegments objectAtIndex:idxTrackSegment];
            for (unsigned long idxTrackPoint = 0; idxTrackPoint < trackSegment.trackpoints.count; idxTrackPoint++)
            {
                GPXTrackPoint* trackPoint = [trackSegment.trackpoints objectAtIndex:idxTrackPoint];
                _latitude = trackPoint.latitude * 10000000.0f;
                self.longitude = trackPoint.longitude * 10000000.0f;
            }
        }
    }
}

@end
