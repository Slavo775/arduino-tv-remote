#ifndef arduino-remote
#define arduino-remote

#include "Arduino.h"

class magioGoTvRemote{
public:
magioGoTvRemote(int IRPin);
void buttonOnOff();
void buttonTvToRadio();
void buttonMute();
void buttonOne();
void buttonTwo();
void buttonThree();
void buttonFour();
void buttonFive();
void buttonSix();
void buttonSeven();
void buttonEight();
void buttonNine();
void buttonOpt();
void buttonZero();
void buttonText();
void buttonRed();
void buttonGreen();
void buttonYellow();
void buttonBlue();
void buttonMedia();
void buttonGuide();
void buttonUp();
void buttonLeft();
void buttonOk();
void buttonRight();
void buttonDown();
void buttonExit();
void buttonMenu();
void buttonBack();
void buttonVolUp();
void buttonInfo();
void buttonChUp();
void buttonVolDown();
void buttonAudio();
void buttonChDown();
void buttonSubT();
void buttonRec();
void buttonPause();
void buttonStop();
void buttonReverse();
void buttonPlay();
void buttonForward();
void buttonReverseRev();
void buttonSleep();
void buttonForwardFor();
  private:
  void _pulseIR(long microsec);
  int  _IRPin;
};
#endif
