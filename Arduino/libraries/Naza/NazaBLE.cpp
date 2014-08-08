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

#include "NazaBLE.h"

// BLE attribute handle definitinos
#define ATTR_DEVICE_NAME              3
#define ATTR_APPEARANCE               6
#define ATTR_MANUFACTURER_NAME       10
#define ATTR_MODEL_NUMBER            13
#define ATTR_RX                      17
#define ATTR_TX                      20

#define ATTR_LATITUDE                25
#define ATTR_LONGITUDE               29
#define ATTR_LATITUDE_HOME           33
#define ATTR_LONGITUDE_HOME          37
#define ATTR_ALTITUDE_HOME           41
#define ATTR_ALTITUDE_BAROMETER      45
#define ATTR_ALTITUDE_GPS            49
#define ATTR_SPEED                   53
#define ATTR_CLIMB_SPEED_BAROMETER   57
#define ATTR_CLIMB_SPEED_GPS         61
#define ATTR_SATELLITES_VISIBLE      65
#define ATTR_FIX_TYPE                69
#define ATTR_COURSE                  73
#define ATTR_HEADING                 77
#define ATTR_HEADING_NC              81
#define ATTR_HDOP                    85
#define ATTR_VDOP                    89
#define ATTR_PITCH                   93
#define ATTR_ROLL                    97
#define ATTR_VOLTAGE_BATTERY        101
#define ATTR_CURRENT_BATTERY        105
#define ATTR_CONSUMED_BATTERY       109
#define ATTR_FLIGHT_MODE            113
#define ATTR_RC_INPUT               117
#define ATTR_MOTOR_OUTPUT           121

// BLE state machine definitions
#define BLE_STATE_STANDBY           0
#define BLE_STATE_SCANNING          1
#define BLE_STATE_ADVERTISING       2
#define BLE_STATE_CONNECTING        3
#define BLE_STATE_CONNECTED_MASTER  4
#define BLE_STATE_CONNECTED_SLAVE   5

#define BGAPI_GET_RESPONSE(v, dType) dType *v = (dType *)m_ble112->getLastRXPayload()

NazaBLE* NazaBLE::m_bleReceiver;

NazaBLE::NazaBLE () : NazaBase()
{
    m_ble112 = NULL;
    m_pinReset = -1;
    m_pinWakeUp = -1;
    m_pinLED = -1;
    
    // BLE state/link status tracker
    m_bleState = BLE_STATE_STANDBY;
    m_bleEncrypted = 0;  // 0 = not encrypted, otherwise = encrypted
    m_bleBonding = 0xFF; // 0xFF = no bonding, otherwise = bonding handle

    registerBleReceiver(this);
}

NazaBLE::~NazaBLE ()
{
}

void NazaBLE::registerBleReceiver (NazaBLE* bleReceiver)
{
    m_bleReceiver = bleReceiver;
}

NazaBLE* NazaBLE::getBleReceiver ()
{
    return m_bleReceiver;
}

