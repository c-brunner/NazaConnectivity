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

#ifndef NAZA_BLE_INCLUDE
#define NAZA_BLE_INCLUDE

#include <BGLib.h>       // https://github.com/jrowberg/bglib

#include "NazaBase.h"

void NazaBLE_onBusy();
void NazaBLE_onIdle();
void NazaBLE_onTimeout();

void NazaBLE_ble_evt_system_boot(const ble_msg_system_boot_evt_t *msg);
void NazaBLE_ble_evt_connection_status(const ble_msg_connection_status_evt_t *msg);
void NazaBLE_ble_evt_connection_disconnect(const struct ble_msg_connection_disconnected_evt_t *msg);
void NazaBLE_ble_evt_attributes_value(const struct ble_msg_attributes_value_evt_t *msg);
void NazaBLE_ble_evt_attributes_user_read_request(const ble_msg_attributes_user_read_request_evt_t *msg);
void NazaBLE_ble_evt_attributes_status(const ble_msg_attributes_status_evt_t *msg);
void NazaBLE_ble_evt_attclient_attribute_value(const ble_msg_attclient_attribute_value_evt_t *msg);
void NazaBLE_ble_evt_attclient_read_multiple_response(const ble_msg_attclient_read_multiple_response_evt_t *msg);

class NazaBLE : public NazaBase
{
    public:
        NazaBLE();
        virtual ~NazaBLE();
        
        void setup(BGLib *ble112, int pinReset, int pinWakeUp, int pinLED);
        
        void bleCheckActivity ();

        void onBusy();
        void onIdle();
        void onTimeout();
        
        void onBeforeTXCommand();
        void onTXCommandComplete();

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
    
        void ble_evt_system_boot(const ble_msg_system_boot_evt_t *msg);
        void ble_evt_connection_status(const ble_msg_connection_status_evt_t *msg);
        void ble_evt_connection_disconnect(const struct ble_msg_connection_disconnected_evt_t *msg);
        void ble_evt_attributes_value(const struct ble_msg_attributes_value_evt_t *msg);
        void ble_evt_attributes_user_read_request(const ble_msg_attributes_user_read_request_evt_t *msg);
        void ble_evt_attributes_status(const ble_msg_attributes_status_evt_t *msg);
        void ble_evt_attclient_attribute_value(const ble_msg_attclient_attribute_value_evt_t *msg);
        void ble_evt_attclient_read_multiple_response(const ble_msg_attclient_read_multiple_response_evt_t *msg);

        static NazaBLE* getBleReceiver ();

    private:
        static NazaBLE* m_bleReceiver;

        static void registerBleReceiver (NazaBLE* bleReceiver);

        BGLib *m_ble112;
        
        int m_pinReset;
        int m_pinWakeUp;
        int m_pinLED;
    
        // BLE state/link status tracker
        uint8_t m_bleState;
        uint8_t m_bleEncrypted;  // 0 = not encrypted, otherwise = encrypted
        uint8_t m_bleBonding; // 0xFF = no bonding, otherwise = bonding handle

    protected:
  
};

#endif