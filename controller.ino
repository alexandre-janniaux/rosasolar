
// CONF PROVIDE ALL THE VARIABLES AVAILABLE TO SETUP THE PROGRAM
#include "conf.h"
// ENGINE PROVIDE FACILITIES TO CONTROL THE DC ENGINE
#include "engine.h"
// RADIO TO GET THE PULSE
#include "radio.h"
// TOOLS GIVE ALL THE FUNCTIONS THAT MAKE THE PROGRAM SIMPLER
#include "tools.h"
// ALGORITHMS FOR BATTERY
#include "battery.h"

Engine engine;
Radio radio;

//############################################################*/
//  SETUP
//############################################################*/
void setup()
{
    Serial.begin(9600);           //  initialisation de la connexion série                            
    
    engine.init(
        conf::moteur_pin,
        conf::relay_pin
    );
    
    radio.init(
        conf::radio_pin
    );
    
    radio.set_limits(
        conf::min_duration,
        conf::max_duration
    );
        
    pinMode(
        conf::button_pin, 
        INPUT
    );
        
    pinMode(
        conf::LED_pin, 
        OUTPUT
    );
    
    #ifdef DEBUG
      Serial.println("Programme demarre");
    #endif
    set_led(false);
    
    
    attachInterrupt(
        conf::button_interrupt,
        on_button_start_pressed, 
        FALLING
    );
}


//############################################################*/
//  MAIN LOOP FUNCTION
//############################################################*/
void loop()
{

    if (conf::program_mode == ENGINE_STOPPED)
    {
        #ifdef DEBUG
            static unsigned long ms = millis();
            Serial.write("speed: ");            
            Serial.println(radio.get_speed());
            Serial.write(" millis : ");
            Serial.println(millis()-ms);
            ms = millis();
            engine.pulse(radio.get_last_pulse());
        #endif
    }
    else if(conf::program_mode == ENGINE_INITIALIZE)
    {
        engine.start();
        
        {
          using namespace conf;
          voltage_start = read_voltage(battery_pin);
          voltage_stade_100 = voltage_start -1.f; // enlever 1 pour laisser une marge
          voltage_stade_90 = voltage_start * 0.9;
          voltage_stade_50 = voltage_start * 0.5;
          voltage_stade_20 = voltage_start * 0.2;
          program_mode = ENGINE_STARTED;
        }
        
        detachInterrupt(conf::button_interrupt);
        #ifdef DEBUG
          Serial.println("Moteur demarre");
        #endif
    }
    else if (conf::program_mode == ENGINE_STARTED)
    {
        long speed = radio.get_speed();
        
        #ifdef DEBUG
            Serial.write("speed: ");
            Serial.println(speed);
            Serial.write("duration: ");
            Serial.println(radio.get_last_pulse());
        #endif
        
        engine.set_speed (modulate_speed(read_voltage(conf::battery_pin), speed));
        engine.run();
    }
}
