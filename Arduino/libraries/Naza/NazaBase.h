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

#ifndef NAZA_BASE_INCLUDE
#define NAZA_BASE_INCLUDE

#include <vector>       // https://github.com/maniacbug/StandardCplusplus

#include "Arduino.h"

class NazaBase
{
    public:
        typedef struct __attribute__((packed))
        {
            int32_t latitude;
            int32_t longitude;
            
            int32_t latitudeHome;
            int32_t longitudeHome;
            int32_t altitudeHome;

            int32_t altitudeBarometer;
            int32_t altitudeGps;

            int16_t speed;
            int16_t climbSpeedBarometer;
            int16_t climbSpeedGps;

            uint8_t satellitesVisible;
            uint8_t fixType;

            uint16_t course;
            uint16_t heading;
            uint16_t headingNc;

            uint16_t hdop;
            uint16_t vdop;

            int8_t pitch;
            int8_t roll;


            uint16_t voltageBattery;
            uint16_t currentBattery;
            uint16_t consumedBattery;
            uint8_t flightMode;

            int16_t rcA;
            int16_t rcE;
            int16_t rcR;
            int16_t rcU;
            int16_t rcT;
            int16_t rcX1;
            int16_t rcX2;

            uint16_t m1;
            uint16_t m2;
            uint16_t m3;
            uint16_t m4;
            uint16_t m5;
            uint16_t m6;
            uint16_t f1;
            uint16_t f2;

            uint32_t tmUpdate;
            uint32_t tmMotorOn;
            uint32_t tmMotorOff;
            boolean isMotorOn;
        } NazaData_t;

        NazaBase();
        virtual ~NazaBase();
        
        static void updateFromNazaCanDecoder();

        static void setLatitude(int32_t latitude);
        static void setLongitude(int32_t longitude);

        static void setLatitudeHome(int32_t latitude);
        static void setLongitudeHome(int32_t longitude);
        static void setAltitudeHome(int32_t altitude);

        static void setAltitudeBarometer(int32_t altitude);
        static void setAltitudeGps(int32_t altitude);

        static void setSpeed(int16_t speed);
        static void setClimbSpeedBarometer(int16_t speed);
        static void setClimbSpeedGps(int16_t speed);

        static void setSatellitesVisible(uint8_t satellites);
        static void setFixType(uint8_t fixType);

        static void setCourse(uint16_t course);
        static void setHeading(uint16_t heading);
        static void setHeadingNc(uint16_t heading);

        static void setHdop(uint16_t hdop);
        static void setVdop(uint16_t vdop);

        static void setPitch(int8_t pitch);
        static void setRoll(int8_t roll);

        static void setVoltageBattery(uint16_t voltage);
        static void setCurrentBattery(uint16_t current);
        static void setConsumedBattery(uint16_t consumed);
        static void setFlightMode(uint8_t flightmode);

        static void setRCInput(int16_t rcA, int16_t rcE, int16_t rcR, int16_t rcU, int16_t rcT, int16_t rcX1, int16_t rcX2);
        static void setMotorOutput(uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4, uint16_t m5, uint16_t m6, uint16_t f1, uint16_t f2);

        static NazaData_t& getData ();

    private:
        static std::vector<NazaBase*> m_listener;

    protected:
        static NazaData_t m_data;

        static void registerListener (NazaBase *pListener);

        virtual void onLatitudeChanged();
        virtual void onLongitudeChanged();
        virtual void onLatitudeHomeChanged();
        virtual void onLongitudeHomeChanged();
        virtual void onAltitudeHomeChanged();
        virtual void onAltitudeBarometerChanged();
        virtual void onAltitudeGpsChanged();
        virtual void onSpeedChanged();
        virtual void onClimbSpeedBarometerChanged();
        virtual void onClimbSpeedGpsChanged();
        virtual void onSatellitesVisibleChanged();
        virtual void onFixTypeChanged();
        virtual void onCourseChanged();
        virtual void onHeadingChanged();
        virtual void onHeadingNcChanged();
        virtual void onHdopChanged();
        virtual void onVdopChanged();
        virtual void onPitchChanged();
        virtual void onRollChanged();
        virtual void onVoltageBatteryChanged();
        virtual void onCurrentBatteryChanged();
        virtual void onConsumedBatteryChanged();
        virtual void onFlightModeChanged();
        virtual void onRCInputChanged();
        virtual void onMotorOutputChanged();
};

#endif