#ifndef _ULTRASOUND_H_
#define _ULTRASOUND_H_

#include <Arduino.h>

#define ULTRASOUND_F_TRIG      2
#define ULTRASOUND_F_ECHO      4
#define SPEED_OF_SOUND_MM_US   0.3

void ultrasound_trigger(uint8_t pin);
unsigned long get_ultrasound_distance(uint8_t trig_pin, uint8_t echo_pin);

#endif
