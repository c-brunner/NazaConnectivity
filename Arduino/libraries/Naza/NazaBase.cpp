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

#include <NazaCanDecoderLib.h>  // http://www.rcgroups.com/forums/showthread.php?t=2071772

#include "NazaBase.h"

NazaBase::NazaData_t NazaBase::m_data;
std::vector<NazaBase*> NazaBase::m_listener;

NazaBase::NazaBase()
{
}

NazaBase::~NazaBase()
{
}

void NazaBase::registerListener (NazaBase *pListener)
{
    m_listener.push_back (pListener);
}

NazaBase::NazaData_t& NazaBase::getData ()
{
    return m_data;
}

void NazaBase::updateFromNazaCanDecoder()
{
    NazaBase::setLatitude (NazaCanDecoder.getLat() * 10000000.0);
    NazaBase::setLongitude (NazaCanDecoder.getLon() * 10000000.0);
    NazaBase::setAltitudeBarometer(NazaCanDecoder.getAlt() * 1000.0);
    NazaBase::setAltitudeGps(NazaCanDecoder.getGpsAlt() * 1000.0);
    NazaBase::setSpeed(NazaCanDecoder.getSpeed() * 100.0);
    NazaBase::setClimbSpeedBarometer(NazaCanDecoder.getVsi() * 100.0);
    NazaBase::setClimbSpeedGps(NazaCanDecoder.getGpsVsi() * 100.0);
    NazaBase::setSatellitesVisible(NazaCanDecoder.getNumSat());
    NazaBase::setFixType(NazaCanDecoder.getFixType());
    NazaBase::setCourse(NazaCanDecoder.getCog() * 100.0);
    NazaBase::setHeading(NazaCanDecoder.getHeading() * 100.0);
    NazaBase::setHeadingNc(NazaCanDecoder.getFixType() * 100.0);
    NazaBase::setHdop(NazaCanDecoder.getHdop() * 100.0);
    NazaBase::setVdop(NazaCanDecoder.getVdop() * 100.0);
    NazaBase::setPitch(NazaCanDecoder.getPitch());
    NazaBase::setRoll(NazaCanDecoder.getRoll());
    NazaBase::setVoltageBattery(NazaCanDecoder.getBattery());
    NazaBase::setCurrentBattery(0);
    NazaBase::setConsumedBattery(0);
    NazaBase::setFlightMode(NazaCanDecoder.getMode());
    NazaBase::setRCInput(NazaCanDecoder.getRcIn(NazaCanDecoderLib::RC_A), NazaCanDecoder.getRcIn(NazaCanDecoderLib::RC_E), 
                         NazaCanDecoder.getRcIn(NazaCanDecoderLib::RC_R), NazaCanDecoder.getRcIn(NazaCanDecoderLib::RC_U), 
                         NazaCanDecoder.getRcIn(NazaCanDecoderLib::RC_T), NazaCanDecoder.getRcIn(NazaCanDecoderLib::RC_X1), 
                         NazaCanDecoder.getRcIn(NazaCanDecoderLib::RC_X2));
    NazaBase::setMotorOutput(NazaCanDecoder.getMotorOut(0), NazaCanDecoder.getMotorOut(1), 
                             NazaCanDecoder.getMotorOut(2), NazaCanDecoder.getMotorOut(3), 
                             NazaCanDecoder.getMotorOut(4), NazaCanDecoder.getMotorOut(5),
                             NazaCanDecoder.getMotorOut(6), NazaCanDecoder.getMotorOut(7));

    if (m_data.m1 > 0 || m_data.m2 > 0 ||
        m_data.m3 > 0 || m_data.m4 > 0 ||
        m_data.m5 > 0 || m_data.m6 > 0)
    {
        m_data.tmMotorOff = 0;
        m_data.tmMotorOn += millis() - m_data.tmUpdate;
    }
    else
    {
        m_data.tmMotorOn = 0;
        m_data.tmMotorOff += millis() - m_data.tmUpdate;
    }

    m_data.tmUpdate = millis();

    if (m_data.isMotorOn == false && m_data.tmMotorOn > 3000)
    {
        m_data.isMotorOn = true;

        NazaBase::setLatitudeHome(NazaCanDecoder.getLat() * 10000000.0);
        NazaBase::setLongitudeHome(NazaCanDecoder.getLon() * 10000000.0);
        NazaBase::setAltitudeHome(NazaCanDecoder.getAlt() * 1000.0);
    }
    
    if (m_data.isMotorOn == true && m_data.tmMotorOff > 3000)
        m_data.isMotorOn = false;
}

