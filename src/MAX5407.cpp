/*
   MAX5407.cpp - Class for digipot object
 */
#include "MAX5407.h"

static byte top_tap = 31;
static boolean UP   = true;
static boolean DOWN = false;

Digipot::Digipot(byte cs_pin, byte ud_pin, byte value)
{
  _tap = 0;
  _cs_pin = cs_pin;
  _ud_pin = ud_pin;
  pinMode(_cs_pin, OUTPUT);
  pinMode(_ud_pin, OUTPUT);
  value = constrain_value(value);
  set_tap(value);
}

byte Digipot::constrain_value(byte value)
{
  if (value > top_tap)
    value = top_tap;
  else if (value < 0)
    value = 0;
}

void Digipot::set_tap(byte value)
{
  byte diff = value - _tap;
  (diff > 0) ? move(UP, diff) : move(DOWN, -diff);
}

byte Digipot::get_tap()
{
  return _tap;
}

void Digipot::move(boolean direction, byte ticks)
{
  Serial.print("move dir: ");
  Serial.print(direction);
  Serial.print(" ticks: ");
  Serial.println(ticks);

  ud(direction);
  do_delay();
  cs(HIGH);
  do_delay();

  for(int i=0; i < ticks; i++)
  {
    ud(LOW);
    do_delay();
    ud(HIGH);
    do_delay();
  }

  cs(LOW);
  do_delay();
  ud(LOW);
  Serial.println("  END");
}

void Digipot::cs(boolean b)
{
  (b) ? Serial.print("C") : Serial.print("X");
  digitalWrite(_cs_pin, b);
}

void Digipot::ud(boolean b)
{
  (b) ? Serial.print("U") : Serial.print("D");
  digitalWrite(_ud_pin, b);
}

void Digipot::do_delay()
{
  Serial.print("_");
  delayMicroseconds(1);
}
