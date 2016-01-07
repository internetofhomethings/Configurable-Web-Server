#ifndef SKETCH_H
#define SKETCH_H 1


//Server actions
#define SET_LED_OFF 0
#define SET_LED_ON  1
#define BLINK_LED  2
#define Get_SENSORS 3
#define ARDUINO_REQUEST 4
#define INVALID_REQUEST 99

//Server Type
#define SVR_MQTT 0
#define SVR_HTTP_LIB 1
#define SVR_HTTP_SDK 2
#define SVR_COAP 3

//Reply Type
#define REPLY_JSON 0
#define REPLY_TEXT 1

//Set this to desired server type (see above 4 types)
#define SVR_TYPE SVR_HTTP_SDK
#define MQTT_SVR_ENABLE 1
#define COAP_SVR_ENABLE 0

//JSON string type
#define ONEJSON 0
#define FIRSTJSON 1
#define NEXTJSON 2
#define LASTJSON 3

//GPIO pin assignments
#define AMUXSEL0 14     // AMUX Selector 0
#define AMUXSEL1 12     // AMUX Selector 1
#define AMUXSEL2 13     // AMUX Selector 2
#define LED_IND 16      // LED used for initial code testing (not included in final hardware design)

#define URLSize 28
#define DATASize 32

#define EEPROM_INIT 1
#define EEPROM_WIFISSID 0x10
#define EEPROM_WIFIPASS 0x30
#define EEPROM_WIFI_IP0 0x40
#define EEPROM_WIFI_IP1 0x41
#define EEPROM_WIFI_IP2 0x42
#define EEPROM_WIFI_IP3 0x43
#define EEPROM_WIFI_NM0 0x44
#define EEPROM_WIFI_NM1 0x45
#define EEPROM_WIFI_NM2 0x46
#define EEPROM_WIFI_NM3 0x47
#define EEPROM_WIFI_GW0 0x48
#define EEPROM_WIFI_GW1 0x49
#define EEPROM_WIFI_GW2 0x4A
#define EEPROM_WIFI_GW3 0x4B
#define EEPROM_WIFI_AP0 0x4C
#define EEPROM_WIFI_AP1 0x4D
#define EEPROM_WIFI_AP2 0x4E
#define EEPROM_WIFI_AP3 0x4F
#define EEPROM_SVR_PORT 0x50
#define EEPROM_MQTT_BK  0x60
#define EEPROM_MQTT_UN  0x80
#define EEPROM_MQTT_PW  0xA0
#define EEPROM_MQTT_RT  0xC0
#define EEPROM_MQTT_TT  0xE0
#define EEPROM_SER_BAUD 0x100
#define EEPROM_SER_SERV 0x108

#define EEPROM_CHR 0
#define EEPROM_INT 1
#define EEPROM_INT16 2
#define EEPROM_INT24 3
#define ADD_CSS 4


typedef struct RQST_Param {
    int request;
    int requestval;
} RQST_Param;

typedef enum ProtocolType {
    GET = 0,
    POST,
    GET_FAVICON
} ProtocolType;

typedef struct URL_Param {
    enum ProtocolType Type;
    char pParam[URLSize][URLSize];
    char pParVal[URLSize][URLSize];
    int nPar;
} URL_Param;

#endif
