#include "validation.h"
#include "ArduinoJson.h"
#include "ESP8266WiFi.h"
#include <WiFiClient.h> 



String validation::getSuccessSimpleValidationMessage(){
  return "{\"status\":\"ok\", \"Message\": \"Success\"}";
}
String validation::sendInformationAboutDevice(String Name, String Type, String role, String description){
    String Json = "{\"name\":\"" + Name + "\", \"type\":\"" + Type + "\",\"role\":\"" + role + "\",\"description\":\"" + description + "\",\"ip\":\"" + WiFi.localIP().toString()+ "\",\"mac\":\""+ WiFi.macAddress() +"\"}";
    return Json;
  }