void NazaBLE::setup (BGLib *ble112, int pinReset, int pinWakeUp, int pinLED)
{
    m_ble112 = ble112;
    m_pinReset = pinReset;
    m_pinWakeUp = pinWakeUp;
    m_pinLED = pinLED;

    // BLE state/link status tracker
    m_bleState = BLE_STATE_STANDBY;
    m_bleEncrypted = 0;  // 0 = not encrypted, otherwise = encrypted
    m_bleBonding = 0xFF; // 0xFF = no bonding, otherwise = bonding handle
  
    // open Arduino USB serial (and wait, if we're using Leonardo)
    // use 38400 since it works at 8MHz as well as 16MHz
    #ifdef DEBUG
        Serial.begin(38400);
        while (!Serial);
    #endif
    
    // initialize status LED
    pinMode(m_pinLED, OUTPUT);
    digitalWrite(m_pinLED, LOW);
    
    // initialize BLE reset pin (active-low)
    pinMode(m_pinReset, OUTPUT);
    digitalWrite(m_pinReset, HIGH);

    // initialize BLE wake-up pin to allow (not force) sleep mode (assumes active-high)
    pinMode(m_pinWakeUp, OUTPUT);
    digitalWrite(m_pinWakeUp, LOW);

    // set up internal status handlers (these are technically optional)
    m_ble112->onBusy = NazaBLE_onBusy;
    m_ble112->onIdle = NazaBLE_onIdle;
    m_ble112->onTimeout = NazaBLE_onTimeout;

    // ONLY enable these if you are using the <wakeup_pin> parameter in your firmware's hardware.xml file
    // BLE module must be woken up before sending any UART data
    //ble112.onBeforeTXCommand = NazaBLE_onBeforeTXCommand;
    //ble112.onTXCommandComplete = NazaBLE_onTXCommandComplete;

    // set up BGLib event handlers
    m_ble112->ble_evt_system_boot = NazaBLE_ble_evt_system_boot;
    m_ble112->ble_evt_connection_status = NazaBLE_ble_evt_connection_status;
    m_ble112->ble_evt_connection_disconnected = NazaBLE_ble_evt_connection_disconnect;
    m_ble112->ble_evt_attributes_value = NazaBLE_ble_evt_attributes_value;
    
    m_ble112->ble_evt_attributes_user_read_request = NazaBLE_ble_evt_attributes_user_read_request;
    m_ble112->ble_evt_attributes_status = NazaBLE_ble_evt_attributes_status;
    m_ble112->ble_evt_attclient_attribute_value = NazaBLE_ble_evt_attclient_attribute_value;
    m_ble112->ble_evt_attclient_read_multiple_response = NazaBLE_ble_evt_attclient_read_multiple_response;

    // open BLE software serial port
    Serial3.begin(38400);

    // reset module (maybe not necessary for your application)
    digitalWrite(m_pinReset, LOW);
    delay(5); // wait 5ms
    digitalWrite(m_pinReset, HIGH);

    registerListener (this);
}

void NazaBLE::onLatitudeChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_LATITUDE, 0, sizeof(m_data.latitude), (const uint8*)&(m_data.latitude));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onLongitudeChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_LONGITUDE, 0, sizeof(m_data.longitude), (const uint8*)&(m_data.longitude));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onLatitudeHomeChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_LATITUDE_HOME, 0, sizeof(m_data.latitudeHome), (const uint8*)&(m_data.latitudeHome));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onLongitudeHomeChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_LONGITUDE_HOME, 0, sizeof(m_data.longitudeHome), (const uint8*)&(m_data.longitudeHome));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onAltitudeHomeChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_ALTITUDE_HOME, 0, sizeof(m_data.altitudeHome), (const uint8*)&(m_data.altitudeHome));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onAltitudeBarometerChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_ALTITUDE_BAROMETER, 0, sizeof(m_data.altitudeBarometer), (const uint8*)&(m_data.altitudeBarometer));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onAltitudeGpsChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_ALTITUDE_GPS, 0, sizeof(m_data.altitudeGps), (const uint8*)&(m_data.altitudeGps));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onSpeedChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_SPEED, 0, sizeof(m_data.speed), (const uint8*)&(m_data.speed));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onClimbSpeedBarometerChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_CLIMB_SPEED_BAROMETER, 0, sizeof(m_data.climbSpeedBarometer), (const uint8*)&(m_data.climbSpeedBarometer));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onClimbSpeedGpsChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_CLIMB_SPEED_GPS, 0, sizeof(m_data.climbSpeedGps), (const uint8*)&(m_data.climbSpeedGps));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onSatellitesVisibleChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_SATELLITES_VISIBLE, 0, sizeof(m_data.satellitesVisible), (const uint8*)&(m_data.satellitesVisible));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onFixTypeChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_FIX_TYPE, 0, sizeof(m_data.fixType), (const uint8*)&(m_data.fixType));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onCourseChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_COURSE, 0, sizeof(m_data.course), (const uint8*)&(m_data.course));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onHeadingChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_HEADING, 0, sizeof(m_data.heading), (const uint8*)&(m_data.heading));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onHeadingNcChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_HEADING_NC, 0, sizeof(m_data.headingNc), (const uint8*)&(m_data.headingNc));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onHdopChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_HDOP, 0, sizeof(m_data.hdop), (const uint8*)&(m_data.hdop));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onVdopChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_VDOP, 0, sizeof(m_data.vdop), (const uint8*)&(m_data.vdop));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onPitchChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_PITCH, 0, sizeof(m_data.pitch), (const uint8*)&(m_data.pitch));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onRollChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_ROLL, 0, sizeof(m_data.roll), (const uint8*)&(m_data.roll));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onVoltageBatteryChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_VOLTAGE_BATTERY, 0, sizeof(m_data.voltageBattery), (const uint8*)&(m_data.voltageBattery));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onCurrentBatteryChanged()
{
    //m_ble112->ble_cmd_attributes_write(ATTR_CURRENT_BATTERY, 0, sizeof(m_data.currentBattery), (const uint8*)&(m_data.currentBattery));
    //while (m_ble112->checkActivity(1000));
}

