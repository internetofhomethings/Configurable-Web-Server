<h2><strong>AppInventor Android App MQTT Example</strong></h2>

This project is an Android Application developed using App Inventor.

App Inventor is accessible online at: http://ai2.appinventor.mit.edu/

This example is provided as method to interface with an MQTT broker.

How it works:

The App Inventor communicates with an html/JavaScript webpage using
the WebViewString. WebViewString is visible to both App Inventor and JavaScript.

The MQTT parameters are hard-coded into the html file mqtt_appinventor.html.

var mqtturl = "ws://test.mosquitto.org:8080/mqtt";<br>
var txtopic = "MyMqttSvrRqst";<br>
var rxtopic = "MyMqttSvrRply";<br>

These values will work only with the project presented here. They will need to be 
modified as necessary to meet your own system requirements

<strong><h3>Setup:</h3></strong>

1. Connect your Android device to a PC via USB.
2. From the PC, copy the file mqtt_appinventor.html to your Android SD card at the following location:
   <<ANDROID NAME ON PC>>\Card\mqtt\mqtt_appinventor.html
3. Install the application "AppInventor_MQTT.apk" on the Android device.

NOTE: If you want to build your own Android Application using the App Inventor web interface,
import the project file AppInventor_MQTT.aia.

This App assumes an ESP8266 device is running the sketch found at: 

https://github.com/internetofhomethings/Configurable-Web-Server

For more information, check out the post at http://wp.me/p5NRQ8-lf.
