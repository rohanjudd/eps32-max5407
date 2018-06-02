/*
   MAX5407.cpp - Class for digipot object
 */
#include "MAX5407.h"

byte top_tap = 31;

Digipot::Digipot(byte cs_pin, byte ud_pin, byte value)
{
  _cs_pin = cs_pin;
  _ud_pin = ud_pin;
  pinMode(_cs_pin, OUTPUT);
  pinMode(_ud_pin, OUTPUT);
  _tap = 0;
  set_tap(value);
}

void Digipot::set_tap(byte value)
{
  while( value != _tap)
  {
    if (value < _tap)
    {
      up();
      Serial.println("UP");
    }
    else if (value > _tap)
    {
      down();
      Serial.println("DOWN");
    }
  }
}

byte Digipot::get_tap()
{
  return _tap;
}

void Digipot::up()
{
  ud(HIGH);
  delayMicroseconds(1);
  cs(HIGH);
  
}

void Digipot::down()
{

}

void Digipot::cs(boolean b)
{
  digitalWrite(_cs_pin, b);
}

void Digipot::ud(boolean b)
{
  digitalWrite(_ud_pin, b);
}
