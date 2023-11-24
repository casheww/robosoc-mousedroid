#include <Arduino.h>
#include "ultrasound.h"

void setup() {
    Serial.begin(9600);

    pinMode(ULTRASOUND_F_TRIG, OUTPUT);
    pinMode(ULTRASOUND_F_ECHO, INPUT);
}

void loop() {
    unsigned long mm_f = get_ultrasound_distance(ULTRASOUND_F_TRIG, ULTRASOUND_F_ECHO);
    Serial.print("ultrasound f: ");
    Serial.println(mm_f);

    delay(200);
}
