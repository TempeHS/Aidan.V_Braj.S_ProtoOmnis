#include <Servo.h>
Servo myservo;
unsigned static int servoPin = 7;
unsigned static int potpin = A2;
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buzzer =  3;      // the number of the buzzer pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  myservo.attach(servoPin);
  // initialize the LED pin as an output:
  pinMode(buzzer, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  int val = analogRead(potpin);
  val = map(val, 0, 1023, 180, 0);
  myservo.write(val);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(buzzer, LOW);
  } else {
    // turn LED off:
    digitalWrite(buzzer, HIGH);
  }
}
