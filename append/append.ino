#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
OpenLog sdCard; //Create instance

int ledPin = LED_BUILTIN; //Status LED connected to digital pin 13

const String FILENAME = "joke.txt"; //Default Qwiic OpenLog I2C address

void setup()
{
  pinMode(ledPin, OUTPUT);

  Wire.begin();
  sdCard.begin();
  sdCard.begin(); //Open connection to OpenLog (no pun intended)

  Serial.begin(9600); //9600bps is used for debug statements
  sdCard.append(FILENAME);
  sdCard.syncFile();


  
  sdCard.syncFile();

  Serial.println("Done!");
}

void loop()
{
sdCard.println("Knock knock Joke");
Serial.println("Knock knock Joke");

sdCard.println("who's there?");
Serial.println("who's there?");

sdCard.println("I see the light");
Serial.println("I see the light");

sdCard.println("I see light who?");
Serial.println("I see light who?");

sdCard.println("I see the light in Jayden's skin thats who");
Serial.println("I see the light in Jayden's skin thats who");

sdCard.println("Knock knock Joke");
Serial.println("Knock knock Joke");

  sdCard.syncFile();
}
