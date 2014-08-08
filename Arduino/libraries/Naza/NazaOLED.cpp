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

#include "NazaOLED.h"

static unsigned char iOSD_Altitude_HomeDistance [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x01, 0x01, 0x82, 0xC6, 0x7C, 0x00, 0x00, 0x00,
0x00, 0x0E, 0x14, 0xF4, 0x14, 0x04, 0x85, 0x05, 0x05, 0x05, 0x04, 0x04, 0x84, 0x04, 0x0E, 0x00,
0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x08, 0x08, 0x08, 0x08, 0x08, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_VerticalSpeed [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_VerticalSpeedDown [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x04, 0x0C, 0x1C, 0x3C, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0x3C, 0x1C, 0x0C, 0x04, 0x00
};

static unsigned char iOSD_VerticalSpeedUp [] = {
0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00,
0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};

static unsigned char iOSD_Battery_0 [] = {
0x00, 0x00, 0xF0, 0x10, 0x10, 0x1C, 0x14, 0x14, 0x1C, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Battery_1 [] = {
0x00, 0x00, 0xF0, 0x10, 0x10, 0x1C, 0x14, 0x14, 0x1C, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Battery_2 [] = {
0x00, 0x00, 0xF0, 0x10, 0x10, 0x1C, 0x14, 0x14, 0x1C, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Battery_3 [] = {
0x00, 0x00, 0xF0, 0x10, 0x10, 0x1C, 0x14, 0x14, 0x1C, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Battery_4 [] = {
0x00, 0x00, 0xF0, 0x10, 0x10, 0x1C, 0x14, 0x14, 0x1C, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Battery_5 [] = {
0x00, 0x00, 0xF0, 0x10, 0x10, 0x1C, 0x14, 0x14, 0x1C, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Battery_6 [] = {
0x00, 0x00, 0xF0, 0x10, 0x50, 0x5C, 0x54, 0x54, 0x5C, 0x50, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Satellites_0 [] = {
0x00, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x07, 0x1F, 0xFF, 0xFE, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0,
0x00, 0x00, 0x00, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Satellites_1 [] = {
0x00, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x07, 0x1F, 0xFF, 0xFE, 0xFC, 0xF9, 0xF9, 0xF3, 0xF2, 0xE6, 0xE0, 0xE0, 0xC0, 0xC0,
0x00, 0x00, 0x00, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Satellites_2 [] = {
0x00, 0xE0, 0xC0, 0x80, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xC0, 0x80, 0x80, 0x00, 0x00,
0x00, 0x01, 0x07, 0x1F, 0xFF, 0xFE, 0xFC, 0xF9, 0xF9, 0xF3, 0xF2, 0xE6, 0xE0, 0xEF, 0xC0, 0xC0,
0x00, 0x00, 0x00, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Satellites_3 [] = {
0x00, 0xE0, 0xC0, 0x80, 0x10, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0xD0, 0x90, 0xB0, 0x20, 0xE0,
0x00, 0x01, 0x07, 0x1F, 0xFF, 0xFE, 0xFC, 0xF9, 0xF9, 0xF3, 0xF2, 0xE6, 0xE0, 0xEF, 0xC0, 0xDF,
0x00, 0x00, 0x00, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char iOSD_Speed [] = {
0x00, 0x0F, 0x01, 0x4F, 0x41, 0x6F, 0x60, 0x18, 0x04, 0x04, 0x02, 0xBA, 0xA8, 0xE8, 0x00, 0x00
};

static char buffer[8];
NazaOLED::NazaOLED() : NazaBase()
{
    m_climbAltitudeStatus = -1;
    m_satellitesVisibleStatus = -1;
    m_voltageBatteryStatus = -1;
    m_homeDistance = -1;
}

NazaOLED::~NazaOLED()
{
}

void NazaOLED::setup()
{
    Wire.begin();	
    SeeedOled.init();  //initialze SEEED OLED display
    DDRB|=0x21;         
    PORTB |= 0x21;

    SeeedOled.clearDisplay();

    drawStaticHUD();

    onLatitudeChanged();
    onAltitudeBarometerChanged();
    onSpeedChanged();
    onClimbSpeedBarometerChanged();
    onSatellitesVisibleChanged();
    onFixTypeChanged();
    onVoltageBatteryChanged();
    onFlightModeChanged();

    registerListener (this);
}

void NazaOLED::onLatitudeChanged()
{
    /*
    calculateDistanceToHome(m_data.latitude, m_data.longitude,
                            m_data.latitudeHome, m_data.longitudeHome);
    */
}

void NazaOLED::onLongitudeChanged()
{
    /*
    calculateDistanceToHome(m_data.latitude, m_data.longitude,
                            m_data.latitudeHome, m_data.longitudeHome);
    */
}

void NazaOLED::onLatitudeHomeChanged()
{
}

void NazaOLED::onLongitudeHomeChanged()
{
}

void NazaOLED::onAltitudeHomeChanged()
{
}

void NazaOLED::onAltitudeBarometerChanged()
{
    sprintf(buffer, "%5.1f\0", (m_data.altitudeBarometer - m_data.altitudeHome) / 1000.0);
    SeeedOled.setTextXY(5,2);
    SeeedOled.putString(buffer);
}

void NazaOLED::onAltitudeGpsChanged()
{
}

void NazaOLED::onSpeedChanged()
{
    sprintf(buffer, "%5.2f\0", m_data.speed / 100.0);
    SeeedOled.setTextXY(3,9);
    SeeedOled.putString(buffer);
}

void NazaOLED::onClimbSpeedBarometerChanged()
{
    if (m_data.climbSpeedBarometer > 0)
        setAltitudeStatus(NazaOLED::ALTITUDE_UP);
    else if (m_data.climbSpeedBarometer < 0)
        setAltitudeStatus(NazaOLED::ALTITUDE_DOWN);
    else
        setAltitudeStatus(NazaOLED::ALTITUDE_HOLD);

    sprintf(buffer, "%5.2f\0", m_data.climbSpeedBarometer / 100.0);
    SeeedOled.setTextXY(5,9);
    SeeedOled.putString(buffer);
}

void NazaOLED::setAltitudeStatus(uint8_t climbAltitudeStatus)
{
    if (m_climbAltitudeStatus != climbAltitudeStatus)
    {
        m_climbAltitudeStatus = climbAltitudeStatus;

        if (m_climbAltitudeStatus == NazaOLED::ALTITUDE_UP)
            drawBitmap(4, 14, &iOSD_VerticalSpeedUp[0], 2);
        else if (m_climbAltitudeStatus == NazaOLED::ALTITUDE_DOWN)
            drawBitmap(4, 14, &iOSD_VerticalSpeedDown[0], 2);
        else if (m_climbAltitudeStatus == NazaOLED::ALTITUDE_HOLD)
            drawBitmap(4, 14, &iOSD_VerticalSpeed[0], 2);
    }
}

void NazaOLED::onClimbSpeedGpsChanged()
{
}

void NazaOLED::onSatellitesVisibleChanged()
{
    if (m_data.satellitesVisible > 5)
        setSatellitesVisibleStatus(NazaOLED::SATELLITE_3);
    else if (m_data.satellitesVisible >= 2)
        setSatellitesVisibleStatus(NazaOLED::SATELLITE_2);
    else if (m_data.satellitesVisible == 1)
        setSatellitesVisibleStatus(NazaOLED::SATELLITE_1);
    else
        setSatellitesVisibleStatus(NazaOLED::SATELLITE_0);

    sprintf(buffer, "%2d\0", m_data.satellitesVisible);
    SeeedOled.setTextXY(1,12);
    SeeedOled.putString(buffer);
}

void NazaOLED::setSatellitesVisibleStatus(uint8_t satellitesVisibleStatus)
{
    if (m_satellitesVisibleStatus != satellitesVisibleStatus)
    {
        m_satellitesVisibleStatus = satellitesVisibleStatus;

        if (m_satellitesVisibleStatus == NazaOLED::SATELLITE_0)
            drawBitmap(0, 14, &iOSD_Satellites_0[0], 3);
        else if (m_satellitesVisibleStatus == NazaOLED::SATELLITE_1)
            drawBitmap(0, 14, &iOSD_Satellites_1[0], 3);
        else if (m_satellitesVisibleStatus == NazaOLED::SATELLITE_2)
            drawBitmap(0, 14, &iOSD_Satellites_2[0], 3);
        else if (m_satellitesVisibleStatus == NazaOLED::SATELLITE_3)
            drawBitmap(0, 14, &iOSD_Satellites_3[0], 3);
    }
}

void NazaOLED::onFixTypeChanged()
{
    SeeedOled.setTextXY(7,11);

     if (m_data.fixType == 0)
        SeeedOled.putString("none");
    else if (m_data.fixType == 2)
        SeeedOled.putString(" 2D");
    else if (m_data.fixType == 3)
        SeeedOled.putString(" 3D");
    else if (m_data.fixType == 4)
        SeeedOled.putString("DGPS");
}

void NazaOLED::onCourseChanged()
{
}

void NazaOLED::onHeadingChanged()
{
}

void NazaOLED::onHeadingNcChanged()
{
}

void NazaOLED::onHdopChanged()
{
}

void NazaOLED::onVdopChanged()
{
}

void NazaOLED::onPitchChanged()
{
}

void NazaOLED::onRollChanged()
{
}

void NazaOLED::onVoltageBatteryChanged()
{
    if (m_data.voltageBattery > 12000)
        setVoltageBatteryStatus(NazaOLED::BATTERY_6);
    else if (m_data.voltageBattery > 11750)
        setVoltageBatteryStatus(NazaOLED::BATTERY_5);
    else if (m_data.voltageBattery > 11500)
        setVoltageBatteryStatus(NazaOLED::BATTERY_4);
    else if (m_data.voltageBattery > 11250)
        setVoltageBatteryStatus(NazaOLED::BATTERY_3);
    else if (m_data.voltageBattery > 11000)
        setVoltageBatteryStatus(NazaOLED::BATTERY_2);
    else if (m_data.voltageBattery > 10750)
        setVoltageBatteryStatus(NazaOLED::BATTERY_1);
    else
        setVoltageBatteryStatus(NazaOLED::BATTERY_0);

    sprintf(buffer, "%4.1f\0", m_data.voltageBattery / 1000.0);
    SeeedOled.setTextXY(1,2);
    SeeedOled.putString(buffer);
}

void NazaOLED::setVoltageBatteryStatus(uint8_t voltageBatteryStatus)
{
    if (m_voltageBatteryStatus != voltageBatteryStatus)
    {
        m_voltageBatteryStatus = voltageBatteryStatus;

        if (m_voltageBatteryStatus == NazaOLED::BATTERY_0)
            drawBitmap(0, 0, &iOSD_Battery_0[0], 3);
        else if (m_voltageBatteryStatus == NazaOLED::BATTERY_1)
            drawBitmap(0, 0, &iOSD_Battery_1[0], 3);
        else if (m_voltageBatteryStatus == NazaOLED::BATTERY_2)
            drawBitmap(0, 0, &iOSD_Battery_2[0], 3);
        else if (m_voltageBatteryStatus == NazaOLED::BATTERY_3)
            drawBitmap(0, 0, &iOSD_Battery_3[0], 3);
        else if (m_voltageBatteryStatus == NazaOLED::BATTERY_4)
            drawBitmap(0, 0, &iOSD_Battery_4[0], 3);
        else if (m_voltageBatteryStatus == NazaOLED::BATTERY_5)
            drawBitmap(0, 0, &iOSD_Battery_5[0], 3);
        else if (m_voltageBatteryStatus == NazaOLED::BATTERY_6)
            drawBitmap(0, 0, &iOSD_Battery_6[0], 3);
    }
}

void NazaOLED::onCurrentBatteryChanged()
{
}

void NazaOLED::onConsumedBatteryChanged()
{
}

void NazaOLED::onFlightModeChanged()
{
    SeeedOled.setTextXY(7,1);

    if (m_data.flightMode == 0)
        SeeedOled.putString("MANUAL");
    else if (m_data.flightMode == 1)
        SeeedOled.putString("GPS   ");
    else if (m_data.flightMode == 2)
        SeeedOled.putString("FSAFE ");
    else if (m_data.flightMode == 3)
        SeeedOled.putString("ATTI  ");
}

void NazaOLED::onRCInputChanged()
{
}

void NazaOLED::onMotorOutputChanged()
{
}

void NazaOLED::setHomeDistance(int32_t homeDistance)
{
    if (m_homeDistance != homeDistance)
    {
        m_homeDistance = homeDistance;

        sprintf(buffer, "%5.1f\0", homeDistance / 1000.0);
        SeeedOled.setTextXY(5,2);
        SeeedOled.putString(buffer);
    }
}

void NazaOLED::calculateDistanceToHome(int32_t latitude, int32_t longitude, int32_t latitudeHome, int32_t longitudeHome)
{
    double lat1 = latitude / 10000000.0;
    double lon1 = longitude / 10000000.0;
    double lat2 = latitudeHome / 10000000.0;
    double lon2 = longitudeHome / 10000000.0;

    double R = 6371.0;
    double pi = 3.14159265359;

    double x1 = lat1 * pi / 180.0;
    double x2 = lat2 * pi / 180.0;
    
    double y1 = (lat2-lat1) * pi / 180;
    double y2 = (lon2-lon1) * pi / 180;
    
    double a = sin(y1/2) * sin(y1/2) +
               cos(x1) * cos(x2) *
               sin(y2/2) * sin(y2/2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    int32_t homeDistance = R * c * 1000.0 * 1000.0;

    setHomeDistance(homeDistance);
}

void NazaOLED::drawStaticHUD()
{

    drawBitmap(3, 0, &iOSD_Altitude_HomeDistance[0], 3);

    drawBitmap(3, 14, &iOSD_Speed[0], 1);
}

void NazaOLED::drawBitmap (unsigned char row, unsigned char column, unsigned char* picture, unsigned char size)
{
    for (unsigned char idx = 0; idx < size; idx++)
    {
        SeeedOled.setTextXY(row++,column);
        SeeedOled.drawBitmap(picture, 16);
        
        picture += sizeof(unsigned char) * 16;
    }
}
