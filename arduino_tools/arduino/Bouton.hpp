#ifndef QUIZBRO_ARDUINO_BOUTON
#define QUIZBRO_ARDUINO_BOUTON

#include <Arduino.h>

/*
    Represents a Bouton, manages LED control and digitalRead.

    - The class uses the INPUT_PULLUP for the switch pin.
    - Class requires the act() to be called every loop iteration for blinking functionality etc.
*/
#define LED_CONSTANT_OFF 0
#define LED_CONSTANT_ON -1
#define LED_ON_ON_PUSH -2
#define LED_OFF_ON_PUSH -3
//any positive number is blinkdelay in ms.

class Bouton
{
public:
    Bouton(int led, int sw);

    int led_program();    
    void led_program(int i);
    void manipulate_timer(int i); // adds i to timer

    void act(); //does blinking etc.
    void swap_state(); //turns led to opposite state
    bool pressed();

protected:
    int m_port_led; //port to activate led on.
    int m_port_switch; //port to read switch from.

    bool m_registered; //true if the current press is already registered.
    
    //vars used for the led programs
    long m_timer;
    bool m_led_on; //led state
    int m_program;
};

#endif
