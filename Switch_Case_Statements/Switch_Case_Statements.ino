//21921
int const potPin = 1;
int const lastPotValue = 2;
void setup() {
  // put your setup code here, to run once:
pinMode(potPin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int potValue = analogRead(potPin) / 255;

if(potValue != lastPotValue); 
{

switch(potValue)
{
  case 0:
  //do something
  Serial.println("Very Low");
  break;

  case 1:
  //Set at Low
  Serial.println("Low");
  break;
 
  case 2:
  Serial.println("Moderate");
  break;

  case 3:
  //Set at Low
  Serial.println("High");
  break;

  case 4:
  //Set at Low
  Serial.println("Extreme");
  break;

  case 5:
  //Set at Low
  Serial.println("Error");
  break;
  
}
}
}

