
#include "Ultrasonic.h"
#include <Servo.h>

Ultrasonic sensor(5);
Servo myServo;

#define servoTwo 6
#define servoPin 7
static signed int potpin = A2;
unsigned long previousMillis = 0;
const unsigned long gateInterval = 0;

void setup() {
  
  myServo.attach(servoPin);
  myServo.write(180);

  Serial.begin(9600);

}

void loop() {

  unsigned long currentMillis = millis();
  int val = analogRead(potpin);  
  Serial.println(sensor.distanceRead());
  
    if (sensor.distanceRead() <= 30) {    
    myServo.write(0);
    previousMillis = currentMillis;



  } else {



    if (currentMillis - previousMillis >= gateInterval) {

      myServo.write(180);

    }

  }

  val = map(val, 0, 1023, 0, 180);
  myServo.write(val);
  
  Serial.println(analogRead(potpin));

}