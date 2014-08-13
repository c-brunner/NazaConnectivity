###NazaConnectivity
####SoftwareModules

#####NazaBLE
adds support for Bluetooth Low Energy ([BlueGiga BLE112](https://www.bluegiga.com/evaluation_BLE112)) in order to receive real time stats of [NAZA-M V2](www.dji.com/product/naza-m-v2) chip on any iOS device.

#####NazaGPX
adds support for logging your flight in [GPX](http://www.topografix.com/gpx.asp) format and view your flight in GoogleEarth.


#####NazaMAVLink
adds support for remote communication between your copter and a small base station via the [Radio Wireless Telemetry Air 433Mhz module](https://store.3drobotics.com/products/3dr-radio). As it's only using the serial connection you can use any wireless communication module.

#####NazaOLED
adds support for dislplaying real time stats on the wireless base station via a small [OLED display](https://github.com/Seeed-Studio/OLED_Display_128X64).

#####NazaSpektrum
adds telemetry support for any Spektrum transmitter (like [Spektrum DX9](http://spektrumrc.com/Products/Default.aspx?ProdID=SPMR9900)). you only have to connect your board to the [Spektrum TM-1000](http://spektrumrc.com/Products/Default.aspx?ProdID=SPM9548) and you get real time stats on your transmitter.

#####F550 Dynamic Flight Data
iOS application for connecting to the base station and displaying real time stats.
you can also view your gpx files in this application.

####Required Hardware Modules

Arduino - [Teensy 3.1](https://www.pjrc.com/teensy/teensy31.html)

CAN Bus - [Breakout Board Pawelsky](http://www.rcgroups.com/forums/showthread.php?t=2071772)

MicroSD - [Breakout Board Pawelsky](http://www.rcgroups.com/forums/showthread.php?t=2071772)

Bluetooth Low Energy - [BLE112](https://www.bluegiga.com/evaluation_BLE112)

Bluetooth Low Energy - [Breakout Board](http://www.inmojo.com/store/jeff-rowberg/item/ble112-bluetooth-low-energy-breakout)

OLED Display - [Grove OLED Display](https://github.com/Seeed-Studio/Grove_OLED_Display_128X64)

Wireless Module - [3DR Radio Set](https://store.3drobotics.com/products/3dr-radio)

Current Sensor - [APM Power Module](https://store.3drobotics.com/products/apm-power-module-with-xt60-connectors)

####Required External Libraries

Many thanks for your effort goes to the developers of the following libraries that made my life much easier:

Pawelsky - [NazaCanDecoder](http://www.rcgroups.com/forums/showthread.php?t=2071772)

Pedro Villanueva - [Teensy 3.0/3.1 ADC implementation](https://github.com/pedvide/ADC)

Jeff Rowberg - [BGLib implementation for Bluegiga BLE112 Bluetooth Smart module](https://github.com/jrowberg/bglib)

teachop - [Arduino library for CAN on Teensy 3.1](https://github.com/teachop/FlexCAN_Library)

Brian "nox771" - [I2C library for Teensy3](http://forum.pjrc.com/threads/21680-New-I2C-library-for-Teensy3)

Daniel Gilbert - [IntervalTimer](https://github.com/loglow/IntervalTimer)

The guys from Seed Studio - [Seeed OLED Display 128*64 library](https://github.com/Seeed-Studio/Grove_OLED_Display_128X64)

The guys from Arduino - [SD](http://arduino.cc/de/Reference/SD), [EEPROM](http://arduino.cc/de/Reference/EEPROM)

The guys from ETH Zurich - [MAVLink](https://pixhawk.ethz.ch/mavlink/)
