#ifndef RADIO_H
#define RADIO_H

#include "conf.h"
//#include "Arduino.h"

class Radio
{
public:
    ////////////////////////////////////////////////////////////
    // Initialise la radio sur un port
    // \param port : le port a binder
    ////////////////////////////////////////////////////////////
    void init(
        int port
    );

    ////////////////////////////////////////////////////////////
    // Recupere la vitesse demande
    // \return la vitesse demande par la telecommande
    ////////////////////////////////////////////////////////////
    long get_speed();
    
    ////////////////////////////////////////////////////////////
    // Recupere la longueur de la derniere pulsation recue
    // \return la longueur de la derniere pulsation
    ////////////////////////////////////////////////////////////
    long get_last_pulse();
    
    ////////////////////////////////////////////////////////////
    // Defini les durees maximales et minimales de la pulsation
    // \param min : la duree minimale
    // \param max : la duree maximale
    ////////////////////////////////////////////////////////////
    void set_limits(
        long min,
        long max
    );
    
private:
    int m_Port;
    unsigned long m_Min;
    unsigned long m_Max;
    unsigned long m_LastPulse;

};

#endif 
