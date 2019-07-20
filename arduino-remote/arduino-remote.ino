#include "arduino_remote_lib.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

#define HTTP_REST_PORT 8080
#define WIFI_RETRY_DELAY 500
#define MAX_WIFI_INIT_RETRY 50

remoteLedStrip ledStrip(D0);
arduinoTvSamsungRemote samsungRemote(D0);
magioRemote tvRemoteMagio(D0);

const char* wifi_ssid = "Xiaomi_34C2";
const char* wifi_passwd = "XXX";

ESP8266WebServer http_rest_server(HTTP_REST_PORT);


void setup() {
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
  
    if (init_wifi() == WL_CONNECTED) {
        Serial.print("Connetted to ");
        Serial.print(wifi_ssid);
        Serial.print("--- IP: ");
        Serial.println(WiFi.localIP());
    }
    else {
        Serial.print("Error connecting to: ");
        Serial.println(wifi_ssid);
    }

    config_rest_server_routing();

    http_rest_server.begin();
    Serial.println("HTTP REST Server Started");
}

void loop() {
  // put your main code here, to run repeatedly:
  http_rest_server.handleClient();

}

int init_wifi() {
    int retries = 0;

    Serial.println("Connecting to WiFi AP..........");

    WiFi.mode(WIFI_STA);
    WiFi.begin(wifi_ssid, wifi_passwd);
    // check the status of WiFi connection to be WL_CONNECTED
    while ((WiFi.status() != WL_CONNECTED) && (retries < MAX_WIFI_INIT_RETRY)) {
        retries++;
        delay(WIFI_RETRY_DELAY);
        Serial.print("#");
    }
    return WiFi.status(); // return the WiFi connection status
}

void config_rest_server_routing() {
    http_rest_server.on("/", HTTP_GET, []() {
        http_rest_server.send(200, "text/html",
            "Welcome to the ESP8266 REST Web Server");
    });
    http_rest_server.on("/samsung/buttonON", HTTP_GET, []() {samsungRemote.buttonON(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonSource", HTTP_GET, []() {samsungRemote.buttonSource(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonOne", HTTP_GET, []() {samsungRemote.buttonOne(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonTwo", HTTP_GET, []() {samsungRemote.buttonTwo(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonThree", HTTP_GET, []() {samsungRemote.buttonThree(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonFour", HTTP_GET, []() {samsungRemote.buttonFour(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonFive", HTTP_GET, []() {samsungRemote.buttonFive(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonSix", HTTP_GET, []() {samsungRemote.buttonSix(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonSeven", HTTP_GET, []() {samsungRemote.buttonSeven(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonEight", HTTP_GET, []() {samsungRemote.buttonEight(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonNine", HTTP_GET, []() {samsungRemote.buttonNine(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonZero", HTTP_GET, []() {samsungRemote.buttonZero(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonVolUp", HTTP_GET, []() {samsungRemote.buttonVolPlus(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonVolDown", HTTP_GET, []() {samsungRemote.buttonVolMinus(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonMute", HTTP_GET, []() {samsungRemote.buttonMute(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonChUp", HTTP_GET, []() {samsungRemote.buttonCHPlus(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonChDown", HTTP_GET, []() {samsungRemote.buttonCHMinus(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonSport", HTTP_GET, []() {samsungRemote.buttonSport(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonHome", HTTP_GET, []() {samsungRemote.buttonHome(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonUp", HTTP_GET, []() {samsungRemote.buttonUp(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonLeft", HTTP_GET, []() {samsungRemote.buttonLeft(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonOk", HTTP_GET, []() {samsungRemote.buttonOK(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonRight", HTTP_GET, []() {samsungRemote.buttonRight(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonDown", HTTP_GET, []() {samsungRemote.buttonDown(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonUndo", HTTP_GET, []() {samsungRemote.buttonReturn(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonExit", HTTP_GET, []() {samsungRemote.buttonExit(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonPlay", HTTP_GET, []() {samsungRemote.buttonPlay(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonPause", HTTP_GET, []() {samsungRemote.buttonPause(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonStop", HTTP_GET, []() {samsungRemote.buttonStop(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonBackward", HTTP_GET, []() {samsungRemote.buttonReverse(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonForward", HTTP_GET, []() {samsungRemote.buttonForward(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonRec", HTTP_GET, []() {samsungRemote.buttonREC(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});

    http_rest_server.on("/magio/buttonON", HTTP_GET, []() {tvRemoteMagio.buttonON(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonOne", HTTP_GET, []() {tvRemoteMagio.buttonOne(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonTwo", HTTP_GET, []() {tvRemoteMagio.buttonTwo(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonThree", HTTP_GET, []() {tvRemoteMagio.buttonThree(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonFour", HTTP_GET, []() {tvRemoteMagio.buttonFour(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonFive", HTTP_GET, []() {tvRemoteMagio.buttonFive(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonSix", HTTP_GET, []() {tvRemoteMagio.buttonSix(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonSeven", HTTP_GET, []() {tvRemoteMagio.buttonSeven(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonEight", HTTP_GET, []() {tvRemoteMagio.buttonEight(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonNine", HTTP_GET, []() {tvRemoteMagio.buttonNine(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonZero", HTTP_GET, []() {tvRemoteMagio.buttonZero(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonVolUp", HTTP_GET, []() {tvRemoteMagio.buttonVolUp(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonVolDown", HTTP_GET, []() {tvRemoteMagio.buttonVolDown(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonMute", HTTP_GET, []() {tvRemoteMagio.buttonMute(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonChUp", HTTP_GET, []() {tvRemoteMagio.buttonChUp(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonChDown", HTTP_GET, []() {tvRemoteMagio.buttonChDown(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonHome", HTTP_GET, []() {tvRemoteMagio.buttonMenu(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonUp", HTTP_GET, []() {tvRemoteMagio.buttonUp(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonLeft", HTTP_GET, []() {tvRemoteMagio.buttonLeft(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonOk", HTTP_GET, []() {tvRemoteMagio.buttonOk(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonRight", HTTP_GET, []() {tvRemoteMagio.buttonRight(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonDown", HTTP_GET, []() {tvRemoteMagio.buttonDown(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonUndo", HTTP_GET, []() {tvRemoteMagio.buttonBack(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonExit", HTTP_GET, []() {tvRemoteMagio.buttonTvExit(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonPlay", HTTP_GET, []() {tvRemoteMagio.buttonPlayPause(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonPause", HTTP_GET, []() {tvRemoteMagio.buttonPlayPause(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonStop", HTTP_GET, []() {tvRemoteMagio.buttonStop(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonBackward", HTTP_GET, []() {tvRemoteMagio.buttonReverse(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonForward", HTTP_GET, []() {tvRemoteMagio.buttonForward(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/magio/buttonRec", HTTP_GET, []() {tvRemoteMagio.buttonRec(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");}); 
}
