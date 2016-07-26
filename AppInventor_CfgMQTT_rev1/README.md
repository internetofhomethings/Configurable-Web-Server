<h2><strong>AppInventor Android App MQTT Example</strong></h2>

This project is an Android Application developoed using App Inventor.
It is provided as an example method to interface with an MQTT broker.

How it works:

The App Inventor communicates with an html/JavaScript webpage using
the WebViewString. WebViewString is visible to both App Inventor and JavaScript.

The MQTT parameters are now configurable using this App Inventor App. The initial
default values are:

broker:           "broker.mqttdashboard.com";<br>
request topic:    "mqtt_request";<br>
reply topic:      "mqtt_reply";<br>
user name:        "mosquitto";<br>
password:         "mosquitto";<br>
reply topic:      "mqtt_reply";<br>
connect port:     "8000";<br>
connect clientID: "clientID";<br>
keepalive timeout:"60";<br>
last will topic:  "closing down....";<br>
last will message:"lwt";<br>
last will QoS:    "0";<br>

These values will only work with the project presented here. They will need to be 
modified as necessary to meet your own system requirements

<strong><h3>Setup:</h3></strong>

1. Connect your Android device to a PC via USB.
2. From the PC, copy the following files to your Android SD card at the following location:<br><br>
   <ANDROID NAME ON PC>\Phone\mqtt\mqtt_appinventor_paho.html<br>
   <ANDROID NAME ON PC>\Phone\mqtt\mqttws31.js<br>
   <ANDROID NAME ON PC>\Phone\mqtt\cfg.txt<br><br>
3. Install the application "AppInventor_MQTT_CFG_rev1.apk" on the Android device.

NOTE: If you want to build your own Android Application using the App Inventor web interface,
import the project file AppInventor_MQTT_CFG_rev1.aia.

This App assumes an ESP8266 device is running with the sketch found at 

https://github.com/internetofhomethings/Configurable-Web-Server

installed.
