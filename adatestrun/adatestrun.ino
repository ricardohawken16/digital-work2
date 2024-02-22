// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte BTNPIN = 1;
const byte POTPIN = A1;
const byte NOISEPIN = A0;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  pinMode(BTNPIN, INPUT);
pinMode(POTPIN, INPUT);

Serial.begin(9600);

}

void loop() {
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  
  delay(500);
  if (digitalRead(BTNPIN) == HIGH) {
  Serial.println("Rolling dice");
  int diceNum = random(1, 6);
  Serial.println(diceNum);
  
  int diceType = analogRead(POTPIN); 
  diceType = map(diceType, 0, 1023, 1 , 6);
  }
}

