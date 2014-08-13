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

#include "ADC.h"                // https://github.com/pedvide/ADC
#include "BGLib.h"              // https://github.com/jrowberg/bglib
#include "EEPROM.h"             // http://arduino.cc/de/Reference/EEPROM
#include "FlexCAN.h"            // https://github.com/teachop/FlexCAN_Library
#include "i2c_t3.h"             // http://forum.pjrc.com/threads/21680-New-I2C-library-for-Teensy3
#include "IntervalTimer.h"      // https://github.com/loglow/IntervalTimer
#include "SD.h"                 // http://arduino.cc/de/Reference/SD
#include "SeeedOLED.h"          // https://github.com/Seeed-Studio/Grove_OLED_Display_128X64
#include "mavlink.h"            // https://pixhawk.ethz.ch/mavlink/
#include "NazaCanDecoderLib.h"  // http://www.rcgroups.com/forums/showthread.php?t=2071772

#include "NazaGPX.h"
#include "NazaMAVLink.h"
#include "NazaSpektrum.h"

char dateTime[32];
uint32_t tmNow, timer_ms_200, timer_sec_1;

NazaGPX nazaGPX = NazaGPX();
NazaMAVLink nazaMAVLink = NazaMAVLink();
NazaSpektrum nazaSpektrum = NazaSpektrum();

ADC *adc = new ADC(); // adc object
IntervalTimer timer0; // timers

double capacity;
boolean isMotorOn;

void setup()
{
    capacity = 0.0;
    isMotorOn = false;
    
    // initialize Spektrum Virtual Telemetry Sensor Modules (Spektrum TM1000)
    nazaSpektrum.setup();
    
    // initialize Radio Wireless Telemetry Air 433Mhz Module / HM-TRP Series 100mW Transceiver modules V1.0 (http://www.hoperf.com/upload/rf_app/HM-TRP.pdf)
    nazaMAVLink.setup(&Serial1);
  
    // initialize CAN Decoder Module from pawelsky (http://www.rcgroups.com/forums/showthread.php?t=2071772)
    NazaCanDecoder.begin();
    
    // initialize SD Card Module
    SD.begin(10);
    
    // initialize Current Sensor of APM Power Module
    adc->setAveraging(32); // set number of averages
    adc->setResolution(16); // set bits of resolution
    
    adc->setConversionSpeed(ADC_HIGH_SPEED_16BITS); // change the conversion speed
    adc->setSamplingSpeed(ADC_HIGH_SPEED_16BITS); // change the sampling speed

    timer0.begin(timer0_callback,    25000); // 25ms
    //timer0.begin(timer0_callback, 100000); // 100ms
    adc->enableInterrupts(ADC_0);
}

void loop()
{
    // keep polling for new data from CAN Bus
    NazaCanDecoder.decode();

    // keep polling for new data from MAVLink
    nazaMAVLink.receiveMessages();

    tmNow = millis();

    // update data from CAN Bus every 200 milliseconds
    if(timer_ms_200 < tmNow)
    {
        timer_ms_200 = tmNow + 200;

        NazaBase::updateFromNazaCanDecoder();
        nazaMAVLink.sendDjiRcMotorStatus();
     
        if (isMotorOn != NazaBase::getData().isMotorOn)
        {
            isMotorOn = NazaBase::getData().isMotorOn;
             
            if (isMotorOn)
            {
                nazaGPX.nextFile();
                nazaGPX.writeHeader();
            }
            else
            {
              nazaGPX.writeFooter();
            }
        }
    }

    // Display date/time at 1Hz rate so every second
    if(timer_sec_1 < tmNow)
    {
        timer_sec_1 = tmNow + 1000;

        if (isMotorOn)
        {
            sprintf(dateTime, "%4u-%02u-%02uT%02u:%02u:%02u.000Z\0",
                    NazaCanDecoder.getYear() + 2000, NazaCanDecoder.getMonth(), NazaCanDecoder.getDay(),
                    NazaCanDecoder.getHour(), NazaCanDecoder.getMinute(), NazaCanDecoder.getSecond());
    
            nazaGPX.writeTrackPoint(dateTime);
        }
        
        nazaMAVLink.sendDjiSystemStatus();
    }

    NazaCanDecoder.heartbeat();
}

// This function will be called with the desired frequency
// start the measurement
// in my low-res oscilloscope this function seems to take 1.5-2 us.
void timer0_callback(void)
{
    adc->startSingleRead(A1, ADC_0); // also: startSingleDifferential, analogSynchronizedRead, analogSynchronizedReadDifferential
}

// when the measurement finishes, this will be called
// first: see which pin finished and then save the measurement into the correct buffer
void adc0_isr()
{
    uint8_t pin = ADC::sc1a2channelADC0[ADC0_SC1A&ADC_SC1A_CHANNELS]; // the bits 0-4 of ADC0_SC1A have the channel

    // add value to correct buffer
    if(pin==A1)
    {
        double value = adc->readSingle() * 3.3 / adc->getMaxValue() * 18;
        capacity +=  value / 144.0; // 25ms
        // capacity +=  value / 360.0; // 10ms
        
        NazaBase::setCurrentBattery(value * 1000.0);
        NazaBase::setConsumedBattery(capacity);
    }
    else
    { // clear interrupt anyway
        ADC0_RA;
    }

    // restore ADC config if it was in use before being interrupted by the analog timer
    if (adc->adc0->adcWasInUse) {
        // restore ADC config, and restart conversion
        ADC0_CFG1 = adc->adc0->adc_config.savedCFG1;
        ADC0_CFG2 = adc->adc0->adc_config.savedCFG2;
        ADC0_SC2 = adc->adc0->adc_config.savedSC2;
        ADC0_SC3 = adc->adc0->adc_config.savedSC3;
        ADC0_SC1A = adc->adc0->adc_config.savedSC1A;
    }
}
