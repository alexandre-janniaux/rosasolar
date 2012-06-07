#include "conf.h"

#include "Arduino.h"


namespace conf // global variables are not the best
{
  
////////////////////////////////////////////////////////////
//  PIN CONFIGURATION
////////////////////////////////////////////////////////////
const int moteur_pin = 9;

const int battery_pin = A4;
const int voltage_divider_ratio = 3; 
const float voltage_reference = 7.5;

const int radio_pin = 3;   

const int button_pin = 2;                
const int button_interrupt = 0;

const int relay_pin = 7;
const int LED_pin = 13;

////////////////////////////////////////////////////////////
//  SPEED AND VOLTAGE CONFIGURATION
////////////////////////////////////////////////////////////
extern const unsigned long min_duration = 1112; // ces valeurs sont en
extern const unsigned long max_duration = 1885; // microsecondes

float voltage_start = 0.f;
float voltage_stade_100 = 0.f; 
float voltage_stade_90 = 0.f;
float voltage_stade_50 = 0.f;
float voltage_stade_20 = 0.f;

////////////////////////////////////////////////////////////
//  RADIO INTERRUPTION CONFIGURATION
////////////////////////////////////////////////////////////
volatile int program_mode = ENGINE_STOPPED;

}
