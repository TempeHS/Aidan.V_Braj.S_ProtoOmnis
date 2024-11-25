#include <Servo.h>
Servo myservo;
unsigned static int servoPin = 7;
unsigned static int potpin = A2;


void setup() {
  myservo.attach(servoPin);
}

void loop() {
  int val = analogRead(potpin);
  val = map(val, 0, 1023, 180, 0);
  myservo.write(val);
}
