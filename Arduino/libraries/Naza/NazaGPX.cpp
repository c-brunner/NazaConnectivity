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

#include "NazaGPX.h"

#define GPX_BEGIN_GPX(fileName) \
	m_log.println("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>"); \
	m_log.println("<gpx xmlns=\"http://www.topografix.com/GPX/1/1\" version=\"1.1\" creator=\"Wikipedia\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd\">"); \
	m_log.println("\t<metadata>"); \
	m_log.print("\t\t<name>"); m_log.print(fileName); m_log.println ("</name>"); \
	m_log.println("\t</metadata>"); \

#define GPX_END_GPX() \
	m_log.println("</gpx>");

#define GPX_BEGIN_TRACK(_name) \
	m_log.println("\t<trk>"); \
	m_log.print("\t\t<name>"); m_log.print(_name); m_log.println("</name>");

#define GPX_END_TRACK() \
	m_log.println("\t</trk>");

#define GPX_BEGIN_TRACKSEGMENT() \
	m_log.println("\t\t<trkseg>");

#define GPX_END_TRACKSEGMENT() \
	m_log.println("\t\t</trkseg>");

#define GPX_BEGIN_TRACKPOINT(_latitude, _longitude) \
	m_log.print("\t\t\t<trkpt lat=\""); m_log.print(_latitude / 10000000.0f, 7); m_log.print("\" lon=\""); m_log.print(_longitude / 10000000.0, 7); m_log.println ("\">");

#define GPX_END_TRACKPOINT() \
	m_log.println("\t\t\t</trkpt>");

#define GPX_ALTITUDE(_altitude) \
	m_log.print("\t\t\t\t<ele>"); m_log.print(_altitude / 1000.0f, 2); m_log.println("</ele>");

#define GPX_SPEED(_speed) \
	m_log.print("\t\t\t\t<speed>"); m_log.print(_speed / 100.0f, 2); m_log.println("</speed>");

#define GPX_DATETIME(_dateTime) \
	m_log.print("\t\t\t\t<time>"); m_log.print(_dateTime); m_log.println("</time>");

#define GPX_COURSE(_course) \
	m_log.print("\t\t\t\t<course>"); m_log.print(_course / 100.0f, 2); m_log.println("</course>");

#define GPX_FIX(_fix) \
	m_log.print("\t\t\t\t<fix>"); m_log.print(_fix); m_log.println("</fix>");

#define GPX_SATELLITES(_satellites) \
	m_log.print("\t\t\t\t<sat>"); m_log.print(_satellites); m_log.println("</sat>");

#define GPX_HDOP(_hdop) \
	m_log.print("\t\t\t\t<hdop>"); m_log.print(_hdop / 100.0f, 2); m_log.println("</hdop>");

#define GPX_VDOP(_vdop) \
	m_log.print("\t\t\t\t<vdop>"); m_log.print(_vdop / 100.0f, 2); m_log.println("</vdop>");

#define GPX_COMMENT(_speed, _verticalSpeed, _altitude, _battery) \
	m_log.print("\t\t\t\t<cmt>altitude: "); m_log.print(_altitude / 1000.0f, 2); \
	m_log.print(", speed: "); m_log.print(_speed / 100.0f, 2); \
	m_log.print(", vertical speed: "); m_log.print(_verticalSpeed / 100.0f, 2); \
	m_log.print(", battery level: "); m_log.print(_battery / 1000.0f, 2); \
	m_log.println("</cmt>");


NazaGPX::NazaGPX() : NazaBase()
{
}

NazaGPX::~NazaGPX()
{
}

void NazaGPX::nextFile()
{
	byte fileNumber = EEPROM.read(0);
	
	if(fileNumber >= 255)
		fileNumber = 0;
  	else
  		fileNumber++;
	
	EEPROM.write(0, fileNumber);
	  
	sprintf(m_fileName, "file%03u.gpx", fileNumber);
	sprintf(m_fileNameSim, "file%03u.sim", fileNumber);
}

void NazaGPX::writeHeader()
{
	open();

	GPX_BEGIN_GPX(m_fileName);
	GPX_BEGIN_TRACK("F550 Flight")
	GPX_BEGIN_TRACKSEGMENT()

	close();
}


void NazaGPX::writeFooter()
{
	open();

	GPX_END_TRACKSEGMENT();
	GPX_END_TRACK()
	GPX_END_GPX();

	close();
}

void NazaGPX::writeTrackPoint(const char* dateTime)
{
	open ();

	GPX_BEGIN_TRACKPOINT(m_data.latitude, m_data.longitude)
		GPX_DATETIME(dateTime)
		GPX_ALTITUDE(m_data.altitudeGps)
		GPX_SPEED(m_data.speed)
		GPX_COURSE(m_data.course)

        switch (m_data.fixType)
        {
          case NazaCanDecoderLib::NO_FIX: GPX_FIX("none") break;
          case NazaCanDecoderLib::FIX_2D: GPX_FIX("2d")   break;
          case NazaCanDecoderLib::FIX_3D: GPX_FIX("3d")   break;
          default:                        GPX_FIX("none") break;
        }

		GPX_SATELLITES(m_data.satellitesVisible)
		GPX_HDOP(m_data.hdop)
		GPX_VDOP(m_data.vdop)
		GPX_COMMENT(m_data.speed, m_data.climbSpeedBarometer, m_data.altitudeGps, m_data.voltageBattery)
	GPX_END_TRACKPOINT()

	close();

	openSim();

		m_logSim.write ((uint8_t*)&m_data, sizeof(NazaBase::NazaData_t));

	closeSim();
}

void NazaGPX::open()
{
	close();

	m_log = SD.open(m_fileName, FILE_WRITE);
}

void NazaGPX::close()
{
	if (m_log)
		m_log.close();
}

void NazaGPX::openSim()
{
	close();

	m_logSim = SD.open(m_fileNameSim, FILE_WRITE);
}

void NazaGPX::closeSim()
{
	if (m_logSim)
		m_logSim.close();
}
