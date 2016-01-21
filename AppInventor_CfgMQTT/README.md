<h2><strong>AppInventor Android App MQTT Example</strong></h2>

This project is an Android Application developoed using App Inventor.
It is provided as an example method to interface with an MQTT broker.

How it works:

The App Inventor communicates with an html/JavaScript webpage using
the WebViewString. WebViewString is visible to both App Inventor and JavaScript.

The MQTT parameters are now configurable using this App Inventor App. The initial
default values are:

broker:        "ws://test.mosquitto.org:8080/mqtt";<br>
request topic: "MyMqttSvrRqst";<br>
reply topic:   "MyMqttSvrRply";<br>

These values will work only with the project presented here. They will need to be 
modified as necessary to meet your own system requirements

<strong><h3>Setup:</h3></strong>

1. Connect your Android device to a PC via USB.
2. From the PC, copy the file mqtt_appinventor.html to your Android SD card at the following location:
   <ANDROID NAME ON PC>\Phone\mqtt\mqtt_appinventor.html
3. Install the application "AppInventor_MQTT_CFG.apk" on the Android device.

NOTE: If you want to build your own Android Application using the App Inventor web interface,
import the project file AppInventor_MQTT_CFG.aia.

This App assumes an ESP8266 device is running with the sketch found at 

https://github.com/internetofhomethings/Configurable-Web-Server

installed.
