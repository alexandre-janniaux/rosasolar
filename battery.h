#ifndef BATTERY_H
#define BATTERY_H
//#include "Arduino.h"
#include "conf.h"
 

////////////////////////////////////////////////////////////
//  SPEED MODULATION ALGORITHM
////////////////////////////////////////////////////////////
int modulate_speed(float input_voltage, long input_speed )
{
    long final_speed = 0;
    input_speed -= 90; // equilibrer la vitesse autour de 0 (90=0, 180=max avant, 0=max arriere
    
    #ifndef DEBUG
        if (input_voltage >= voltage_stade_100) 
            final_speed = input_speed;
        
        else if (input_voltage >= voltage_stade_90) 
            final_speed = int(input_speed * 0.9f);
        
        else if (input_voltage >= voltage_stade_50) 
            final_speed = int(input_speed * 0.5f);
        
        else if (input_voltage >= voltage_stade_20) 
            final_speed = int(input_speed * 0.2f);
        
        else
            final_speed = int(input_speed * 0.2f);
        
        final_speed += 90;
    #else
        final_speed = input_speed+90;        
        Serial.println("....");
        Serial.write("modulated speed : ");
        Serial.println(final_speed);
    #endif
    
    
    return final_speed;
    
}

#endif 
