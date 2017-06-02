#include "Bouton.hpp"

Bouton b_red(2, 13);
Bouton b_blue(4, 12);
Bouton b_green(6, 11);
Bouton b_yellow(8, 10);

enum ArduinoSignal
{
    NO_EVENT                =   0b0000000000000000,
    RED_BOUTON              =   0b0000000000000001,
    GREEN_BOUTON            =   0b0000000000000010,
    BLUE_BOUTON             =   0b0000000000000100,
    YELLOW_BOUTON           =   0b0000000000001000,
    ALL_BOUTONS             =   0b0000000000001111,

    ARDUINO_STATUS_ERROR    =   0b0000000000000000,
    ARDUINO_STATUS_OK       =   0b0000000000000001,

    ARDUINO_MODE_BTB        =   0b0000001000000000,
    ARDUINO_MODE_FREE       =   0b0000010000000000,
    ARDUINO_MODE_UNLOCK     =   0b0000100000000000,

    BUTTON_STATE_OFF        =   0,
    BUTTON_STATE_ON         =   -1,
    BUTTON_STATE_ON_PUSH    =   -2,
    BUTTON_STATE_OFF_PUSH   =   -3
};

int count = 0;

int fatoi(const char *str)
{
    int val = 0;
    bool neg = false;
    if(*str == '-') neg = true;
    while(*str)
    {
        val = val * 10 + (*str++ - '0');
    }
    return neg ? -val : val;
}

void setup()
{
    Serial.begin(57600);
    Serial.setTimeout(2);

    b_red.led_program(1000);
    b_blue.led_program(1000);
    b_green.led_program(1000);
    b_yellow.led_program(1000);
}

void action_input(int button, int state)
{
    if(button & RED_BOUTON) b_red.led_program(state);
    if(button & BLUE_BOUTON) b_blue.led_program(state);
    if(button & GREEN_BOUTON) b_green.led_program(state);
    if(button & YELLOW_BOUTON) b_yellow.led_program(state);
}

void loop()
{
    short sig = 0;
    if(b_red.pressed()) sig |= RED_BOUTON;
    if(b_blue.pressed()) sig |= BLUE_BOUTON;
    if(b_green.pressed()) sig |= GREEN_BOUTON;
    if(b_yellow.pressed()) sig |= YELLOW_BOUTON;

    if(sig)
    {
        Serial.println(sig);
        Serial.flush();
    }

    if(Serial.available())
    {
        int i1 = Serial.parseInt();
        int i2 = Serial.parseInt();
        action_input(i1, i2);
    }

    b_red.act();
    b_blue.act();
    b_green.act();
    b_yellow.act();
    
}


