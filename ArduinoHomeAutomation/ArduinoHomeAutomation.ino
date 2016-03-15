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
String periodicMsg="";
long lastMsg = 0;

// Process Requests from ESP8266
void ReadAndProcessRequests() {
    int chan,state,button;
    float Ain;
    char szAin[20],szT[200];
    button = digitalRead(6);
    if(button==0) {
       toEspSerial.println("Button has been Pressed");   
    }
    
    while(toEspSerial.available()) {
        char inChar = (char)toEspSerial.read();            // get the new byte
        if (inChar != '\n') {
            fromEsp8266 += inChar;                         // add it to receive string
        }
        else {                              // process string if end of line
             if(fromEsp8266.substring(0,8)=="Arduino_") {   // Valid command from ESP8266?
                if(fromEsp8266.substring(8,10) == "SM") {  // Set Digital if true
                    // --- Build Reply String -----------------------------------------------
                    toEsp8266 = "Echoing your message: ";
                    toEsp8266 += fromEsp8266.substring(10,50); 
                    // ---- Set Periodic Message String -------------------------------------
                    url_decode((char *)toEsp8266.c_str(), (char *)szT );
                    periodicMsg = szT;
                }
                else if(fromEsp8266.substring(8,10) == "SD") {  // Set Digital if true
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

/********************************************************
 *  URL Message Decoder
 ********************************************************/
 
int url_decode(char *encoded_str, char *decoded_str) {
   
    // While we're not at the end of the string (current character not NULL)
    while (*encoded_str) {
        // Check to see if the current character is a %
        if (*encoded_str == '%') {
    
            // Grab the next two characters and move encoded_str forwards
            encoded_str++;
            char high = *encoded_str;
            encoded_str++;
            char low = *encoded_str;
    
            // Convert ASCII 0-9A-F to a value 0-15
            if (high > 0x39) high -= 7;
            high &= 0x0f;
    
            // Same again for the low byte:
            if (low > 0x39) low -= 7;
            low &= 0x0f;
    
            // Combine the two into a single byte and store in decoded_str:
            *decoded_str = (high << 4) | low;
        } else {
            // All other characters copy verbatim
            *decoded_str = *encoded_str;
        }
    
        // Move both pointers to the next character:
        encoded_str++;
        decoded_str++;
    }
    // Terminate the new string with a NULL character to trim it off
    *decoded_str = 0;
}
/*****************************************************
 * Send Message Every 2 seconds until Message = stop *
 *****************************************************/
void PeriodicMessageEcho() {
    String dc;
    if(periodicMsg!="") {
         //Stop sending when Msg="stop"
         if(periodicMsg.substring(22,26) == "stop" ) {
             toEspSerial.println("Msg echo terminated.");
             periodicMsg = ""; 
         }
         // Send Message every 2 seconds
         else {
             long now = millis();                 
             if (now - lastMsg > 2000) { 
                 toEspSerial.println(periodicMsg);
                 lastMsg = now;
             }
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
    PeriodicMessageEcho();
}
     