void NazaBLE::onConsumedBatteryChanged()
{
    //m_ble112->ble_cmd_attributes_write(ATTR_CONSUMED_BATTERY, 0, sizeof(m_data.consumedBattery), (const uint8*)&(m_data.consumedBattery));
    //while (m_ble112->checkActivity(1000));
}

void NazaBLE::onFlightModeChanged()
{
    m_ble112->ble_cmd_attributes_write(ATTR_FLIGHT_MODE, 0, sizeof(m_data.flightMode), (const uint8*)&(m_data.flightMode));
    while (m_ble112->checkActivity(1000));
}

void NazaBLE::onRCInputChanged()
{
    int8_t buffer[14];
    int16_t* pRCInput = (int16_t*)&buffer;

    pRCInput[0] = m_data.rcA;
    pRCInput[1] = m_data.rcE;
    pRCInput[2] = m_data.rcR;
    pRCInput[3] = m_data.rcU;
    pRCInput[4] = m_data.rcT;
    pRCInput[5] = m_data.rcX1;
    pRCInput[6] = m_data.rcX2;

    m_ble112->ble_cmd_attributes_write(ATTR_RC_INPUT, 0, 14, (const uint8*)&buffer);
    while (m_ble112->checkActivity(1000));  
}

void NazaBLE::onMotorOutputChanged()
{
    int8_t buffer[16];
    uint16_t* pMotorOutput = (uint16_t*)&buffer;

    pMotorOutput[0] = m_data.m1;
    pMotorOutput[1] = m_data.m2;
    pMotorOutput[2] = m_data.m3;
    pMotorOutput[3] = m_data.m4;
    pMotorOutput[4] = m_data.m5;
    pMotorOutput[5] = m_data.m6;
    pMotorOutput[6] = m_data.f1;
    pMotorOutput[7] = m_data.f2;

    m_ble112->ble_cmd_attributes_write(ATTR_MOTOR_OUTPUT, 0, 16, (const uint8*)&buffer);
    while (m_ble112->checkActivity(1000));  
}

