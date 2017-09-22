#include "ShiftChain.hpp"

ShiftChain<1> leds(5, 11, 8);

void setup()
{
    //leds.set(0, BITS);
}

void loop()
{
    for(byte i = 0; i < 255; ++i)
    {
        leds.set(0, i);
        delay(500);
    }
}