#include <Arduino.h>
#include "MAX5407.h"

static byte cs_pin = 13;
static byte ud_pin = 27;
static byte initial = 0;
Digipot digipot(cs_pin, ud_pin, initial);

void setup() {
    Serial.begin(115200);
    Serial.println("MAX5407 test");
}

void loop()
{
    for (int i=0; i<=31; i++)
    {
      Serial.print("setting to: ");
      Serial.println(i);
      digipot.set_tap(i);
      delay(10);
      Serial.print("set to");
      Serial.println(digipot.get_tap());
      delay(200);
    }
    for (int i=31; i>=0; i--)
    {
      Serial.print("setting to: ");
      Serial.println(i);
      digipot.set_tap(i);
      delay(10);
      Serial.print("set to");
      Serial.println(digipot.get_tap());
      delay(200);
    }
}
