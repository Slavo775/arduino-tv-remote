#ifndef validation_h
#define validation_h


#include "Arduino.h"
#include <ArduinoJson.h>

class validation{
  public:
  String getSuccessSimpleValidationMessage();
  String sendInformationAboutDevice(String Name, String Type, String role, String description);
};
#endif
