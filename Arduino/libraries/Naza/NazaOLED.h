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

#ifndef NAZA_OLED_INCLUDE
#define NAZA_OLED_INCLUDE

#include <i2c_t3.h>     // http://forum.pjrc.com/threads/21680-New-I2C-library-for-Teensy3
#include <SeeedOLED.h>  // https://github.com/Seeed-Studio/Grove_OLED_Display_128X64

#include "NazaBase.h"

class NazaOLED : public NazaBase
{
    public:
     typedef enum { ALTITUDE_UP = 0, ALTITUDE_DOWN = 1, ALTITUDE_HOLD = 2 } AltitudeStatus_t;
     typedef enum { SATELLITE_0 = 0, SATELLITE_1 = 1, SATELLITE_2 = 2, SATELLITE_3 = 3 } SateliteStatus_t;
     typedef enum { BATTERY_0 = 0, BATTERY_1 = 1, BATTERY_2 = 2, BATTERY_3 = 3, BATTERY_4 = 4, BATTERY_5 = 5, BATTERY_6 = 6 } BatteryStatus_t;

        NazaOLED();
        ~NazaOLED();
        
        void setup();

        void setHomeDistance(int32_t homeDistance);
        void calculateDistanceToHome(int32_t latitude, int32_t longitude, int32_t latitudeHome, int32_t longitudeHome);

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

    private:

        void drawStaticHUD();
        void drawBitmap (unsigned char row, unsigned char column, unsigned char* picture, unsigned char size);

        void setAltitudeStatus(uint8_t climbAltitudeStatus);
        void setSatellitesVisibleStatus(uint8_t satellitesVisibleStatus);
        void setVoltageBatteryStatus(uint8_t voltageBatteryStatus);

        uint8_t m_climbAltitudeStatus;
        uint8_t m_satellitesVisibleStatus;
        uint8_t m_voltageBatteryStatus;
        int32_t m_homeDistance;

    protected:
};

#endif