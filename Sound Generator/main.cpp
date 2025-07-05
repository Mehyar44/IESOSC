int sound = 2;
int echo = 4;
int trig = 7;

void setup() {
  Serial.begin(9600);
  Serial.println();

  pinMode(sound, OUTPUT);
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
    tone(sound, random(0,5000));
    delay(250);
  }
  else {
    noTone(sound);
  }
}
