#include "arduino_remote_lib.h"

remoteLedStrip ledStrip(D0);
arduinoTvSamsungRemote samsungRemote;
void setup() {
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ledStrip.OFFButton();
  delay(1000);
  ledStrip.ONButton();
  delay(1000);

}
