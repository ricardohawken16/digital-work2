const int TEMPSENSOR = 1

void setup() {
Serial.begin(9600);

}
int potValue = analogRead(potPin) / 255;

if(potValue != lastPotValue) 
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
