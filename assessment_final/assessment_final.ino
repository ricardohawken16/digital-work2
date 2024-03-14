//21291

#include <SparkFun_LPS25HB_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB

const int TEMPSENSOR = 1
LPS25HB pressureSensor; // Create an object of the LPS25HB class

void setup()
{
  Serial.begin(9600);
  Serial.println("LPS25HB Pressure Sensor Example 1 - Basic Readings");
  Serial.println();

  Wire.begin();
  pressureSensor.begin(); // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings

  if (pressureSensor.isConnected() == false) // The library supports some different error codes such as "DISCONNECTED"
  {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");     // Alert the user that the device cannot be reached
    Serial.println("Are you using the right Wire port and I2C address?");      // Suggest possible fixes
    Serial.println("See Example2_I2C_Configuration for how to change these."); // Suggest possible fixes
    Serial.println("");
    while (1)
      ;
  }
}

void loop()
{

  #include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
OpenLog myLog; //Create instance

int ledPin = LED_BUILTIN; //Status LED connected to digital pin 13

const byte OpenLogAddress = 42; //Default Qwiic OpenLog I2C address
{
  pinMode(ledPin, OUTPUT);

  Wire.begin();
  myLog.begin(); //Open connection to OpenLog (no pun intended)

  Serial.begin(9600); //9600bps is used for debug statements
  Serial.println("Run OpenLog Append File Test");
  myLog.println("Run OpenLog Append File Test");

  myLog.println("This is recorded to the default log file");
  myLog.append("bottole_rocket.txt");
  myLog.println("This is recorded to appendMe.txt");
  myLog.println("If this file doesn't exist it is created and");
  myLog.println("anything sent to OpenLog will be recorded to this file");

  myLog.println();
  myLog.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  myLog.append("appendMe1.txt");
  myLog.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  myLog.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  myLog.syncFile();

  Serial.println("Done!");
}

void loop()
{
  //Blink the Status LED because we're done!
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
#include <SparkFun_LPS25HB_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB

LPS25HB pressureSensor; // Create an object of the LPS25HB class

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
      pressureSensor.begin();
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
    Serial.println("Disconnected");
    pressureSensor.begin();
  }
  delay(100);
}

  Serial.print("Pressure in hPa: ");
  Serial.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa
  Serial.print(", Temperature (degC): ");
  Serial.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C

  delay(40); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}