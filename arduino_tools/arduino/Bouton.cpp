#include "Bouton.hpp"

Bouton::Bouton(int led, int sw)
{
    m_port_led = led;
    m_port_switch = sw;
    m_timer = millis();
    m_led_on = false;
    m_program = 0;

    pinMode(m_port_led, OUTPUT);
    pinMode(m_port_switch, INPUT_PULLUP);
    digitalWrite(m_port_led, LOW);
}

int Bouton::led_program()
{
    return m_program;
}

void Bouton::led_program(int i)
{
    m_program = i;
    m_timer = millis();

    if(i > 0)
    {
        m_led_on = true;
        digitalWrite(m_port_led, HIGH);
    }
}

void Bouton::manipulate_timer(int i)
{
    m_timer += i;
}

void Bouton::swap_state()
{
    if(m_led_on)
    {
        digitalWrite(m_port_led, LOW);
        m_led_on = false;
    }
    else
    {
        digitalWrite(m_port_led, HIGH);
        m_led_on = true;
    }
}

bool Bouton::pressed()
{
    return digitalRead(m_port_switch) == LOW;
}

void Bouton::act()
{
    if(m_program < LED_OFF_ON_PUSH) //lowest defined value
        m_program = 0;

    switch(m_program)
    {
        case LED_CONSTANT_OFF:
            if(m_led_on)
            {
                digitalWrite(m_port_led, LOW);
                m_led_on = false;
            }
            return;
        case LED_CONSTANT_ON:
            if(!m_led_on)
            {
                digitalWrite(m_port_led, HIGH);
                m_led_on = true;
            }
            return;
        case LED_ON_ON_PUSH:
            digitalWrite(m_port_led, pressed());
            return;
        case LED_OFF_ON_PUSH:
            digitalWrite(m_port_led, !pressed());
            return;
    }

    //no other program ran so we blink :).
    long current_time = millis();
    if((current_time - m_timer) >= m_program)
    {
        swap_state();
        m_timer = current_time;
    }
}
