//
//  F550DynamicFlightData.h
//  F550 Dynamic Flight Data
//
//  Created by Christian Brunner on 20/06/14.
//  Copyright (c) 2014 Christian Brunner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVFoundation.h>

@interface F550DynamicFlightData : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>
{
}

@property NSString* manufacturerName;
@property NSString* modelNumber;

@property bool isConnected;

@property int32_t latitude;
@property int32_t longitude;

@property int32_t latitudeHome;
@property int32_t longitudeHome;
@property int32_t altitudeHome;

@property int32_t altitudeBarometer;
@property int32_t altitudeGps;
@property int32_t altitudeRelative;

@property int16_t speed;
@property int16_t climbSpeedBarometer;
@property int16_t climbSpeedGps;

@property uint8_t satellitesVisible;
@property uint8_t fixType;

@property uint16_t course;
@property uint16_t heading;
@property uint16_t headingNc;

@property uint16_t hdop;
@property uint16_t vdop;

@property int8_t pitch;
@property int8_t roll;

@property uint16_t voltageBattery;
@property uint16_t currentBattery;
@property uint16_t consumedBattery;
@property uint8_t flightMode;

@property int16_t rcA;
@property int16_t rcE;
@property int16_t rcR;
@property int16_t rcU;
@property int16_t rcT;
@property int16_t rcX1;
@property int16_t rcX2;

@property uint16_t m1;
@property uint16_t m2;
@property uint16_t m3;
@property uint16_t m4;
@property uint16_t m5;
@property uint16_t m6;
@property uint16_t f1;
@property uint16_t f2;

@property time_t voiceBattery;
@property time_t voiceHeight;
@property time_t voiceFlightMode;
@property time_t voiceFix;



@property CBUUID* attrLatitude;
@property CBUUID* attrLongitude;
@property CBUUID* attrLatitudeHome;
@property CBUUID* attrLongitudeHome;
@property CBUUID* attrAltitudeHome;
@property CBUUID* attrAltitudeBarometer;
@property CBUUID* attrAltitudeGps;
@property CBUUID* attrSpeed;
@property CBUUID* attrClimbSpeedBarometer;
@property CBUUID* attrClimbSpeedGps;
@property CBUUID* attrSatellitesVisible;
@property CBUUID* attrFixType;
@property CBUUID* attrCourse;
@property CBUUID* attrHeading;
@property CBUUID* attrHeadingNc;
@property CBUUID* attrHdop;
@property CBUUID* attrVdop;
@property CBUUID* attrPitch;
@property CBUUID* attrRoll;
@property CBUUID* attrVoltageBattery;
@property CBUUID* attrCurrentBattery;
@property CBUUID* attrConsumedBattery;
@property CBUUID* attrFlightMode;
@property CBUUID* attrRcInput;
@property CBUUID* attrMotorOutput;


@property (nonatomic, strong) CBCentralManager      *centralManager;
@property (nonatomic, strong) CBPeripheral          *dynamicFlightDataPeripheral;
@property (nonatomic, strong) AVSpeechSynthesizer   *synthesizer;

-(void)scanForDynamicFlightData;
-(void)loadGPX:(NSString *)fileName;
+ (id)sharedDynamicFlightData;

@end

