#define arduino-tv-magio-remote
#include "Arduino.h"

class magioRemote
{
public:
magioRemote(int IRPin = 10);
void buttonON
();
void buttonOne
();
void buttonTwo
();
void buttonThree
();
void buttonFour
();
void buttonFive
();
void buttonSix
();
void buttonSeven
();
void buttonEight
();
void buttonNine
();
void buttonLast
();
void buttonZero
();
void buttonOptions
();
void buttonTvExit
();
void buttonMute
();
void buttonInfo
();
void buttonVolUp
();
void buttonVolDown
();
void buttonUp
();
void buttonLeft
();
void buttonRight
();
void buttonOk
();
void buttonDown
();
void buttonChUp
();
void buttonChDown
();
void buttonBack
();
void buttonMenu
();
void buttonEpg
();
void buttonRed
();
void buttonGreen
();
void buttonYellow
();
void buttonBlue
();
void buttonReverse
();
void buttonPlayPause
();
void buttonForward
();
void buttonRec
();
void buttonStop
();
void buttonRecTv
();
void buttonTone
();
void buttonMosaic
();
void buttonPip
();
void buttonTxt
();
void buttonVod
();
void buttonMagio
();
private:
  void _pulseIR(long microsec);
  int  _IRPin;
};
