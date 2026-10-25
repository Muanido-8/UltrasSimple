#include <UltrasSimple.h>

UltrasSimple sensor(9, 10);

void setup() {
    Serial.begin(9600);
    sensor.begin();
}

void loop() {
    float distance = sensor.readDistanceCm();

    if (distance < 0) {
        Serial.println("Sem leitura valida");
    } else {
        Serial.print("Distancia: ");
        Serial.print(distance);
        Serial.println(" cm");
    }

    delay(500);
}