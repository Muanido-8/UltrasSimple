#ifndef ULTRAS_SIMPLE_H
#define ULTRAS_SIMPLE_H

#include <Arduino.h>

class UltrasSimple {
    public:
        UltrasSimple(uint8_t trigPin, uint8_t echoPin);
        uint8_t getTrigPin();
        uint8_t getEchoPin();
        float readDistanceCm();
        float readDistanceInch();
        void begin();

    private:
        uint8_t _trigPin;
        unsigned long read();
        uint8_t _echoPin;
};
#endif