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