void NazaBLE::bleCheckActivity ()
{
  m_ble112->checkActivity();
  
    // blink Arduino LED based on state:
    //  - solid = STANDBY
    //  - 1 pulse per second = ADVERTISING
    //  - 2 pulses per second = CONNECTED_SLAVE
    //  - 3 pulses per second = CONNECTED_SLAVE with encryption
    uint16_t slice = millis() % 1000;
    
    if (m_bleState == BLE_STATE_STANDBY)
    {
        digitalWrite(m_pinLED, HIGH);
    }
    else if (m_bleState == BLE_STATE_ADVERTISING)
    {
        digitalWrite(m_pinLED, slice < 100);
    }
    else if (m_bleState == BLE_STATE_CONNECTED_SLAVE)
    {
        if (!m_bleEncrypted)
        {
            digitalWrite(m_pinLED, slice < 100 || (slice > 200 && slice < 300));
        }
        else
        {
            digitalWrite(m_pinLED, slice < 100 || (slice > 200 && slice < 300) || (slice > 400 && slice < 500));
        }
    }  
}
// called when the module begins sending a command
void NazaBLE::onBusy() {
    // turn LED on when we're busy
    //digitalWrite(LED_PIN, HIGH);
}

// called when the module receives a complete response or "system_boot" event
void NazaBLE::onIdle() {
    // turn LED off when we're no longer busy
    //digitalWrite(LED_PIN, LOW);
}

// called when the parser does not read the expected response in the specified time limit
void NazaBLE::onTimeout() {
    // reset module (might be a bit drastic for a timeout condition though)
    //digitalWrite(BLE_RESET_PIN, LOW);
    //delay(5); // wait 5ms
    //digitalWrite(BLE_RESET_PIN, HIGH);
}

// called immediately before beginning UART TX of a command
void NazaBLE::onBeforeTXCommand() {
    // wake module up (assuming here that digital pin 5 is connected to the BLE wake-up pin)
    digitalWrite(m_pinWakeUp, HIGH);

    // wait for "hardware_io_port_status" event to come through, and parse it (and otherwise ignore it)
    uint8_t *last;
    while (1) {
        m_ble112->checkActivity();
        last = m_ble112->getLastEvent();
        if (last[0] == 0x07 && last[1] == 0x00) break;
    }

    // give a bit of a gap between parsing the wake-up event and allowing the command to go out
    delayMicroseconds(1000);
}

// called immediately after finishing UART TX
void NazaBLE::onTXCommandComplete() {
    // allow module to return to sleep (assuming here that digital pin 5 is connected to the BLE wake-up pin)
    digitalWrite(m_pinWakeUp, LOW);
}

