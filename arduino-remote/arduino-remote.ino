#include "arduino_remote_lib.h"

remoteLedStrip ledStrip(13);
arduinoTvSamsungRemote samsungRemote;
void setup() {
  Serial.begin(9600);
  ledStrip.OFFButton();
  samsungRemote.buttonOFF();
}

void loop() {
  // put your main code here, to run repeatedly:

}
