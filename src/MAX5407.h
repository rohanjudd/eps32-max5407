/*
   MAX5407.h - Class for hex byte object
 */
#include "Arduino.h"

class Digipot
{
public:
Digipot(byte cs_pin, byte ud_pin, byte value);
void set_tap(byte value);
byte get_tap();
void up();
void down();
void cs(boolean b);
void ud(boolean b);


private:
byte _tap;
boolean _cs_state;
boolean _ud_state;
byte _cs_pin;
byte _ud_pin;
};
