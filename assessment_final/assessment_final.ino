//21291

#include <SparkFun_LPS25HB_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
const int PRESURESENSOR = 2;
const int TEMPSENSOR = 1;
LPS25HB pressureSensor; // Create an object of the LPS25HB class
OpenLog SD;

void setup()
{
  //TEACHER COMMENTS if this is where you begin Serial you don't need it on line 36 do you? but you might want to have the check up here
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
 

  Wire.begin();
  pressureSensor.begin(); // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  if (pressureSensor.isConnected() == false) // This line of code is to chek that the pressure sensor is connected, if not display false.
  {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");     // Alert the user that the device cannot be reached
    Serial.println("Are you using the right Wire port and I2C address?");      // Suggest possible fixes
    Serial.println("See Example2_I2C_Configuration for how to change these."); // Suggest possible fixes
    Serial.println("");
    while (1)
      ;
  }
  

//TEACHER COMMENTS give a comment explaining the purpose of this code 
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin()) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  SD.append("Ricardo.txt");
  Serial.println("card initialized.");
}
}

void loop() {

 String dataString = "";

   //TEACHER COMMENTS what is analogPin? you are reading A0 A1 and A2 but we don't have anything connected to them?
  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }

  //TEACHER COMMENTS I would think the stuff you have around line 100 or so would merge with this well
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

    SD.println(dataString);
    SD.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
  
  //*************************************************************************
   //TEACHER COMMENTS It looks like this comes from the example code and is the tail end of the setup method and the start of the loop but 
  //without the loop(){ part
  //*************************************************************************
  {
  Serial.begin(9600);
  Serial.println("LPS25HB Pressure Sensor Example 3 - Checking the Connection");
  Serial.println();

  Wire.begin();

  pressureSensor.begin(Wire, LPS25HB_I2C_ADDR_DEF); // Begin with I2C settings of your choice (see Example2_I2C_Configuration)
}
{

  if (pressureSensor.isConnected() == true)
  {
    if (pressureSensor.getStatus() == 0x00)
    {
      pressureSensor.begin();  //TEACHER COMMENTS this starts the pressure sensor that you have checked in the last two if statements?! should it not be in the setup method
    } // If it is connected but not responding (for example after a hot-swap) then it may need to be re-initialized
    Serial.print("Connected. Sensor Status: ");
    Serial.print(pressureSensor.getStatus(), HEX); // Read the sensor status, the datasheet can explain what the various codes mean
    Serial.print(", Pressure (hPa): ");
    Serial.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa as determined by dividing the number of ADC counts by 4096 (according to the datasheet)
    Serial.print(", Temperature (degC): ");
    Serial.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C by dividing the ADC count by 480
  }
  else
  {
     //TEACHER COMMENTS explain what this code is doing in a comment
    Serial.println("Disconnected");
    pressureSensor.begin();
  }

  delay(40); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
  }
