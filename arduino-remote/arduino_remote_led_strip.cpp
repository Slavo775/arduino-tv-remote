#include "arduino_remote_lib.h"

remoteLedStrip::remoteLedStrip(int IRPin){
  _IRPin = IRPin;
}

void remoteLedStrip::_pulseIR(long microsecs){
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(_IRPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(_IRPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
  sei();
}

void remoteLedStrip::ONButton(){
  delayMicroseconds(29772);
  _pulseIR(9400);
  delayMicroseconds(4600);
  _pulseIR(640);
  delayMicroseconds(520);
  _pulseIR(640);
  delayMicroseconds(540);
  _pulseIR(600);
  delayMicroseconds(560);
  _pulseIR(640);
  delayMicroseconds(540);
  _pulseIR(620);
  delayMicroseconds(540);
  _pulseIR(640);
  delayMicroseconds(520);
  _pulseIR(640);
  delayMicroseconds(520);
  _pulseIR(620);
  delayMicroseconds(560);
  _pulseIR(640);
  delayMicroseconds(1660);
  _pulseIR(640);
  delayMicroseconds(1680);
  _pulseIR(620);
  delayMicroseconds(1680);
  _pulseIR(640);
  delayMicroseconds(1680);
  _pulseIR(620);
  delayMicroseconds(1680);
  _pulseIR(640);
  delayMicroseconds(1660);
  _pulseIR(640);
  delayMicroseconds(1680);
  _pulseIR(620);
  delayMicroseconds(1680);
  _pulseIR(640);
  delayMicroseconds(1680);
  _pulseIR(620);
  delayMicroseconds(540);
  _pulseIR(640);
  delayMicroseconds(1660);
  _pulseIR(640);
  delayMicroseconds(1680);
  _pulseIR(640);
  delayMicroseconds(520);
  _pulseIR(600);
  delayMicroseconds(580);
  _pulseIR(600);
  delayMicroseconds(560);
  _pulseIR(620);
  delayMicroseconds(540);
  _pulseIR(640);
  delayMicroseconds(540);
  _pulseIR(620);
  delayMicroseconds(1680);
  _pulseIR(600);
  delayMicroseconds(560);
  _pulseIR(620);
  delayMicroseconds(560);
  _pulseIR(620);
  delayMicroseconds(1680);
  _pulseIR(620);
  delayMicroseconds(1680);
  _pulseIR(640);
  delayMicroseconds(1680);
  _pulseIR(640);
  delayMicroseconds(41080);
  _pulseIR(9380);
  delayMicroseconds(2280);
  _pulseIR(600);
  delayMicroseconds(33644);
  _pulseIR(9360);
  delayMicroseconds(2280);
  _pulseIR(640);
  
}

void remoteLedStrip::OFFButton(){
  Serial.println("OFF button");
}
