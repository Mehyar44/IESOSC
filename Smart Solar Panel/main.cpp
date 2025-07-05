#include <Servo.h>

const int ldr1Pin = A0;
const int ldr2Pin = A1;
const int servoPin = 3;
const int threshold = 300;
const int stepSize = 3;
const int loopDelay = 500;
int currentAngle = 90;

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(currentAngle);
  delay(500);
}

void loop() {
  int val1 = analogRead(ldr1Pin);
  int val2 = analogRead(ldr2Pin);

  Serial.print("LDR1: ");
  Serial.print(val1);
  Serial.print("   LDR2: ");
  Serial.println(val2);

  int newAngle = currentAngle;

  if (val1 > val2 + threshold) {
    newAngle = currentAngle - stepSize;
  }
  else if (val2 > val1 + threshold) {
    newAngle = currentAngle + stepSize;
  }

  if (newAngle < 0)   newAngle = 0;
  if (newAngle > 180) newAngle = 180;

  if (newAngle > currentAngle) {
    for (int angle = currentAngle; angle <= newAngle; angle++) {
      myServo.write(angle);
      delay(10);
    }
  }
  else if (newAngle < currentAngle) {
    for (int angle = currentAngle; angle >= newAngle; angle--) {
      myServo.write(angle);
      delay(10);
    }
  }

  currentAngle = newAngle;
  delay(loopDelay);
}
