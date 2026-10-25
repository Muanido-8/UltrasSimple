#include "UltrasSimple.h"

UltrasSimple::UltrasSimple(uint8_t trigPin, uint8_t echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
}

void UltrasSimple::begin() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);

    digitalWrite(_trigPin, LOW);
}

unsigned long UltrasSimple::read() {
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    unsigned long duration = pulseIn(_echoPin, HIGH);
    return duration;
}

float UltrasSimple::readDistanceCm() {
    unsigned long duration = read();

    if (duration == 0) {
        return -1.0;
    }

    return duration * 0.0343 / 2.0;
}

float UltrasSimple::readDistanceInch() {
    unsigned long duration = read();

    if (duration == 0) {
        return -1.0;
    }

    return duration * 0.0135 / 2.0;
}

uint8_t UltrasSimple::getTrigPin() {
    return _trigPin;
}

uint8_t UltrasSimple::getEchoPin() {
    return _echoPin;
}