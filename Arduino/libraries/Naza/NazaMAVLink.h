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

#ifndef NAZA_MAVLINK_INCLUDE
#define NAZA_MAVLINK_INCLUDE

#include <mavlink.h>            // https://pixhawk.ethz.ch/mavlink/
#include <HardwareSerial.h>     // http://arduino.cc/de/Reference/Serial

#include "NazaBase.h"

class NazaMAVLink : public NazaBase
{
    public:
        NazaMAVLink();
        virtual ~NazaMAVLink();
        
        void setup(HardwareSerial* serial);
    
        void sendDjiSystemStatus();
        void sendDjiRcMotorStatus();

        void receiveMessages();
        
    private:
        
        HardwareSerial* m_serial;
        
        uint8_t m_buffer[MAVLINK_MAX_PACKET_LEN];

        int m_sysid;
        int m_type;
        int m_compid;
        uint8_t m_autopilot_type;
        uint8_t m_system_mode;
        uint32_t m_custom_mode;
        uint8_t m_system_state;

    protected:
};

#endif