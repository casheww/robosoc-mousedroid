#ifndef _ULTRASOUND_H_
#define _ULTRASOUND_H_

#include <Arduino.h>

#define SPEED_OF_SOUND_MM_US   0.3

class MouseUltrasound {
public:
    MouseUltrasound(uint8_t trig_pin, uint8_t echo_pin);
    unsigned long get_distance(void);

private:
    void _trigger(void);
    uint8_t trig_pin;
    uint8_t echo_pin;
};

#endif
