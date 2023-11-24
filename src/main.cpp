#include <Arduino.h>

#define ULTRASOUND_F_TRIG      2
#define ULTRASOUND_F_ECHO      4
#define SPEED_OF_SOUND_MM_US   0.3


void ultrasound_trigger(uint8_t pin);
unsigned long get_ultrasound_distance(uint8_t trig_pin, uint8_t echo_pin);

void setup() {
    Serial.begin(9600);

    pinMode(ULTRASOUND_F_TRIG, OUTPUT);
    pinMode(ULTRASOUND_F_ECHO, INPUT);
}

void loop() {
    unsigned long mm_f = get_ultrasound_distance(ULTRASOUND_F_TRIG, ULTRASOUND_F_ECHO);
    Serial.print("ultrasound f: ");
    Serial.println(mm_f);

    delay(2);
}


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
