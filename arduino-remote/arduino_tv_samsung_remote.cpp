#include "arduino_tv_samsung_remote.h"
#include "arduino_remote_lib.h"
void arduinoTvSamsungRemote::buttonOFF(){
  Serial.println("Samsung remote OFF");
  remoteLedStrip remote = new remoteLedStrip;
  }
