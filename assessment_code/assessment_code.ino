//21291
#include <SparkFun_LPS25HB_Arduino_Library.h>  // LPS commands
#include <Wire.h> // Connecting components together automatically
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h" // Openlog commands

const int PRESSURE_SENSOR = 2;
const int TEMP_SENSOR = 1;

LPS25HB pressureSensor;  // Create an object of the LPS25HB class
OpenLog SD;

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
  SD.append("Ricardo.txt");
  Serial.println("Card initialized.");
}

void loop() {
  String dataString = "";

  // Read three sensors and append to the string
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }

  SD.println(dataString);  // Save data to SD card
  Serial.println(dataString);  // Print data to the serial port

  // Read and print pressure and temperature data from the pressure sensor
  if (pressureSensor.isConnected() == true) {
    Serial.print("Connected. Sensor Status: ");     // Check if the sensor is connected
    Serial.print(pressureSensor.getStatus(), HEX);  // Read the sensor status
    Serial.print(", Pressure: ");
    Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa
    Serial.print(", Temperature: ");
    Serial.println(pressureSensor.getTemperature_degC());  // Get the temperature in degrees C
  } else {
    Serial.println("Disconnected");  // Alert if the sensor is disconnected
  }

  delay(40);  // Wait for 40 ms (corresponding to the sensor update rate)
}

void ready(bool debug) {
  String dataString = "";

  // Read three sensors and append to the string
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }

  SD.println(dataString);  // Save data to SD card
  Serial.println(dataString);  // Print data to the serial port

  // Read and print pressure and temperature data from the pressure sensor
  if (pressureSensor.isConnected() == true) {
    Serial.print("Connected. Sensor Status: ");     // Check if the sensor is connected
    Serial.print(pressureSensor.getStatus(), HEX);  // Read the sensor status
    Serial.print(", Pressure: ");
    Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa
    Serial.print(", Temperature: ");
    Serial.println(pressureSensor.getTemperature_degC());  // Get the temperature in degrees C
  } else {
    Serial.println("Disconnected");  // Alert if the sensor is disconnected
  }

  delay(40);  // Wait for 40 ms (corresponding to the sensor update rate)
}