void NazaBase::setLatitude(int32_t latitude)
{
    if (m_data.latitude != latitude)
    {
        m_data.latitude = latitude;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onLatitudeChanged();
        }
    }
}

void NazaBase::setLongitude(int32_t longitude)
{
    if (m_data.longitude != longitude)
    {
        m_data.longitude = longitude;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onLongitudeChanged();
        }
    }
}

void NazaBase::setLatitudeHome(int32_t latitude)
{
    if (m_data.latitudeHome != latitude)
    {
        m_data.latitudeHome = latitude;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onLatitudeHomeChanged();
        }
    }
}

void NazaBase::setLongitudeHome(int32_t longitude)
{
    if (m_data.longitudeHome != longitude)
    {
        m_data.longitudeHome = longitude;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onLongitudeHomeChanged();
        }
    }
}

void NazaBase::setAltitudeHome(int32_t altitude)
{
    if (m_data.altitudeHome != altitude)
    {
        m_data.altitudeHome = altitude;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onAltitudeHomeChanged();
        }
    }
}

void NazaBase::setAltitudeBarometer(int32_t altitude)
{
    if (m_data.altitudeBarometer != altitude)
    {
        m_data.altitudeBarometer = altitude;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onAltitudeBarometerChanged();
        }
    }
}

void NazaBase::setAltitudeGps(int32_t altitude)
{
    if (m_data.altitudeGps != altitude)
    {
        m_data.altitudeGps = altitude;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onAltitudeGpsChanged();
        }
    }
}

void NazaBase::setSpeed(int16_t speed)
{
    if (m_data.speed != speed)
    {
        m_data.speed = speed;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onSpeedChanged();
        }
    }
}

void NazaBase::setClimbSpeedBarometer(int16_t speed)
{
    if (m_data.climbSpeedBarometer != speed)
    {
        m_data.climbSpeedBarometer = speed;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onClimbSpeedBarometerChanged();
        }
    }
}

void NazaBase::setClimbSpeedGps(int16_t speed)
{
    if (m_data.climbSpeedGps != speed)
    {
        m_data.climbSpeedGps = speed;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onClimbSpeedGpsChanged();
        }
    }
}

void NazaBase::setSatellitesVisible(uint8_t satellites)
{
    if (m_data.satellitesVisible != satellites)
    {
        m_data.satellitesVisible = satellites;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onSatellitesVisibleChanged();
        }
    }
}

void NazaBase::setFixType(uint8_t fixType)
{
    if (m_data.fixType != fixType)
    {
        m_data.fixType = fixType;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onFixTypeChanged();
        }
    }
}

void NazaBase::setCourse(uint16_t course)
{
    if (m_data.course != course)
    {
        m_data.course = course;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onCourseChanged();
        }
   }
}

void NazaBase::setHeading(uint16_t heading)
{
    if (m_data.heading != heading)
    {
        m_data.heading = heading;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onHeadingChanged();
        }
    }
}

void NazaBase::setHeadingNc(uint16_t heading)
{
    if (m_data.headingNc != heading)
    {
        m_data.headingNc = heading;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onHeadingNcChanged();
        }
    }
}

void NazaBase::setHdop(uint16_t hdop)
{
    if (m_data.hdop != hdop)
    {
        m_data.hdop = hdop;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onHdopChanged();
        }
   }
}

void NazaBase::setVdop(uint16_t vdop)
{
    if (m_data.vdop != vdop)
    {
        m_data.vdop = vdop;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onVdopChanged();
        }
    }
}

