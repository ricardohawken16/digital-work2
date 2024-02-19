const byte BTNPIN = 1;
const byte POTPIN = A1;

void setup() {
  // put your setup code here, to run once:
pinMode(BTNPIN, INPUT);
pinMode(POTPIN, INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(BTNPIN) == HIGH) {
  Serial.println("Rolling dice");
  int diceNum = random(1, 6);
  Serial.println(diceNum);
  
  int diceType = analogRead(POTPIN); 
  diceType = map(diceType, 0, 1023, 1 , 6);
  
}
}
