#include <SoftwareSerial.h>

SoftwareSerial lcd(255, 8);

void setup() {
  lcd.begin(9600);
}

void loop() {
  lcd.write(12);
  lcd.write(17);
  lcd.print("Hello");
  delay(1500);
  lcd.write(12);
  lcd.print("World");
  delay(1500);
}
