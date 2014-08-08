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

#include <i2c_t3.h>  // http://forum.pjrc.com/threads/21680-New-I2C-library-for-Teensy3

#include "NazaSpektrum.h"

NazaSpektrum* NazaSpektrum::m_receiver;

NazaSpektrum::NazaSpektrum () : NazaBase()
{
    registerReceiver(this);

    memset(&m_a03_current,0,16);
    m_a03_current.address = 0x03;

    memset(&m_a0a_powerbox,0,16);
    m_a0a_powerbox.address = 0x0A;

    memset(&m_a11_airspeed,0,16);
    m_a11_airspeed.address = 0x11;
    m_a11_airspeed.O1 = 0x01; // kmh
    m_a11_airspeed.f9 = 0xF9;

    memset(&m_a12_altitude,0,16);
    m_a12_altitude.address = 0x12;
    m_a12_altitude.ff = 0xFF;

    /*
    memset(&m_a14_gforce,0,16);
    m_a14_gforce.address = 0x14;

    memset(&m_a16_gps,0,16);
    m_a16_gps.address = 0x16;

    memset(&m_a17_gps,0,16);
    m_a17_gps.address = 0x17;

    memset(&m_a40_vario,0,16);
    m_a40_vario.address = 0x40;
    */
}

NazaSpektrum::~NazaSpektrum ()
{
}

int16_t swapBytes(int16_t value)
{
    byte hiByte = (value & 0xff00) >> 8;
    byte loByte = (value & 0xff);    
    return loByte << 8 | hiByte;
}

void NazaSpektrum::registerReceiver (NazaSpektrum* receiver)
{
    m_receiver = receiver;
}

NazaSpektrum* NazaSpektrum::getReceiver ()
{
    return m_receiver;
}

void NazaSpektrum::setup ()
{
    // Setup for Slave mode, addresses 0x08 to 0x77, pins 18/19, external pullups, 400kHz
    Wire.begin(I2C_SLAVE, 0x03, 0x70, I2C_PINS_18_19, I2C_PULLUP_EXT, I2C_RATE_100);

    // register events
    Wire.onReceive(spektrumReceiveEvent);
    Wire.onRequest(spektrumRequestEvent);

    NazaBase::setConsumedBattery(0);

    registerListener (this);
}

void NazaSpektrum::onLatitudeChanged()
{
}

void NazaSpektrum::onLongitudeChanged()
{

}

void NazaSpektrum::onLatitudeHomeChanged()
{
}

void NazaSpektrum::onLongitudeHomeChanged()
{
}

void NazaSpektrum::onAltitudeHomeChanged()
{
}

void NazaSpektrum::onAltitudeBarometerChanged()
{
    // Altitude, 1 unit is 0.1m. Displays -3276.8m to 3276.7m, alarm values between -300m and 1000m
    m_a12_altitude.altitude = swapBytes((m_data.altitudeBarometer - m_data.altitudeHome) / 100);

    // Altitude, 1 unit is 0.1m. Displays -3276.8m to 3276.7m, alarm values between -300m and 1000m
    m_a40_vario.altitude = m_a12_altitude.altitude;
}

void NazaSpektrum::onAltitudeGpsChanged()
{
}

void NazaSpektrum::onSpeedChanged()
{
    // MSB,LSB
    // 1 unit is 1 km/h. Displays up to 65535 km/h, maximum alarm value 563 km/h
    m_a11_airspeed.airspeed = swapBytes(m_data.speed / 100 * 3.6);
}

void NazaSpektrum::onClimbSpeedBarometerChanged()
{
}

void NazaSpektrum::onClimbSpeedGpsChanged()
{
}

void NazaSpektrum::onSatellitesVisibleChanged()
{
}

void NazaSpektrum::onFixTypeChanged()
{
}

void NazaSpektrum::onCourseChanged()
{
}

void NazaSpektrum::onHeadingChanged()
{
}

void NazaSpektrum::onHeadingNcChanged()
{
}

void NazaSpektrum::onHdopChanged()
{
}

void NazaSpektrum::onVdopChanged()
{
}

void NazaSpektrum::onPitchChanged()
{
}

void NazaSpektrum::onRollChanged()
{
}

void NazaSpektrum::onVoltageBatteryChanged()
{
    // MSB,LSB
    // Voltage1, 1 unit is 0.01V
    m_a0a_powerbox.voltage1 = swapBytes(m_data.voltageBattery / 1000.0 / 0.01);
    m_a0a_powerbox.voltage2 = 0;
}

void NazaSpektrum::onCurrentBatteryChanged()
{
    // MSB,LSB
    // Current, 1 unit is 0.1967A, maximum alarm value 200A
    m_a03_current.current = swapBytes(m_data.currentBattery / 1000.0 / 0.196791);
}

void NazaSpektrum::onConsumedBatteryChanged()
{
    // MSB,LSB
    // Capacity1, 1 unit is 1mAh
    m_a0a_powerbox.capacity1 = swapBytes(m_data.consumedBattery / 1000.0 / 0.001);
    m_a0a_powerbox.capacity2 = 0;
}

void NazaSpektrum::onFlightModeChanged()
{
}

void NazaSpektrum::onRCInputChanged()
{
}

void NazaSpektrum::onMotorOutputChanged()
{
}

void NazaSpektrum::onReceiveEvent(size_t len)
{
    while(Wire.available())
    {
        Wire.readByte();
    }
}

void NazaSpektrum::onRequestEvent(void)
{
    Serial.println((int)Wire.getRxAddr());

    uint8_t address = Wire.getRxAddr();
    if (address == 0x03)
    {
        Wire.write((const uint8_t*)&m_a03_current, 16);
    }
    else if (address == 0x0A)
    {
        Wire.write((const uint8_t*)&m_a0a_powerbox, 16);        
    }
    else if (address == 0x11)
    {
        Wire.write((const uint8_t*)&m_a11_airspeed, 16);        
    }
    else if (address == 0x12)
    {
        Wire.write((const uint8_t*)&m_a12_altitude, 16);        
    }
    /*else if (address == 0x16)
    {
        Wire.write((const uint8_t*)&m_a16_gps, 16);        
    }*/
    /*else if (address == 0x17)
    {
        Wire.write((const uint8_t*)&m_a17_gps, 16);        
    }*/
    /*else if (address == 0x40)
    {
        Wire.write((const uint8_t*)&m_a40_vario, 16);        
    }*/
}

//
// handle Rx Event (incoming I2C request/data)
//
void spektrumReceiveEvent(size_t len)
{
    NazaSpektrum::getReceiver()->onReceiveEvent(len);
}

//
// handle Tx Event (outgoing I2C data)
//
void spektrumRequestEvent(void)
{
    NazaSpektrum::getReceiver()->onRequestEvent();
}