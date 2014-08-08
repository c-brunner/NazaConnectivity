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

#include "NazaMAVLink.h"

NazaMAVLink::NazaMAVLink () : NazaBase()
{
    m_sysid = 42;
    m_type = 0;
    m_compid = 0;
    m_autopilot_type = 0; /* Generic autopilot supporting waypoints and other simple navigation commands | */
    m_system_mode = 0; /* System is not ready to fly, booting, calibrating, etc. No flag is set. | */
    m_custom_mode = 0;
    m_system_state = 0; /* System is grounded and on standby. It can be launched any time.*/
}

NazaMAVLink::~NazaMAVLink ()
{
}

void NazaMAVLink::setup (HardwareSerial* serial)
{
    m_serial = serial;
    m_serial->begin(57600);
}

void NazaMAVLink::sendDjiSystemStatus()
{
      // Initialize the required buffers
    mavlink_message_t msg;
    
    // Pack the message
    mavlink_msg_dji_system_status_pack(m_sysid, m_compid, &msg,
                                      m_data.latitude,
                                      m_data.longitude,
                                      m_data.latitudeHome,
                                      m_data.longitudeHome,
                                      m_data.altitudeHome,
                                      m_data.altitudeBarometer,
                                      m_data.altitudeGps,
                                      m_data.speed,
                                      m_data.climbSpeedBarometer,
                                      m_data.climbSpeedGps,
                                      m_data.satellitesVisible,
                                      m_data.fixType,
                                      m_data.course,
                                      m_data.heading,
                                      m_data.headingNc,
                                      m_data.hdop,
                                      m_data.vdop,
                                      m_data.pitch,
                                      m_data.roll,
                                      m_data.voltageBattery,
                                      m_data.currentBattery,
                                      m_data.consumedBattery,
                                      m_data.flightMode);

    // Copy the message to the send buffer
    uint16_t len = mavlink_msg_to_send_buffer(m_buffer, &msg);
 
    // Send the message with the standard UART send function
     m_serial->write(m_buffer, len);
}

void NazaMAVLink::sendDjiRcMotorStatus()
{
      // Initialize the required buffers
    mavlink_message_t msg;
    
    // Pack the message
    mavlink_msg_dji_rc_motor_status_pack(m_sysid, m_compid, &msg,
                                      m_data.rcA,
                                      m_data.rcE,
                                      m_data.rcR,
                                      m_data.rcU,
                                      m_data.rcT,
                                      m_data.rcX1,
                                      m_data.rcX2,
                                      m_data.m1,
                                      m_data.m2,
                                      m_data.m3,
                                      m_data.m4,
                                      m_data.m5,
                                      m_data.m6,
                                      m_data.f1,
                                      m_data.f2);

    // Copy the message to the send buffer
    uint16_t len = mavlink_msg_to_send_buffer(m_buffer, &msg);
 
    // Send the message with the standard UART send function
     m_serial->write(m_buffer, len);
}

void NazaMAVLink::receiveMessages()
{
    mavlink_message_t msg;
    mavlink_status_t status;
 
    while(m_serial->available() > 0 ) 
    {
        uint8_t c = m_serial->read();
        
        // Try to get a new message
        if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status))
        {
            // Handle message
 
            /*switch(msg.msgid)
            {
                case MAVLINK_MSG_ID_HEARTBEAT:
                {
                    // E.g. read GCS heartbeat and go into
                    // comm lost mode if timer times out
                }
                break;

                case MAVLINK_MSG_ID_COMMAND_LONG:
                    // EXECUTE ACTION
                    break;
                
                default:
                    //Do nothing
		    break;
            }*/
        }
    }
}

