////////////////////////////////////////////////////////////
#include "engine.h"
#include "Arduino.h"

////////////////////////////////////////////////////////////
void Engine::init( 
    int port,
    int relay_pin
) {
    m_Engine.attach (port);
    pinMode (relay_pin, OUTPUT);
    m_Port = port;
    m_Relay_pin = relay_pin;
    m_Engine.writeMicroseconds(1500);
}

////////////////////////////////////////////////////////////
void Engine::wait () {
      m_Engine.writeMicroseconds(1500);
      delayMicroseconds (20000-1500);
}

////////////////////////////////////////////////////////////
void Engine::pulse (unsigned long pulse) {
      m_Engine.writeMicroseconds(pulse);
      delayMicroseconds (20000-pulse);
}


////////////////////////////////////////////////////////////
void Engine::start () {
    unsigned long ms = millis();
    while (millis()-ms < 2500)
    {
      m_Engine.writeMicroseconds(1000);
      delayMicroseconds(20000-1000);
    } 
}

////////////////////////////////////////////////////////////
void Engine::set_speed (
    int speed
) {
    if ( speed == m_Speed)
      return;
      
    if (speed > 180)
      speed = 180;
        
    else if (speed < 0)
      speed = 0;
        
    if (!m_LockedMode)
    {
      if (speed < 90)
        set_mode(BACKWARD);
      else
        set_mode(FORWARD);
    }
    //if (speed < 90)
      //speed = map(speed, 90, 0, 90, 180);   
    m_Speed = speed;
}

////////////////////////////////////////////////////////////
int Engine::get_current_speed () {
    return m_CurrentSpeed;
}

////////////////////////////////////////////////////////////
void Engine::run () {
    pulse (map(m_CurrentSpeed,0,180,1000, 2000));
    
    // TODO: Calculate next speed
    m_CurrentSpeed = m_Speed;
}

////////////////////////////////////////////////////////////
void Engine::set_mode (
    MODE mode,
    bool lock
) {
    if (m_Mode != mode)
    {
        m_Mode = mode; 
        if (mode == FORWARD)
          digitalWrite(m_Relay_pin, HIGH);
        else
          digitalWrite(m_Relay_pin, LOW);
    }
    m_LockedMode = lock;
}
