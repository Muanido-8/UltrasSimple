#include <UltrasSimple.h>

UltrasSimple sensor(9, 10);

void setup() {
    Serial.begin(9600);
    sensor.begin();
}

void loop() {
    float distanceCm = sensor.readDistanceCm();
    float distanceIn = sensor.readDistanceInch();

    if (distanceCm < 0) {
        Serial.println("Sem leitura valida");
    } else {
        Serial.print("Distancia (cm): ");
        Serial.print(distanceCm);
        Serial.println(" cm");
        Serial.print("Distancia (in): ");
        Serial.print(distanceIn);
        Serial.println(" in");
    }

    delay(500);
}