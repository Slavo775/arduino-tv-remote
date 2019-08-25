#include "remote_magio_go_remote.h"
#include "validation.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>


#define HTTP_REST_PORT 8080
#define WIFI_RETRY_DELAY 500
#define MAX_WIFI_INIT_RETRY 50
const uint8_t magioGoPin = D0;
const uint8_t redLedPin = D7;
const uint8_t greenLedPin = D6;
magioGoTvRemote remoteMagioGo (magioGoPin);
validation val;
const char* wifi_ssid = "XXX";
const char* wifi_passwd = "XXX";
const long interval = 3600000;
unsigned long previousMillis = 0;

ESP8266WebServer http_rest_server(HTTP_REST_PORT);


void setup() {
  Serial.begin(9600);
  pinMode(magioGoPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  wifiLedOff();
  if (init_wifi() == WL_CONNECTED) {
    Serial.print("Connetted to ");
    Serial.print(wifi_ssid);
    Serial.print("--- IP: ");
    Serial.println(WiFi.localIP());
    wifiLedOn();
  }
  else {
    Serial.print("Error connecting to: ");
    Serial.println(wifi_ssid);
  }

  config_rest_server_routing();

  http_rest_server.begin();
  Serial.println("HTTP REST Server Started");
  String deviceStatus = val.sendInformationAboutDevice("Tv Ovladac", "nodeMCU", "remote", "Nahrada ovladacov zariadenia ovladane pomocou webovej apilikacie");
}

void loop() {
  unsigned long currentMillis = millis();
  http_rest_server.handleClient();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (WiFi.status() != WL_CONNECTED) {
      wifiLedOff();
      if (init_wifi() == WL_CONNECTED) {
        wifiLedOn();
      }
    } else {
      wifiLedOn();
    }
  }
}
void wifiLedOff() {
  digitalWrite(redLedPin, true);
  digitalWrite(greenLedPin, false);
}

void wifiLedOn() {
  digitalWrite(redLedPin, false);
  digitalWrite(greenLedPin, true);
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
                          "Welcome to the home remote!!");
  });
  http_rest_server.on("/deviceStatus", HTTP_GET, []() {
    http_rest_server.send(200, "text/html", val.sendInformationAboutDevice("Tv Ovladac", "nodeMCU", "remote", "Nahrada ovladacov zariadenia ovladane pomocou webovej apilikacie"));
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });

  http_rest_server.on("/magiogo/buttonON", HTTP_GET, []() {
    remoteMagioGo.buttonOnOff();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonOne", HTTP_GET, []() {
    remoteMagioGo.buttonOne();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonTwo", HTTP_GET, []() {
    remoteMagioGo.buttonTwo();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonThree", HTTP_GET, []() {
    remoteMagioGo.buttonThree();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonFour", HTTP_GET, []() {
    remoteMagioGo.buttonFour();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonFive", HTTP_GET, []() {
    remoteMagioGo.buttonFive();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonSix", HTTP_GET, []() {
    remoteMagioGo.buttonSix();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonSeven", HTTP_GET, []() {
    remoteMagioGo.buttonSeven();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonEight", HTTP_GET, []() {
    remoteMagioGo.buttonEight();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonNine", HTTP_GET, []() {
    remoteMagioGo .buttonNine();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonZero", HTTP_GET, []() {
    remoteMagioGo.buttonZero();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonVolUp", HTTP_GET, []() {
    remoteMagioGo.buttonVolUp();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonVolDown", HTTP_GET, []() {
    remoteMagioGo.buttonVolDown();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonMute", HTTP_GET, []() {
    remoteMagioGo.buttonMute();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonChUp", HTTP_GET, []() {
    remoteMagioGo.buttonChUp();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonChDown", HTTP_GET, []() {
    remoteMagioGo.buttonChDown();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonHome", HTTP_GET, []() {
    remoteMagioGo.buttonMenu();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonUp", HTTP_GET, []() {
    remoteMagioGo.buttonUp();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonLeft", HTTP_GET, []() {
    remoteMagioGo.buttonLeft();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonOk", HTTP_GET, []() {
    remoteMagioGo.buttonOk();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonRight", HTTP_GET, []() {
    remoteMagioGo.buttonRight();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonDown", HTTP_GET, []() {
    remoteMagioGo.buttonDown();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonUndo", HTTP_GET, []() {
    remoteMagioGo.buttonBack();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonExit", HTTP_GET, []() {
    remoteMagioGo.buttonExit();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonPlay", HTTP_GET, []() {
    remoteMagioGo.buttonPlay();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonPause", HTTP_GET, []() {
    remoteMagioGo.buttonPause();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonStop", HTTP_GET, []() {
    remoteMagioGo.buttonStop();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogo/buttonBackward", HTTP_GET, []() {
    remoteMagioGo.buttonReverse();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogogo/buttonForward", HTTP_GET, []() {
    remoteMagioGo.buttonForward();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
  http_rest_server.on("/magiogogo/buttonRec", HTTP_GET, []() {
    remoteMagioGo.buttonRec();
    http_rest_server.send(200, "text/html", "OK");
    http_rest_server.sendHeader("Access-Control-Allow-Origin", "*");
  });
}
