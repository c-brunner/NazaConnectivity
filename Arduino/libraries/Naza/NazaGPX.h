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

#ifndef NAZA_GPX_INCLUDE
#define NAZA_GPX_INCLUDE

#include <SD.h>                 // arduino.cc/de/Reference/SD
#include <EEPROM.h>             // http://arduino.cc/de/Reference/EEPROM
#include <NazaCanDecoderLib.h>  // http://www.rcgroups.com/forums/showthread.php?t=2071772

#include "NazaBase.h"

class NazaGPX : public NazaBase
{
    public:
        NazaGPX();
        virtual ~NazaGPX();
        
        void nextFile();
		void writeTrackPoint(const char* dateTime);

		void writeHeader();
		void writeFooter();

    private:
        void open();
        void close();

        void openSim();
        void closeSim();

        File m_log;
        File m_logSim;
        char m_fileName[12];
        char m_fileNameSim[12];

    protected:
};

#endif