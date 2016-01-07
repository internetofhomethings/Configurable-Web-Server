<h2><strong>ESP8266 http Web and MQTT Server</strong></h2>

This project provides a Web Server Framework supporting http and MQTT requests 
to access both ESP8266 and Arduino resources.

Setup:

1. Copy the http_mqtt_server folder to your Arduino sketch folder.
2. Copy the UtilityFunctions folder to your Arduino libraries folder.
3. Copy the webserver folder to your Arduino libraries folder.
4. Change the following in the http_mqtt_server sketch to match your network settings:

<hr>
char init_ssid[32] = "YOURWIFISSID";            
char init_pass[32] = "YOURWIFIPASSWORD";            
//Your assigned ESP8266 static IP            
const char* init_ip0 = "192";            
const char* init_ip1 = "168";            
const char* init_ip2 = "0";            
const char* init_ip3 = "132";            
.            
//Your assigned WIFI LAN router IP            
const char* init_gw0 = "192";                      
const char* init_gw1 = "168";            
const char* init_gw2 = "0";            
const char* init_gw3 = "1";            
.            
//Web Server port            
const char* init_port = "9701";            
//Your MQTT broker            
const char* init_bk = "test.mosquitto.org";            
<hr>            

<strong>Server Setting</strong>

If you wish to disable the MQTT server, change the following in sketch.h

from:

define MQTT_SVR_ENABLE 1

to:

define MQTT_SVR_ENABLE 0

<strong>Operation:</strong>

The ESP8266 performs as a server, receiving URL commands and either:

1. Sets or gets the requested ESP8266 resource and returns the appropriate reply.
2. Creates a small request string and forwards the request to an Arduino via the serial interface.

In order to test this, the ESP8266 Tx needs to be connected to an Arduino Rx.
Likewise, the ESP8266 Rx needs to be connected to an Arduino Tx.

The subject Arduino should have the sketch "ArduinoHomeAutomation.ino" installed and running.
This sketch uses the Arduino software serial interface using digital pins 10 and 11. It was
tested using an Arduino nano. Using an Arduino with more serial ports, such as a MEGA can be used
and utilize the built-in hardware serial port. This would require some adjustment to the sketch.

<strong><h3>--- Web Server test: ---</h3></strong>

With both the Arduino and ESP8266 connected and running,

<strong>DIGITAL CHANNEL GET:</strong>

Enter the following URL in a web browser (adjust IP & port to your settings):

http://192.168.0.132:9701/?arduino=GetDigital&chan=04

The returned value in the web browser should be:

Digital Channel 04 is LO

<strong>DIGITAL CHANNEL SET:</strong>

Now set the channel HI by entering the following URL:

http://192.168.0.132:9701/?arduino=SetDigital&chan=04&state=1

The returned value in the web browser should be:

Digital Channel 04 is HI

And if something is connected to channel 4, such as an LED, it should illuminate with this command.

<strong>ANALOG CHANNEL GET:</strong>

Enter the following URL to get the Arduino Analog channel reading:

http://192.168.0.132:9701/?arduino=GetAnalog&chan=04

The returned value in the web browser should be similar to (units returned are volts):

Analog Channel 04 is 2.48

Expansion:

Simply add the input/output configuration in your Arduino sketch setup() function to enable
additional resource control such as 1-wire or i2c connected devices.

<strong><h3>--- Web configuration test: ---</h3></strong>

This sketch is provided with the operation of loading the ESP8266 internal EEPROM with the default
values hard-coded in the sketch.

Once the sketch has been loaded and executed at least once, the EEPROM is set as needed. In order to
disable the initialization EEPROM writes so that the EEPROM values are used, the following line 
in sketch.h needs to be revised:

From:

define EEPROM_INIT 1

To:

define EEPROM_INIT 0

With this change, the sketch will obviously need to be reloaded into the ESP8266.

This will allow configuration changes to be made using the sketch's build-in configuration webpage.

In order to access the configuration screen, enter the following URL into a web browser:

http://192.168.0.132:9701/config

Once you have entered any desired changes, click on the SAVE button to write these new values to
EEPROM, They will used the next time the ESP8266 is started. Clicking on the RESET ESP8266 button will
restart it.

<strong>Configuration in AP mode:</strong>

If the ESP8266 is moved to a WIFI with a different ssid/password, it will not be able to connect using
it's current settings. Upon startup, the ESP attempts to connect to the Wifi that is stored in EEPROM. This
attempts are aborted if unsucessful after 10 seconds. The ESP will then start up in AP mode. This provides
a method of accessing the ESP to modify the Wifi parameters as needed. To access the ESP in AP mode,
connect to the ESP with the ssid "<stored in EEPROM>_AP". Then simply open a web browser (from computer,
tablet, or smartphone) and enter:

http://192.168.4.1:9701/config

This will open the configuration panel. The AP IP "192.168.4.1" can also be modified through the configuration
panel..

<strong>Final note:</strong>

Note that the Serial Interface is set by default to a very slow 1200 baud rate. This is necessary for
reliable operation when intefacing  with Arduino using the Arduino Software Serial (Digital pins 10 & 11)
interface. This baud can be used if using a serial hardware bus such as one fount with the Arduino Mega or
if the Arduino interface is not being used. If not used. it is suggested to uncheck the "Arduino Server On"
checkbox. This enables serial output during operation which is inhibited when the serial bus is used
to communicate with an Arduino.






