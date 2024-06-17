//21291
#include <SparkFun_LPS25HB_Arduino_Library.h>        // LPS commands
#include <Wire.h>                                    // Connecting components together automatically
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>  // Openlog commands

LPS25HB pressureSensor;  // Create an object of the LPS25HB class
OpenLog SD;              // Pulling sd card

void setup() {
  Serial.begin(9600);  // Serial begins and sets data rate for code setup
  while (!Serial) {    // Wait for serial port to connect
    ;
  }

  Wire.begin();                                                             // Join the I2C as a controller or hardware
  pressureSensor.begin();                                                   // Initialize the pressure sensor
  if (pressureSensor.isConnected() == false) {                              // Check if the pressure sensor is connected
    Serial.println("LPS25HB disconnected. Reset the board to try again.");  // Alerts the user that the device cannot be read
    while (1)
      ;
  }

  Serial.print("Initializing SD card...");          // Stating that the sd card is trying to be reached
  if (!SD.begin()) {                                // See if the card is present and can be initialized
    Serial.println("Card failed, or not present");  // The sd card is not working
    while (1)
      ;
  }
  SD.begin();                           // Start the sd card writing process
  SD.append("Ricardo.txt");             // Named the sd card my name so it is easier to tell if its my code from the sd card
  Serial.println("Card initialized.");  // Sd card is in and working properly
  SD.syncFile();                        // Syncs every sd.print and pushes it to a singular line once the code has done its loop
}

void loop() {
  ready(true);  // Tells the code chunk if debug is true then it will only debug and only use serial monitor, if false we are launching and only using it for the sd to write
                // Otherwise the sd will give a error status
}

void ready(bool debug) {  //My method for my debug function


  // Read and print pressure and temperature data from the pressure sensor
  if (debug) {
    (pressureSensor.isConnected() == true);
    {                                                  // Powering on sensor
      Serial.print(" Millis: ");                       // Get millis
      Serial.print(millis());                          // Display millis
      Serial.print(", Pressure: ");                    // Write pressure
      Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa
      Serial.print(", Temperature: ");
      Serial.println(pressureSensor.getTemperature_degC());  // Get the temperature in degrees C
    }

    SD.print(millis());                                // Get time in millis and print to the sd
    SD.print(", ");                                    // Formats csv file
    SD.print(pressureSensor.getPressure_hPa());        // Gets pressure in hpa and print to the sd
    SD.print(", ");                                    // Formats csv file
    SD.println(pressureSensor.getTemperature_degC());  // Get temperture in degrees and print to the sd
    SD.syncFile();                                     // Syncs every sd.print and pushes it to a singular line once the code has done its loop
    delay(40);                                         // Code will take 40 millis to perform the next loop again
  }
}
