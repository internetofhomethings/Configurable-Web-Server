#include <SoftwareSerial.h>
#include <UtilityFunctions.h>

#define SERBAUD 115200
#define ESPSERBAUD 1200

/*
 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
*/

SoftwareSerial toEspSerial(10, 11); // RX, TX
String fromEsp8266 = "";
String toEsp8266 = "";

// Process Requests from ESP8266
void ReadAndProcessRequests() {
    int chan,state;
    float Ain;
    char szAin[20];
    while(toEspSerial.available()) {
        char inChar = (char)toEspSerial.read();            // get the new byte
        fromEsp8266 += inChar;                             // add it to receive string
        if (inChar == '\n') {                              // process string if end of line
            if(fromEsp8266.substring(0,8)=="Arduino_") {   // Valid command from ESP8266?
                if(fromEsp8266.substring(8,10) == "SD") {  // Set Digital if true
                    // --- Build Reply String -----------------------------------------------
                    toEsp8266 = "Digital Channel ";
                    toEsp8266 += fromEsp8266.substring(10,12); //Digital Channel
                    toEsp8266 += " is ";
                    toEsp8266 += (fromEsp8266.substring(12,13)=="0") ? "LO" : "HI";
                    // ---- Send Reply String -----------------------------------------------
                    toEspSerial.println(toEsp8266);        // Send Reply String to ESP8266 
                    Serial.println(toEsp8266);             // Send Reply String to Console
                    // --- Set Digital Channel State ----------------------------------------
                    chan = atoi(fromEsp8266.substring(10,12).c_str()); 
                    state = atoi(fromEsp8266.substring(12,13).c_str()); 
                    digitalWrite(chan, state);             // Set Digital Output per request
                }
                else if(fromEsp8266.substring(8,10) == "GD") {  // Get Digital if true
                    // --- Get Digital Channel State ----------------------------------------
                    chan = atoi(fromEsp8266.substring(10,12).c_str()); 
                    state = digitalRead(chan);             // Set Digital Output per request
                    // --- Build Reply String -----------------------------------------------
                    toEsp8266 = "Digital Channel ";
                    toEsp8266 += fromEsp8266.substring(10,12); //Digital Channel
                    toEsp8266 += " is ";
                    toEsp8266 += (state==0) ? "LO" : "HI";
                    // ---- Send Reply String -----------------------------------------------
                    toEspSerial.println(toEsp8266);        // Send Reply String to ESP8266 
                    Serial.println(toEsp8266);             // Send Reply String to Console
                }
                else if(fromEsp8266.substring(8,10) == "GA") {  // Get Analog if true
                    // --- Get Analog Channel Reading ---------------------------------------
                    chan = atoi(fromEsp8266.substring(10,12).c_str()); 
                    Ain = 0.0048828 * (float) analogRead(chan);        // Read analog input
                    ftoa(Ain,szAin, 2);
                    // --- Build Reply String -----------------------------------------------
                    toEsp8266 = "Analog Channel ";
                    toEsp8266 += fromEsp8266.substring(10,12); //Analog Channel
                    toEsp8266 += " is ";
                    toEsp8266 += String(szAin);
                    // ---- Send Reply String -----------------------------------------------
                    toEspSerial.println(toEsp8266);        // Send Reply String to ESP8266 
                    Serial.println(toEsp8266);             // Send Reply String to Console
                }
                else {
                    // ---- Send Reply String -----------------------------------------------
                    toEsp8266 = "Arduino does not recognize request.";
                    toEspSerial.println(toEsp8266);        // Send Reply String to ESP8266 
                    Serial.println(toEsp8266);             // Send Reply String to Console
                }
             }
            fromEsp8266 = "";
            toEspSerial.flush();
        }
    }
}

void setup() {
    Serial.begin(SERBAUD);               // Initialize serial port
    toEspSerial.begin(ESPSERBAUD);
    pinMode(4 , OUTPUT);                 // Set Indicator LED as output

}

void loop() {
    ReadAndProcessRequests();
}
     

