#include <Arduino.h>
#include "ultrasound.h"
#include "motors/motors.h"


MouseUltrasound ultrasound_f(2, 4);


void setup() {
    Serial.begin(9600);
}

void loop() {
    unsigned long mm_f = ultrasound_f.get_distance();
    Serial.print("ultrasound f: ");
    Serial.println(mm_f);

    delay(200);
}
