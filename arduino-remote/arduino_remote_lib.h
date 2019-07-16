#ifndef arduino-remote
#define arduino-remote

#include "Arduino.h"
#include "arduino_tv_samsung_remote.h"

class remoteLedStrip{
  public:
  remoteLedStrip(int IRPin = 10);
  void ONButton();
  void OFFButton();
  void brightnessDown();
  void brightnessUp();
  void buttonRed();
  void buttonGreen();
  void buttonBlue();
  void buttonWhite();
  void buttonOne();
  void buttonTwo();
  void buttonThree();
  void buttonFlash();
  void buttonFour();
  void buttonFive();
  void buttonSix();
  void buttonStrobe();
  void buttonSeven();
  void buttonEight();
  void buttonNine();
  void buttonFade();
  void buttonTen();
  void buttonEleven();
  void buttonTwelve();
  void buttonSmooth();
  private:
  void _pulseIR(long microsec);
  int  _IRPin;
};








#endif