void NazaBLE::ble_evt_system_boot(const ble_msg_system_boot_evt_t *msg)
{
    #ifdef DEBUG
        Serial.print("###\tsystem_boot: { ");
        Serial.print("major: "); Serial.print(msg -> major, HEX);
        Serial.print(", minor: "); Serial.print(msg -> minor, HEX);
        Serial.print(", patch: "); Serial.print(msg -> patch, HEX);
        Serial.print(", build: "); Serial.print(msg -> build, HEX);
        Serial.print(", ll_version: "); Serial.print(msg -> ll_version, HEX);
        Serial.print(", protocol_version: "); Serial.print(msg -> protocol_version, HEX);
        Serial.print(", hw: "); Serial.print(msg -> hw, HEX);
        Serial.println(" }");
    #endif

    // system boot means module is in standby state
    //ble_state = BLE_STATE_STANDBY;
    // ^^^ skip above since we're going right back into advertising below

    // set advertisement interval to 200-300ms, use all advertisement channels
    // (note min/max parameters are in units of 625 uSec)
    m_ble112->ble_cmd_gap_set_adv_parameters(320, 480, 7);
    while (m_ble112->checkActivity(1000));

    // USE THE FOLLOWING TO LET THE BLE STACK HANDLE YOUR ADVERTISEMENT PACKETS
    // ========================================================================
    // start advertising general discoverable / undirected connectable
    m_ble112->ble_cmd_gap_set_mode(BGLIB_GAP_GENERAL_DISCOVERABLE, BGLIB_GAP_UNDIRECTED_CONNECTABLE);
    while (m_ble112->checkActivity(1000));

    // USE THE FOLLOWING TO HANDLE YOUR OWN CUSTOM ADVERTISEMENT PACKETS
    // =================================================================

    // build custom advertisement data
    // default BLE stack value: 0201061107e4ba94c3c9b7cdb09b487a438ae55a19
/*    uint8 adv_data[] = {
        0x02, // field length
        BGLIB_GAP_AD_TYPE_FLAGS, // field type (0x01)
        0x06, // data (0x02 | 0x04 = 0x06, general discoverable + BLE only, no BR+EDR)
        0x11, // field length
        BGLIB_GAP_AD_TYPE_SERVICES_128BIT_ALL, // field type (0x07)
        0xe4, 0xba, 0x94, 0xc3, 0xc9, 0xb7, 0xcd, 0xb0, 0x9b, 0x48, 0x7a, 0x43, 0x8a, 0xe5, 0x5a, 0x19
    };

    // set custom advertisement data
    ble112.ble_cmd_gap_set_adv_data(0, 0x15, adv_data);
    while (ble112.checkActivity(1000));
*/
    // build custom scan response data (i.e. the Device Name value)
    // default BLE stack value: 140942474c69622055314131502033382e344e4657
    uint8 sr_data[] = {
        0x14, // field length
        BGLIB_GAP_AD_TYPE_LOCALNAME_COMPLETE, // field type
        'M', 'y', ' ', 'A', 'r', 'd', 'u', 'i', 'n', 'o', ' ', '0', '0', ':', '0', '0', ':', '0', '0'
    };

    // get BLE MAC address
    m_ble112->ble_cmd_system_address_get();
    while (m_ble112->checkActivity(1000));
    BGAPI_GET_RESPONSE(r0, ble_msg_system_address_get_rsp_t);

    #ifdef DEBUG
        Serial.print("mac address: ");
        // this is a "bd_addr" data type, which is a 6-byte uint8_t array
        for (uint8_t i = 0; i < 6; i++) {
            if (r0 -> address.addr[i] < 16) Serial.write('0');
            Serial.print(r0 -> address.addr[i], HEX);
        }
        Serial.println("");
    #endif
    
    // assign last three bytes of MAC address to ad packet friendly name (instead of 00:00:00 above)
    sr_data[13] = (r0 -> address.addr[2] / 0x10) + 48 + ((r0 -> address.addr[2] / 0x10) / 10 * 7); // MAC byte 4 10's digit
    sr_data[14] = (r0 -> address.addr[2] & 0xF)  + 48 + ((r0 -> address.addr[2] & 0xF ) / 10 * 7); // MAC byte 4 1's digit
    sr_data[16] = (r0 -> address.addr[1] / 0x10) + 48 + ((r0 -> address.addr[1] / 0x10) / 10 * 7); // MAC byte 5 10's digit
    sr_data[17] = (r0 -> address.addr[1] & 0xF)  + 48 + ((r0 -> address.addr[1] & 0xF ) / 10 * 7); // MAC byte 5 1's digit
    sr_data[19] = (r0 -> address.addr[0] / 0x10) + 48 + ((r0 -> address.addr[0] / 0x10) / 10 * 7); // MAC byte 6 10's digit
    sr_data[20] = (r0 -> address.addr[0] & 0xF)  + 48 + ((r0 -> address.addr[0] & 0xF ) / 10 * 7); // MAC byte 6 1's digit

    // set custom scan response data (i.e. the Device Name value)
    m_ble112->ble_cmd_gap_set_adv_data(1, 0x15, sr_data);
    while (m_ble112->checkActivity(1000));

    // put module into discoverable/connectable mode (with user-defined advertisement data)
    m_ble112->ble_cmd_gap_set_mode(BGLIB_GAP_USER_DATA, BGLIB_GAP_UNDIRECTED_CONNECTABLE);
    while (m_ble112->checkActivity(1000));
    
    uint8 value = 0xff;
    m_ble112->ble_cmd_attributes_write(20, 0, 1, &value);
    while (m_ble112->checkActivity(1000));


    // set state to ADVERTISING
    m_bleState = BLE_STATE_ADVERTISING;
}

