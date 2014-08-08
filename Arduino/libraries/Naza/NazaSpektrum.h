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

#ifndef NAZA_SPEKTRUM_INCLUDE
#define NAZA_SPEKTRUM_INCLUDE

#include "NazaBase.h"

void spektrumReceiveEvent(size_t len);
void spektrumRequestEvent(void);

class NazaSpektrum : public NazaBase
{
    public:
        NazaSpektrum();
        virtual ~NazaSpektrum();
        
        void setup();

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

        void onReceiveEvent(size_t len);
        void onRequestEvent(void);
    
        static NazaSpektrum* getReceiver ();

        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero01;
            int16_t current; // Current, 1 unit is 0.1967A, maximum alarm value 200A
            byte zero04;
            byte zero05;
            byte zero06;
            byte zero07;
            byte zero08;
            byte zero09;
            byte zero10;
            byte zero11;
            byte zero12;
            byte zero13;
            byte zero14;
            byte zero15;
        } A03_Current;


        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero01;
            int16_t voltage1;  // Voltage1, 1 unit is 0.01V
            int16_t voltage2;  // Voltage1, 2 unit is 0.01V
            int16_t capacity1; // Capacity1, 1 unit is 1mAh
            int16_t capacity2; // Capacity2, 1 unit is 1mAh
            byte zero10;
            byte zero11;
            byte zero12;
            byte zero13;
            byte zero14;
            byte alarm;        //  The fist bit is alarm voltage1, the second voltage2, the third capacity1, the 4th capacity2
        } A0A_Powerbox;

        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero01;
            int16_t airspeed; // 1 unit is 1 km/h. Displays up to 65535 km/h, maximum alarm value 563 km/h
            byte O1;
            byte f9;
            byte zero06;
            byte zero07;
            byte zero08;
            byte zero09;
            byte zero10;
            byte zero11;
            byte zero12;
            byte zero13;
            byte zero14;
            byte zero15;
        } A11_Airspeed;

        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero01;
            int16_t altitude; // Altitude, 1 unit is 0.1m. Displays -3276.8m to 3276.7m, alarm values between -300m and 1000m
            byte ff;
            byte zero05;
            byte zero06;
            byte zero07;
            byte zero08;
            byte zero09;
            byte zero10;
            byte zero11;
            byte zero12;
            byte zero13;
            byte zero14;
            byte zero15;
        } A12_Altitude;

        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero01;
            int16_t x; // x, unit is 0.01g
            int16_t y; // y, unit is 0.01g
            int16_t z; // z, unit is 0.01g
            int16_t xMax;
            int16_t yMax;
            int16_t zMax;
            int16_t zMin;
        } A14_GForce;

        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero1;
            int16_t altitude;               // In 0.1m,  Altitude = Altitude(0x17) * 10000 + Value (in 0.1m)
            byte latitude_milliseconds;  // 1/100th of a degree second latitude (Decimal) (XX YY.SSSS)
            byte latitude_seconds;       // degree seconds latitude (Decimal)
            byte latitude_minutes;       // degree minutes latitude (Decimal)
            byte latitude_degrees;       // degrees latitude (Decimal)
            byte longitude_milliseconds; // 1/100th of a degree second longitude (Decimal) (XX YY.SSSS)
            byte longitude_seconds;      // degree seconds longitude (Decimal)
            byte longitude_minutes;      // degree minutes longitude (Decimal)
            byte longitude_degrees;      // degrees longitude (Decimal)
            int16_t heading;             // Heading (Decimal), Divide by 10 for Degrees
            byte unknown;
            byte sign;                   // First bit for latitude: 1=N(+), 0=S(-), Second bit for longitude: 1=E(+), 0=W(-), Third bit for longitude over 99 degrees: 1=+-100 degrees
        } A16_GPS;

        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero01;
            byte speed[0];          // Speed, Divide by 10 for Knots. Multiply by 0.185 for Kph and 0.115 for Mph
            byte time_milliseconds; // UTC Time (Decimal) 1/100th sec. (HH:MM:SS.SS)
            byte time_seconds;      // UTC Time (Decimal) = SS
            byte time_minutes;      // UTC Time (Decimal) = MM
            byte time_hours;        // UTC Time MSB (Decimal) = HH
            byte numberOfSats;      // Number of Sats (Decimal)
            byte altitude;          // Altitude in 1000m (Decimal)
            byte zero10;
            byte zero11;
            byte zero12;
            byte zero13;
            byte zero14;
            byte zero15;
        } A17_GPS;        

        typedef struct /*__attribute__((packed))*/
        {
            byte address;
            byte zero1;
            int16_t altitude;      // Altitude in 0.1m
            int16_t altitude_250;  // altitude change rate in 0.1m during last 250ms
            int16_t altitude_500;  // altitude change rate in 0.1m during last 500ms
            int16_t altitude_1000; // altitude change rate in 0.1m during last 1000ms
            int16_t altitude_1500; // altitude change rate in 0.1m during last 1500ms
            int16_t altitude_2000; // altitude change rate in 0.1m during last 2000ms
            int16_t altitude_3000; // altitude change rate in 0.1m during last 3000ms
        } A40_Vario;

    private:
        static NazaSpektrum* m_receiver;

        static void registerReceiver (NazaSpektrum* receiver);

        A03_Current  m_a03_current;
        A0A_Powerbox m_a0a_powerbox;
        A11_Airspeed m_a11_airspeed;
        A12_Altitude m_a12_altitude;
        A14_GForce   m_a14_gforce;
        A16_GPS      m_a16_gps;
        A17_GPS      m_a17_gps;
        A40_Vario    m_a40_vario;

    protected:
  
};

#endif