void NazaBase::setPitch(int8_t pitch)
{
    if (m_data.pitch != pitch)
    {
        m_data.pitch = pitch;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onPitchChanged();
        }
    }
}

void NazaBase::setRoll(int8_t roll)
{
    if (m_data.roll != roll)
    {
        m_data.roll = roll;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onRollChanged();
        }
    }
}

void NazaBase::setVoltageBattery(uint16_t voltage)
{
    if (m_data.voltageBattery != voltage)
    {
        m_data.voltageBattery = voltage;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onVoltageBatteryChanged();
        }
    }
}

void NazaBase::setCurrentBattery(uint16_t current)
{
    if (m_data.currentBattery != current)
    {
        m_data.currentBattery = current;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onCurrentBatteryChanged();
        }
    }
}

void NazaBase::setConsumedBattery(uint16_t consumed)
{
    if (m_data.consumedBattery != consumed)
    {
        m_data.consumedBattery = consumed;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onConsumedBatteryChanged();
        }
    }
}

void NazaBase::setFlightMode(uint8_t flightmode)
{
    if (m_data.flightMode != flightmode)
    {
        m_data.flightMode = flightmode;

        for(size_t idx = 0; idx < m_listener.size(); idx++)
        {
            m_listener[idx]->onFlightModeChanged();
        }
    }
}

void NazaBase::setRCInput(int16_t rcA, int16_t rcE, int16_t rcR, int16_t rcU, int16_t rcT, int16_t rcX1, int16_t rcX2)
{
    m_data.rcA = rcA;
    m_data.rcE = rcE;
    m_data.rcR = rcR;
    m_data.rcU = rcU;
    m_data.rcT = rcT;
    m_data.rcX1 = rcX1;
    m_data.rcX2 = rcX2;

    for(size_t idx = 0; idx < m_listener.size(); idx++)
    {
        m_listener[idx]->onRCInputChanged();
    }
}

void NazaBase::setMotorOutput(uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4, uint16_t m5, uint16_t m6, uint16_t f1, uint16_t f2)
{
    m_data.m1 = m1;
    m_data.m2 = m2;
    m_data.m3 = m3;
    m_data.m4 = m4;
    m_data.m5 = m5;
    m_data.m6 = m6;
    m_data.f1 = f1;
    m_data.f2 = f2;

    for(size_t idx = 0; idx < m_listener.size(); idx++)
    {
        m_listener[idx]->onMotorOutputChanged();
    }
}

void NazaBase::onLatitudeChanged()
{
}

void NazaBase::onLongitudeChanged()
{
}

void NazaBase::onLatitudeHomeChanged()
{
}

void NazaBase::onLongitudeHomeChanged()
{
}

void NazaBase::onAltitudeHomeChanged()
{
}

void NazaBase::onAltitudeBarometerChanged()
{
}

void NazaBase::onAltitudeGpsChanged()
{
}

void NazaBase::onSpeedChanged()
{
}

void NazaBase::onClimbSpeedBarometerChanged()
{
}

void NazaBase::onClimbSpeedGpsChanged()
{
}

void NazaBase::onSatellitesVisibleChanged()
{
}

void NazaBase::onFixTypeChanged()
{
}

void NazaBase::onCourseChanged()
{
}

void NazaBase::onHeadingChanged()
{
}

void NazaBase::onHeadingNcChanged()
{
}

void NazaBase::onHdopChanged()
{
}

void NazaBase::onVdopChanged()
{
}

void NazaBase::onPitchChanged()
{
}

void NazaBase::onRollChanged()
{
}

void NazaBase::onVoltageBatteryChanged()
{
}

void NazaBase::onCurrentBatteryChanged()
{
}

void NazaBase::onConsumedBatteryChanged()
{
}

void NazaBase::onFlightModeChanged()
{
}

void NazaBase::onRCInputChanged()
{
}

void NazaBase::onMotorOutputChanged()
{
}