void NazaBLE::ble_evt_connection_status(const ble_msg_connection_status_evt_t *msg)
{
    #ifdef DEBUG
        Serial.print("###\tconnection_status: { ");
        Serial.print("connection: "); Serial.print(msg -> connection, HEX);
        Serial.print(", flags: "); Serial.print(msg -> flags, HEX);
        Serial.print(", address: ");
        // this is a "bd_addr" data type, which is a 6-byte uint8_t array
        for (uint8_t i = 0; i < 6; i++) {
            if (msg -> address.addr[i] < 16) Serial.write('0');
            Serial.print(msg -> address.addr[i], HEX);
        }
        Serial.print(", address_type: "); Serial.print(msg -> address_type, HEX);
        Serial.print(", conn_interval: "); Serial.print(msg -> conn_interval, HEX);
        Serial.print(", timeout: "); Serial.print(msg -> timeout, HEX);
        Serial.print(", latency: "); Serial.print(msg -> latency, HEX);
        Serial.print(", bonding: "); Serial.print(msg -> bonding, HEX);
        Serial.println(" }");
    #endif

    // "flags" bit description:
    //  - bit 0: connection_connected
    //           Indicates the connection exists to a remote device.
    //  - bit 1: connection_encrypted
    //           Indicates the connection is encrypted.
    //  - bit 2: connection_completed
    //           Indicates that a new connection has been created.
    //  - bit 3; connection_parameters_change
    //           Indicates that connection parameters have changed, and is set
    //           when parameters change due to a link layer operation.

    // check for new connection established
    if ((msg -> flags & 0x05) == 0x05)
    {
        // track state change based on last known state, since we can connect two ways
        if (m_bleState == BLE_STATE_ADVERTISING)
        {
            m_bleState = BLE_STATE_CONNECTED_SLAVE;
        }
        else
        {
            m_bleState = BLE_STATE_CONNECTED_MASTER;
        }
    }

    // update "encrypted" status
    m_bleEncrypted = msg -> flags & 0x02;
    
    // update "bonded" status
    m_bleBonding = msg -> bonding;
}

void NazaBLE::ble_evt_connection_disconnect(const struct ble_msg_connection_disconnected_evt_t *msg)
{
    #ifdef DEBUG
        Serial.print("###\tconnection_disconnect: { ");
        Serial.print("connection: "); Serial.print(msg -> connection, HEX);
        Serial.print(", reason: "); Serial.print(msg -> reason, HEX);
        Serial.println(" }");
    #endif

    // set state to DISCONNECTED
    //ble_state = BLE_STATE_DISCONNECTED;
    // ^^^ skip above since we're going right back into advertising below

    // after disconnection, resume advertising as discoverable/connectable
    //ble112.ble_cmd_gap_set_mode(BGLIB_GAP_GENERAL_DISCOVERABLE, BGLIB_GAP_UNDIRECTED_CONNECTABLE);
    //while (ble112.checkActivity(1000));

    // after disconnection, resume advertising as discoverable/connectable (with user-defined advertisement data)
    m_ble112->ble_cmd_gap_set_mode(BGLIB_GAP_USER_DATA, BGLIB_GAP_UNDIRECTED_CONNECTABLE);
    while (m_ble112->checkActivity(1000));

    // set state to ADVERTISING
    m_bleState = BLE_STATE_ADVERTISING;

    // clear "encrypted" and "bonding" info
    m_bleEncrypted = 0;
    m_bleBonding = 0xFF;
}

