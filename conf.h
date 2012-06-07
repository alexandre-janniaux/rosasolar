#ifndef CONFIGAR_H
#define CONFIGAR_H

////////////////////////////////////////////////////////////
//  SPECIAL VALUES
////////////////////////////////////////////////////////////

#define ENGINE_STOPPED 0
#define ENGINE_INITIALIZE 1
#define ENGINE_STARTED 2

#define DEBUG true
//#define DEBUG_SPEED 95

#define MICROS_CONVERSION 1000

namespace conf // global variables are not the best !
{
////////////////////////////////////////////////////////////
//  PIN CONFIGURATION
////////////////////////////////////////////////////////////
extern const int moteur_pin;

extern const int battery_pin ;
extern const int voltage_divider_ratio; 
extern const float voltage_reference ;

extern const int radio_pin;   

extern const int button_pin ;                
extern const int button_interrupt;

extern const int relay_pin ;
extern const int LED_pin ;

////////////////////////////////////////////////////////////
//  SPEED AND VOLTAGE CONFIGURATION
////////////////////////////////////////////////////////////
extern const unsigned long min_duration;
extern const unsigned long max_duration;

extern float voltage_start ;
extern float voltage_stade_100 ; 
extern float voltage_stade_90 ;
extern float voltage_stade_50 ;
extern float voltage_stade_20 ;

//############################################################*/
//  RADIO INTERRUPTION CONFIGURATION
//############################################################*/

extern volatile int program_mode ;

}

#endif
