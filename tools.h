#ifndef TOOLS_H
#define TOOLS_H

#include "conf.h"
#include "Arduino.h"

////////////////////////////////////////////////////////////
//  FUNCTION TO HANDLE LED
////////////////////////////////////////////////////////////
void set_led (bool value)
{
    if(value)
        digitalWrite(conf::LED_pin, LOW);
    else
        digitalWrite(conf::LED_pin, HIGH);
}

////////////////////////////////////////////////////////////
//  INTERRUPT CALLBACK FUNCTION FOR RADIO
////////////////////////////////////////////////////////////
void on_button_start_pressed()
{
  //begin engine start sequence
    if(conf::program_mode == ENGINE_STOPPED && digitalRead(conf::button_pin) == HIGH) 
    {
        conf::program_mode = ENGINE_INITIALIZE;
    }/*
    else if(program_mode == ENGINE_STARTED)
    {
        program_mode = ENGINE_STOPPED;
        detachInterrupt(radio_interrupt);  
    }
    */
}

////////////////////////////////////////////////////////////
//  TOOL FONCTION
////////////////////////////////////////////////////////////
float read_voltage(
    int pin
) {
    int input_value = analogRead(pin);    
    return (float)(input_value)*conf::voltage_divider_ratio* conf::voltage_reference /1023; 
}

#endif 
