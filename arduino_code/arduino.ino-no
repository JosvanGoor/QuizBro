#include "Bouton.hpp"

Bouton red(12, 8);
int state = -3;
long touch = 0;

/*
    Arduino runtime setup.
*/  
void setup()
{
    Serial.begin(9600);
    Serial.setTimeout(1); //1ms latency on com port.
    red.led_program(state);

    pinMode(10, INPUT_PULLUP);
    //red.led_program(LED_CONSTANT_ON);
    red.led_program(1000);
}

/*
    Runtime body
*/
void loop()
{   

    if(digitalRead(10) == LOW && (millis() - touch > 500))
    {
        //Serial.print("Switch is pressed: ");
        touch = millis();
        
        switch(state)
        {
            case -3:
                red.led_program(-2); state = -2;
                //Serial.print("- setting state to -2 - ");
                break;
            case -2:
                red.led_program(-1); state = -1;
                //Serial.print("- setting state to -1 - ");
                break;
            case -1:
                //Serial.print("- setting state to 0 - ");
                red.led_program(0); state = 0;
                break;
            case 0:
                //Serial.print("- setting state to 500 - ");
                red.led_program(1000); state = 1000;
                break;
            case 1000:
                red.led_program(250); state = 250;
                break;
            case 250:
                red.led_program(-3); state = -3;
                break;
        }
    } //else Serial.print("Switch is not pressed: ");

    //Serial.print("state = ");
    //Serial.println(state);
    red.act();
}