#ifndef arduino-remote
#define arduino-remote

#include "Arduino.h"
#include "arduino_tv_samsung_remote.h"

class remoteLedStrip{
  public:
  remoteLedStrip(int IRPin = 10);
  void ONButton();
  void OFFButton();
  void birghtnessDown();
  void brightnessUp();
  void red();
  void green();
  void blue();
  void white();
  private:
  void _pulseIR(long microsec);
  int  _IRPin;
};








#endif
