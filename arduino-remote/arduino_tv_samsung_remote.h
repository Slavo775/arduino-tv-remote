
#define arduino-tv-samsung-remote
#include "Arduino.h"
class arduinoTvSamsungRemote
{
public:
  arduinoTvSamsungRemote(int IRPin);
  void buttonON();
  void buttonSource();
  void buttonOne();
  void buttonTwo();
  void buttonThree();
  void buttonFour();
  void buttonFive();
  void buttonSix();
  void buttonSeven();
  void buttonEight();
  void buttonNine();
  void buttonTTXMIX();
  void buttonZero();
  void buttonPRECH();
  void buttonVolPlus();
  void buttonVolMinus();
  void buttonMute();
  void buttonCHList();
  void buttonCHPlus();
  void buttonCHMinus();
  void buttonSport();
  void buttonHome();
  void buttonGuide();
  void buttonExtra();
  void buttonUp();
  void buttonInfo();
  void buttonLeft();
  void buttonOK();
  void buttonRight();
  void buttonReturn();
  void buttonDown();
  void buttonExit();
  void buttonRedA();
  void buttonGreenB();
  void buttonYellowC();
  void buttonBlueD();
  void buttonSettings();
  void buttonADSUBT();
  void buttonREC();
  void buttonStop();
  void buttonReverse();
  void buttonPlay();
  void buttonPause();
  void buttonForward();
private:
  void _pulseIR(long microsec);
  int  _IRPin;
};
