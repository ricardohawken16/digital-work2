//shared with Mr Hansen successfully :)
// Code setup
const byte LEDPIN = 13;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;

void setup() {
  
  //The LED is used as a light source for our coding, this is an output
  pinMode(LEDPIN, OUTPUT);
  
  // Paw inputs are used as switches or buttons to tell the arduino to activate it's code
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
}

void loop() {
 
 // if paw 1 is on then the LED will light up
if(digitalRead (PAWPIN1) == HIGH){
 digitalWrite (LEDPIN, HIGH);
}
  
 // if paw 2 is on then the LED will light up
if(digitalRead (PAWPIN2) == HIGH){
 digitalWrite (LEDPIN, HIGH);
}
 // if paw 3 is on then the LED will light up
if(digitalRead (PAWPIN3) == HIGH){
 digitalWrite (LEDPIN, HIGH);
}
 // if paw 4 is on then the LED will light up
if(digitalRead (PAWPIN4) == HIGH){
 digitalWrite (LEDPIN, HIGH);
 int score = playGame();
}  

void playMusic(){
 //play an MP3 file here
}

int playGame(){
 byte score = 99;
 //play simon says game
 return score;
 }
}


