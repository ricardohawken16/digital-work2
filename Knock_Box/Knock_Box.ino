// 21291
#include <Servo.h>

const byte MICROPIN = 2; 
const byte LEDPIN = 13;
const byte SERVOPIN = 3;
const byte BTNPIN = 1;

Servo latch; 

const byte LOCK = 0;
const byte UNLOCK = 90; 
const byte LOUDENOUGH = 512;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BTNPIN, INPUT); 
  pinMode(MICROPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);  // sets the pin as output
  latch.attach(SERVOPIN);
  
  Serial.begin(9600);

}

void loop() {

  if (digitalRead(BTNPIN) == HIGH) {
  }

  digitalWrite(4, HIGH); // sets the digital pin 13 on
  delay(1000);            // waits for a second
  digitalWrite(4, LOW);  // sets the digital pin 13 off
  delay(1000);            // waits for a second
  
}