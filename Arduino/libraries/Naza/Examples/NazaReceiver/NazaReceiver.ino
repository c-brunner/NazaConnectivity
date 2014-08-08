//    Copyright (C) 2014  Christian Brunner
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "BGLib.h"              // https://github.com/jrowberg/bglib
#include "EEPROM.h"             // http://arduino.cc/de/Reference/EEPROM
#include "FlexCAN.h"            // https://github.com/teachop/FlexCAN_Library
#include "i2c_t3.h"             // http://forum.pjrc.com/threads/21680-New-I2C-library-for-Teensy3
#include "SD.h"                 // http://arduino.cc/de/Reference/SD
#include "NazaCanDecoderLib.h"  // http://www.rcgroups.com/forums/showthread.php?t=2071772
#include "mavlink.h"            // https://pixhawk.ethz.ch/mavlink/

#include "NazaBLE.h"
#include "NazaOLED.h"
#include "SeeedOLED.h"

#define SERIAL_RF Serial1
BGLib ble112(&Serial3, 0, 1);
NazaBLE nazaBLE = NazaBLE();
NazaOLED nazaOLED = NazaOLED();

#define LED_PIN         13  // Arduino Uno LED pin
#define BLE_WAKEUP_PIN  14  // BLE wake-up pin
#define BLE_RESET_PIN   14  // BLE reset pin (active-low)

void setup()
{
    // initialize Radio Wireless Telemetry Air 433Mhz Module / HM-TRP Series 100mW Transceiver modules V1.0 (http://www.hoperf.com/upload/rf_app/HM-TRP.pdf)
    SERIAL_RF.begin(57600);

    // initialize Grove - OLED Display 1.12 (http://www.seeedstudio.com/wiki/Grove_-_OLED_Display_128*64)
    nazaOLED.setup();

    // initialize BLE112 Bluetooth Low Energy (https://www.bluegiga.com/evaluation_BLE112, http://www.inmojo.com/store/jeff-rowberg/item/ble112-bluetooth-low-energy-breakout/)
    nazaBLE.setup(&ble112, BLE_RESET_PIN, BLE_WAKEUP_PIN, LED_PIN);
    nazaBLE.bleCheckActivity();
}

void loop()
{
    // keep polling for new data from BLE
    nazaBLE.bleCheckActivity();

    // keep polling for new data from MAVLink
    receiveMAVLinkMessage();
}

void receiveMAVLinkMessage()
{
    mavlink_message_t msg;
    mavlink_status_t status;
 
    while(SERIAL_RF.available() > 0 ) 
    {
        uint8_t c = SERIAL_RF.read();

        if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status))
        {
            switch(msg.msgid)
            {
                case MAVLINK_MSG_ID_DJI_SYSTEM_STATUS:
                    {
                        NazaBase::setLatitude(mavlink_msg_dji_system_status_get_latitude(&msg));
                        NazaBase::setLongitude(mavlink_msg_dji_system_status_get_longitude(&msg));
                        NazaBase::setLatitudeHome(mavlink_msg_dji_system_status_get_latitudeHome(&msg));
                        NazaBase::setLongitudeHome(mavlink_msg_dji_system_status_get_longitudeHome(&msg));
                        NazaBase::setAltitudeHome(mavlink_msg_dji_system_status_get_altitudeHome(&msg));
                        NazaBase::setAltitudeBarometer(mavlink_msg_dji_system_status_get_altitudeBarometer(&msg));
                        NazaBase::setAltitudeGps(mavlink_msg_dji_system_status_get_altitudeGps(&msg));
                        NazaBase::setSpeed(mavlink_msg_dji_system_status_get_speed(&msg));
                        NazaBase::setClimbSpeedBarometer(mavlink_msg_dji_system_status_get_climbSpeedBarometer(&msg));
                        NazaBase::setClimbSpeedGps(mavlink_msg_dji_system_status_get_climbSpeedGps(&msg));
                        NazaBase::setSatellitesVisible(mavlink_msg_dji_system_status_get_satellitesVisible(&msg));
                        NazaBase::setFixType(mavlink_msg_dji_system_status_get_fixType(&msg));
                        NazaBase::setCourse(mavlink_msg_dji_system_status_get_course(&msg));
                        NazaBase::setHeading(mavlink_msg_dji_system_status_get_heading(&msg));
                        NazaBase::setHeadingNc(mavlink_msg_dji_system_status_get_headingNc(&msg));
                        NazaBase::setHdop(mavlink_msg_dji_system_status_get_hdop(&msg));
                        NazaBase::setVdop(mavlink_msg_dji_system_status_get_vdop(&msg));
                        NazaBase::setPitch(mavlink_msg_dji_system_status_get_pitch(&msg));
                        NazaBase::setRoll(mavlink_msg_dji_system_status_get_roll(&msg));
                        NazaBase::setVoltageBattery(mavlink_msg_dji_system_status_get_voltageBattery(&msg));
                        NazaBase::setCurrentBattery(mavlink_msg_dji_system_status_get_currentBattery(&msg));
                        NazaBase::setConsumedBattery(mavlink_msg_dji_system_status_get_consumedBattery(&msg));
                        NazaBase::setFlightMode(mavlink_msg_dji_system_status_get_flightMode(&msg));
                    }
                    break;

                case MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS:
                    {
                        NazaBase::setRCInput(mavlink_msg_dji_rc_motor_status_get_rcA(&msg),
                                             mavlink_msg_dji_rc_motor_status_get_rcE(&msg),
                                             mavlink_msg_dji_rc_motor_status_get_rcR(&msg),
                                             mavlink_msg_dji_rc_motor_status_get_rcU(&msg),
                                             mavlink_msg_dji_rc_motor_status_get_rcT(&msg),
                                             mavlink_msg_dji_rc_motor_status_get_rcX1(&msg),
                                             mavlink_msg_dji_rc_motor_status_get_rcX2(&msg));
                                            
                        NazaBase::setMotorOutput(mavlink_msg_dji_rc_motor_status_get_m1(&msg),
                                                 mavlink_msg_dji_rc_motor_status_get_m2(&msg),
                                                 mavlink_msg_dji_rc_motor_status_get_m3(&msg),
                                                 mavlink_msg_dji_rc_motor_status_get_m4(&msg),
                                                 mavlink_msg_dji_rc_motor_status_get_m5(&msg),
                                                 mavlink_msg_dji_rc_motor_status_get_m6(&msg),
                                                 mavlink_msg_dji_rc_motor_status_get_f1(&msg),
                                                 mavlink_msg_dji_rc_motor_status_get_f2(&msg));
                    }
                    break;
    
                default:
                    // ignore all other messages
		    break;
            }
        }
    }
}
       
       
       

