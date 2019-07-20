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
  ledStrip.OFFButton();
  delay(1000);
  ledStrip.ONButton();
  delay(1000);

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
    http_rest_server.on("/samsung/buttonVolPlus", HTTP_GET, []() {samsungRemote.buttonVolPlus(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonVolMinus", HTTP_GET, []() {samsungRemote.buttonVolMinus(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonMute", HTTP_GET, []() {samsungRemote.buttonMute(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonSport", HTTP_GET, []() {samsungRemote.buttonSport(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonExit", HTTP_GET, []() {samsungRemote.buttonExit(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonHome", HTTP_GET, []() {samsungRemote.buttonHome(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonLeft", HTTP_GET, []() {samsungRemote.buttonLeft(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonRight", HTTP_GET, []() {samsungRemote.buttonRight(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
    http_rest_server.on("/samsung/buttonUp", HTTP_GET, []() {samsungRemote.buttonUp(); http_rest_server.send(200, "text/html","OK"); http_rest_server.sendHeader("Access-Control-Allow-Origin","*");});
}
