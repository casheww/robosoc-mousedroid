#include "ultrasound.h"


MouseUltrasound::MouseUltrasound(uint8_t trig_pin, uint8_t echo_pin) {
    this->trig_pin = trig_pin;
    this->echo_pin = echo_pin;
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
}

unsigned long MouseUltrasound::get_distance_mm(void) {
    _trigger();
    unsigned long us = pulseIn(echo_pin, HIGH);
    unsigned long mm = (us/2) * SPEED_OF_SOUND_MM_US;       // time[us] halved to account for return journey of signal
    return mm;
}

void MouseUltrasound::_trigger(void) {
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
}
