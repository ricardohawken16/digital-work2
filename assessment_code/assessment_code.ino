//21291
#include <SparkFun_LPS25HB_Arduino_Library.h>  // LPS commands
#include <Wire.h> // Connecting components together automatically
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h" // Openlog commands

const int PRESSURE_SENSOR = 2;
const int TEMP_SENSOR = 1;

LPS25HB pressureSensor;  // Create an object of the LPS25HB class
OpenLog SD; // Pulling sd card

void setup() {
  Serial.begin(9600);  // Serial begins and sets data rate for code setup
  while (!Serial) {
    ;  // Wait for serial port to connect
  }

  Wire.begin();  // Join the I2C as a controller or hardware
  pressureSensor.begin();  // Initialize the pressure sensor
  if (pressureSensor.isConnected() == false) {  // Check if the pressure sensor is connected
    Serial.println("LPS25HB disconnected. Reset the board to try again.");  // Alerts the user that the device cannot be read
    while (1)
      ;
  }

  Serial.print("Initializing SD card...");
  if (!SD.begin()) {  // See if the card is present and can be initialized
    Serial.println("Card failed, or not present");
    while (1)
      ;
  }
  SD.begin();
  SD.append("Ricardo.csv");
  Serial.println("Card initialized.");
}

void loop() {
  ready(true); // Tells the code chunk if debug is true then it will only debug and only use serial monitor, if false we are launching and only using it for the sd to write 
               // Otherwise the sd will give a error status
}

void ready(bool debug) {
 
// millis();

  // Read and print pressure and temperature data from the pressure sensor
  if(debug){
  (pressureSensor.isConnected()==true); { // Powering on sensor
    Serial.print("millis: ");
    Serial.print(", Pressure: ");
    Serial.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa
    Serial.print(", Temperature: ");
    Serial.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C

  }
  
    
    SD.print(millis());
    SD.print(", ");
    SD.print(pressureSensor.getPressure_hPa());
    SD.print(", ");
    SD.print(pressureSensor.getTemperature_degC());
    SD.print(", ");
    SD.println(); // To add a new line at the end
  delay(40); // Code will take 40 millis to perform the next loop again
  }
}
