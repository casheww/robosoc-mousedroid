#include "ultrasound.h"


void ultrasound_trigger(uint8_t pin) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);
}

unsigned long get_ultrasound_distance(uint8_t trig_pin, uint8_t echo_pin) {
    ultrasound_trigger(trig_pin);
    unsigned long us = pulseIn(echo_pin, HIGH);
    unsigned long mm = (us / 2) * SPEED_OF_SOUND_MM_US;
    return mm;
}
