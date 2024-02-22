//shared with Mr Hansen successfully :)
// Code setup
#include <Servo.h>
const byte LEDPIN = 13;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;

Servo leftEar;
Servo rightEar;

void setup() {
  //The LED is used as a light source for our coding, this is an output
  pinMode(LEDPIN, OUTPUT);

  // Paw inputs are used as switches or buttons to tell the arduino to activate it's code
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
  leftEar.attach(LEFTEARPIN);
  rightEar.attach(RIGHTEARPIN);
}
void loop() {

  // if paw 1 is on then the LED will light up
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }

  // if paw 2 is on then the LED will light up
  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  // if paw 3 is on then the LED will light up
  if (digitalRead(PAWPIN3) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  // if paw 4 is on then the LED will light up
  if (digitalRead(PAWPIN4) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  
  }
}

   void wagEars() {
  
  leftEar.attach(0);
  leftEar.attach(90);
  leftEar.attach(0);
  
  rightEar.attach(0);
  rightEar.attach(90);
  rightEar.attach(0);

  leftEar.attach(0);
  rightEar.attach(0);
  leftEar.attach(90);
  rightEar.attach(90);
  leftEar.attach(0);
  rightEar.attach(0);
}
  

void blinkingLed() {
  byte randNumber = random(1, 3);

 for (int i = 0; i < randNumber; i++) {
  digitalWrite(LEDPIN, HIGH);
  delay(500);
  digitalWrite(LEDPIN,LOW);
  delay(500);
  }
}
