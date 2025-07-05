#include <Servo.h>

Servo servo1;

int trig = 11;
int echo = 12;
int servo = 13;

void setup() {
  Serial.begin(9600);
  Serial.println();
  
  servo1.attach(servo);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int time = pulseIn(echo, HIGH);
  double distance = (time * 0.0344) / 2;
  Serial.println(distance);
  
  if (0 < distance && distance < 10) {
    servo1.write(0);
    delay(250);
  }
  else {
    servo1.write(180);
    delay(250);
  }
}
