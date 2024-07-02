
# Obstruction and Edge Avoiding Car
---

## Overview

This project is designed to develop an autonomous car capable of navigating its environment while avoiding edges and obstacles. Using Internet of Things (IoT) technologies, the car integrates various sensors and a microcontroller to achieve autonomous navigation.

## Components Used

- **Chassis Kit of Car**: Structural frame and wheels.
- **Arduino Uno Board**: Microcontroller for processing and control.
- **IR Sensors**: For edge detection.
- **Ultrasonic Sensors**: For obstacle detection.
- **Batteries (40V, 4 nos)**: Power source for the car's electronics.
- **Wires**: For connections between components.

## Circuit Diagram

![Wiring Diagram](docs/wiring_diagram.png)

- **IR Sensor** connected to `A0`.
- **Ultrasonic Sensor** connected to `9` (Trig) and `10` (Echo).
- **Motors** connected to `3` (Left Motor) and `5` (Right Motor).

## Software Requirements

- **Arduino IDE**: For programming the Arduino Uno.

## Arduino Code

```cpp
#include <Ultrasonic.h>

// Define sensor pins
#define IR_SENSOR_PIN A0
#define ULTRASONIC_TRIG_PIN 9
#define ULTRASONIC_ECHO_PIN 10
#define MOTOR_LEFT_PIN 3
#define MOTOR_RIGHT_PIN 5

Ultrasonic ultrasonic(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN);

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(MOTOR_LEFT_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int irValue = analogRead(IR_SENSOR_PIN);
  long distance = ultrasonic.read();

  if (irValue < THRESHOLD) {
    // Edge detected
    avoidEdge();
  } else if (distance < SAFE_DISTANCE) {
    // Obstacle detected
    avoidObstacle();
  } else {
    // Move forward
    moveForward();
  }
}

void avoidEdge() {
  moveBackward();
  delay(500);
  turnRight();
  delay(300);
}

void avoidObstacle() {
  moveBackward();
  delay(500);
  turnLeft();
  delay(300);
}

void moveForward() {
  digitalWrite(MOTOR_LEFT_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN, HIGH);
}

void moveBackward() {
  digitalWrite(MOTOR_LEFT_PIN, LOW);
  digitalWrite(MOTOR_RIGHT_PIN, LOW);
}

void turnRight() {
  digitalWrite(MOTOR_LEFT_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN, LOW);
}

void turnLeft() {
  digitalWrite(MOTOR_LEFT_PIN, LOW);
  digitalWrite(MOTOR_RIGHT_PIN, HIGH);
}
```

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/abstraction-edge-avoiding-car.git
   ```

2. Install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).

3. Open the Arduino IDE and load the `abstraction_edge_avoiding_car.ino` file.

4. Select the correct board and port from the Tools menu and upload the code to your Arduino Uno.

## Testing

1. Power the car using the 40V batteries.
2. Place the car on a flat surface and observe its behavior.
3. Ensure the car detects edges and obstacles correctly, adjusting the sensor sensitivity as needed.

## Troubleshooting

- **Car does not move**: Check motor connections and battery voltage.
- **Sensors not detecting edges or obstacles**: Verify sensor wiring and calibration.

## Future Improvements

- Enhance sensor accuracy and range.
- Integrate additional sensors for improved navigation.
- Optimize control algorithms for smoother movement.

## Contributing

Contributions are welcome! Feel free to fork the repository, make changes, and submit a pull request.