void NazaBLE::ble_evt_attributes_value(const struct ble_msg_attributes_value_evt_t *msg)
{
    #ifdef DEBUG
        Serial.print("###\tattributes_value: { ");
        Serial.print("connection: "); Serial.print(msg -> connection, HEX);
        Serial.print(", reason: "); Serial.print(msg -> reason, HEX);
        Serial.print(", handle: "); Serial.print(msg -> handle, HEX);
        Serial.print(", offset: "); Serial.print(msg -> offset, HEX);
        Serial.print(", value_len: "); Serial.print(msg -> value.len, HEX);
        Serial.print(", value_data: ");
        // this is a "uint8array" data type, which is a length byte and a uint8_t* pointer
        for (uint8_t i = 0; i < msg -> value.len; i++) {
            if (msg -> value.data[i] < 16) Serial.write('0');
            Serial.print(msg -> value.data[i], HEX);
        }
        Serial.println(" }");
    #endif

    // check for data written to "c_rx_data" handle
    if (msg -> handle == ATTR_RX && msg -> value.len > 0) {
        // set ping 8, 9, and 10 to three lower-most bits of first byte of RX data
        // (nice for controlling RGB LED or something)
        digitalWrite(8, msg -> value.data[0] & 0x01);
        digitalWrite(9, msg -> value.data[0] & 0x02);
        digitalWrite(10, msg -> value.data[0] & 0x04);
    }
}

void NazaBLE::ble_evt_attributes_user_read_request(const ble_msg_attributes_user_read_request_evt_t *msg)
{

}

void NazaBLE::ble_evt_attributes_status(const ble_msg_attributes_status_evt_t *msg)
{

}

void NazaBLE::ble_evt_attclient_attribute_value(const ble_msg_attclient_attribute_value_evt_t *msg)
{

}

void NazaBLE::ble_evt_attclient_read_multiple_response(const ble_msg_attclient_read_multiple_response_evt_t *msg)
{

}



// ================================================================
// INTERNAL BGLIB CLASS CALLBACK FUNCTIONS
// ================================================================

// called when the module begins sending a command
void NazaBLE_onBusy()
{
  NazaBLE::getBleReceiver()->onBusy();
}

// called when the module receives a complete response or "system_boot" event
void NazaBLE_onIdle()
{
  NazaBLE::getBleReceiver()->onIdle();
}

// called when the parser does not read the expected response in the specified time limit
void NazaBLE_onTimeout()
{
  NazaBLE::getBleReceiver()->onTimeout();
}

// called immediately before beginning UART TX of a command
void NazaBLE_onBeforeTXCommand()
{
  NazaBLE::getBleReceiver()->onBeforeTXCommand();
}

// called immediately after finishing UART TX
void NazaBLE_onTXCommandComplete()
{
  NazaBLE::getBleReceiver()->onTXCommandComplete();
}


// ================================================================
// APPLICATION EVENT HANDLER FUNCTIONS
// ================================================================

void NazaBLE_ble_evt_system_boot(const ble_msg_system_boot_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_system_boot(msg);
}

void NazaBLE_ble_evt_connection_status(const ble_msg_connection_status_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_connection_status(msg);
}

void NazaBLE_ble_evt_connection_disconnect(const struct ble_msg_connection_disconnected_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_connection_disconnect(msg);
}

void NazaBLE_ble_evt_attributes_value(const struct ble_msg_attributes_value_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_attributes_value(msg);
}

void NazaBLE_ble_evt_attributes_user_read_request(const ble_msg_attributes_user_read_request_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_attributes_user_read_request(msg);
}

void NazaBLE_ble_evt_attributes_status(const ble_msg_attributes_status_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_attributes_status(msg);
}

void NazaBLE_ble_evt_attclient_attribute_value(const ble_msg_attclient_attribute_value_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_attclient_attribute_value(msg);
}

void NazaBLE_ble_evt_attclient_read_multiple_response(const ble_msg_attclient_read_multiple_response_evt_t *msg)
{
  NazaBLE::getBleReceiver()->ble_evt_attclient_read_multiple_response(msg);
}
