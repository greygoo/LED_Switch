#include "Arduino.h"
#include "LED_Switch.h"
//#include "Flicker.h"

LED_Switch::LED_Switch(int state, long delay)
{
      enabled = 0;
      _delay = delay;
      prevMillis = 0;
      ledFlask1_green = A4;
      ledFlask1_red = A5;
      ledFlask2_green = A2;
      ledFlask2_red = A3;
      ledFlask3_green = A0;
      ledFlask3_red = A1;
      _state = state;
      maxFlick = 50;
      minFlick = 10;
      passedMillis = 0;
      red = true;
}

void LED_Switch::Enable()
{
  enabled = 1;
  prevMillis = millis();
  pinMode(ledFlask1_red, OUTPUT);
  pinMode(ledFlask2_red, OUTPUT);
  pinMode(ledFlask3_red, OUTPUT);
  pinMode(ledFlask1_green, OUTPUT);
  pinMode(ledFlask2_green, OUTPUT);
  pinMode(ledFlask3_green, OUTPUT);
  FlickTime = random(maxFlick - minFlick) + minFlick;
}

void LED_Switch::Update()
{
  currentMillis = millis();
  passedMillis = currentMillis - prevMillis;

  if ( enabled )
  //Timeout reached
  {
    if (passedMillis >= _delay)
    {
      enabled = 0;
      prevMillis = currentMillis;
      if (_state == 1) {
        digitalWrite(ledFlask1_red, LOW);
        digitalWrite(ledFlask2_red, LOW);
        digitalWrite(ledFlask3_red, LOW);
        digitalWrite(ledFlask1_green, HIGH);
        digitalWrite(ledFlask2_green, HIGH);
        digitalWrite(ledFlask3_green, HIGH);
      } else if (_state == 0) {
        digitalWrite(ledFlask1_red, HIGH);
        digitalWrite(ledFlask2_red, HIGH);
        digitalWrite(ledFlask3_red, HIGH);
        digitalWrite(ledFlask1_green, LOW);
        digitalWrite(ledFlask2_green, LOW);
        digitalWrite(ledFlask3_green, LOW);
      } else {
        digitalWrite(ledFlask1_red, HIGH);
        digitalWrite(ledFlask2_red, HIGH);
        digitalWrite(ledFlask3_red, HIGH);
        digitalWrite(ledFlask1_green, HIGH);
        digitalWrite(ledFlask2_green, HIGH);
        digitalWrite(ledFlask3_green, HIGH);
      }
    }
    else 
    {
      if ( passedMillis >= FlickTime)
      {
        Serial.print("\nFlick...................................................\n");
        Serial.print(FlickTime);
        FlickTime = passedMillis + random(maxFlick - minFlick) + minFlick;
        // switch color
        if (red)
        {
          red = false;
        }
        else
        {
          red = true;
        }
      }
      if (red)
      {
        digitalWrite(ledFlask1_red, HIGH);
        digitalWrite(ledFlask2_red, HIGH);
        digitalWrite(ledFlask3_red, HIGH);
        digitalWrite(ledFlask1_green, LOW);
        digitalWrite(ledFlask2_green, LOW);
        digitalWrite(ledFlask3_green, LOW);
      }
      else 
      {
        digitalWrite(ledFlask1_red, LOW);
        digitalWrite(ledFlask2_red, LOW);
        digitalWrite(ledFlask3_red, LOW);
        digitalWrite(ledFlask1_green, HIGH);
        digitalWrite(ledFlask2_green, HIGH);
        digitalWrite(ledFlask3_green, HIGH);
      }
    }
  }
}
