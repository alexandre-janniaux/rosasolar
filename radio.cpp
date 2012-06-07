#include "radio.h"
#include "Arduino.h"

////////////////////////////////////////////////////////////
void Radio::init(
    int port
){
    pinMode( port, INPUT );
    m_Port = port;
}

////////////////////////////////////////////////////////////
long Radio::get_speed() {
    unsigned long pulse = pulseIn(conf::radio_pin, HIGH);
    if (pulse > m_Max || pulse < m_Min)
        return map(m_LastPulse, m_Min, m_Max, 0, 180);
    m_LastPulse = pulse;
    return map(pulse, m_Min, m_Max, 0, 180);
}

////////////////////////////////////////////////////////////
long Radio::get_last_pulse() {
    return m_LastPulse;  
}

////////////////////////////////////////////////////////////
void Radio::set_limits(
    long min,
    long max
){
    m_Min = min;
    m_Max = max;
}
