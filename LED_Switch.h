/*
  LED_Timer.h - Library for a turning on a LED for a given Time.
*/

#ifndef LED_Switch_h
#define LED_Switch_h

#include "Arduino.h"

class LED_Switch
{
  public:
    LED_Switch(int state, long delay);
    void Enable();
    void Update();
  private:
    bool enabled;
    long _delay;
    int _state;
    long prevMillis;
    int ledFlask1_green;
    int ledFlask1_red;
    int ledFlask2_green;
    int ledFlask2_red;
    int ledFlask3_green;
    int ledFlask3_red;
    int maxFlick;
    int minFlick; 
    long passedMillis;
    bool red;
    int FlickTime;
    long currentMillis;
};

#endif
