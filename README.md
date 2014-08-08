NazaConnectivity
================

SoftwareModules
---------------

NazaBLE

adds support for Bluetooth Low Energy (BlueGiga BLE112) in order to receive real time stats of NAZA-M V2 chip on any iOS device.

NazaGPX

adds support for logging your flight in GPX format and view your flight in GoogleEarth.
http://www.topografix.com/gpx.asp

NazaMAVLink

adds support for remote communication between your copter and a small base station via the Radio Wireless Telemetry Air 433Mhz module.
As it's only using the serial connection you can use any wireless communication module.

NazaOLED

adds support for dislplaying real time stats on the wireless base station via a small OLED display.

NazaSpektrum

adds telemetry support for any Spektrum transmitter (like DX9).
you only have to connect your board to the Spektrum TM-1000 and you get real time stats on your transmitter.

F550 Dynamic Flight Data

iOS application for connecting to the base station and displaying real time stats.
you can also view your gpx files in this application.

HardwareModules
---------------

Arduino - Teensy 3.1

CAN Bus - Breakout Board Pawelsky (http://www.rcgroups.com/forums/showthread.php?t=2071772)

MicroSD - Breakout Board Pawelsky (http://www.rcgroups.com/forums/showthread.php?t=2071772)

Bluetooth Low Energy - BLE112 (https://www.bluegiga.com/evaluation_BLE112)

Bluetooth Low Energy - Breakout Board
(http://www.inmojo.com/store/jeff-rowberg/item/ble112-bluetooth-low-energy-breakout)

OLED Display - Grove OLED Display (https://github.com/Seeed-Studio/Grove_OLED_Display_128X64)

Wireless Module - 3DR Radio Set (https://store.3drobotics.com/products/3dr-radio)

Current Sensor - APM Power Module (https://store.3drobotics.com/products/apm-power-module-with-xt60-connectors)


External Libraries
------------------

Many thanks for your effort goes to the developers of the following libraries that made my life much easier:

Pawelsky - http://www.rcgroups.com/forums/showthread.php?t=2071772

Pedro Villanueva - https://github.com/pedvide/ADC

Jeff Rowberg - https://github.com/jrowberg/bglib

teachop - https://github.com/teachop/FlexCAN_Library

Brian "nox771" - http://forum.pjrc.com/threads/21680-New-I2C-library-for-Teensy3

The guys from Seed Studio - https://github.com/Seeed-Studio/Grove_OLED_Display_128X64

The guys from Arduino - http://arduino.cc/de/Reference/SD, http://arduino.cc/de/Reference/EEPROM

The guys from ETH Zurich - https://pixhawk.ethz.ch/mavlink/
