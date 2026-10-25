# UltrasSimple

**A simple Arduino library for measuring distance with the HC-SR04 ultrasonic sensor. My first arduino library😅**

UltrasSimple provides a straightforward interface for reading distances in centimeters and inches. It encapsulates the trigger and echo operations, allowing you to measure distances without repeating low-level sensor code in every sketch.

## Features

- Measure distances in centimeters.
- Measure distances in inches.
- Simple, object-oriented API.

## Requirements

- An Arduino-compatible board.
- An HC-SR04 ultrasonic sensor.
- Arduino IDE or another compatible build environment.

## Installation

### Manual installation

1. Download or clone this repository.
2. Copy the `UltrasSimple` folder into your Arduino sketchbook's `libraries` directory.
3. Restart the Arduino IDE.
4. Include the library in your sketch:

```cpp
#include <UltrasSimple.h>
```

## Wiring

Example using an Arduino Uno:

| HC-SR04 | Arduino Uno    |
| ------- | -------------- |
| VCC     | 5V             |
| GND     | GND            |
| TRIG    | Digital pin 9  |
| ECHO    | Digital pin 10 |

Make sure your board's logic levels are compatible with the sensor.

## Quick Start

```cpp
#include <UltrasSimple.h>

UltrasSimple sensor(9, 10);

void setup() {
    Serial.begin(9600);
    sensor.begin();
}

void loop() {
    float distance = sensor.readDistanceCm();

    if (distance < 0) {
        Serial.println("No valid reading");
    } else {
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
    }

    delay(500);
}
```

## API Reference

### Constructor

```cpp
UltrasSimple(uint8_t trigPin, uint8_t echoPin);
```

Creates a sensor instance using the specified trigger and echo pins.

### `begin()`

```cpp
void begin();
```

Initializes the trigger pin as an output and the echo pin as an input. Call this method from `setup()` before taking measurements.

### `readDistanceCm()`

```cpp
float readDistanceCm();
```

Measures and returns the distance in centimeters.

Returns `-1.0` when no echo is received before the configured timeout.

### `readDistanceInch()`

```cpp
float readDistanceInch();
```

Measures and returns the distance in inches.

Returns `-1.0` when no echo is received before the configured timeout.

**Note:** Each call triggers a new measurement. Calling both distance methods consecutively performs two separate measurements.

### `getTrigPin()`

```cpp
uint8_t getTrigPin();
```

Returns the configured trigger pin number.

### `getEchoPin()`

```cpp
uint8_t getEchoPin();
```

Returns the configured echo pin number.

## How It Works

UltrasSimple sends a short trigger pulse to the HC-SR04 and measures the duration of the returning echo pulse.

The distance is calculated using the approximate speed of sound:

- Centimeters: `duration * 0.0343 / 2.0`
- Inches: `duration * 0.0135 / 2.0`

The division by two accounts for the sound traveling to the target and back.

## Limitations

- Measurement accuracy depends on the sensor, target surface, alignment, temperature, and environmental conditions.
- Objects that are small, soft, or angled may produce unreliable readings.
- A missing echo is represented by `-1.0`; check for negative results before using a measurement.

## License

See the `LICENSE` file in this repository for the terms governing the use, modification, and distribution of this library.

## Contributing

Contributions, bug reports, and suggestions are welcome. Please open an issue or submit a pull request.

---

**UltrasSimple** — simple distance measurements for Arduino projects.

## Enjoy! Peace and love 😇✌️☺️