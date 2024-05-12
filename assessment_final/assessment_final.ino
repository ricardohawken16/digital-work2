//21291

#include <SparkFun_LPS25HB_Arduino_Library.h>  //LPS commands
#include <Wire.h> //connecting components together automatically
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h" //Openlog commands
const int PRESURESENSOR = 2;
const int TEMPSENSOR = 1;
LPS25HB pressureSensor;  // Create an object of the LPS25HB class
OpenLog SD;

void setup() {
  Serial.begin(9600);  //Serial begins and sets data rate for code setup
  while (!Serial) {
    ;


    Wire.begin();                               //joins the I2C as a controller or hardware
    pressureSensor.begin();                     // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
    if (pressureSensor.isConnected() == false)  // This line of code is to chek that the pressure sensor is connected, if not display false.
    {
      Serial.println("LPS25HB disconnected. Reset the board to try again.");  // Alert the user that the device cannot be reached
      while (1)
        ;
    }


    //TEACHER COMMENTS give a comment explaining the purpose of this code
    Serial.print("Initializing SD card...");

    // see if the card is present and can be initialized:
    if (!SD.begin()) {
      Serial.println("Card failed, or not present");
      // don't do anything more:
      while (1)
        ;
    }
    SD.append("Ricardo.txt");
    Serial.println("card initialized.");
  }
}

void loop() {
  //millis();
  String dataString = "";

  //analog pin = 0
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
  // print to the serial port too:
  Serial.println(dataString);
  {
    Serial.begin(9600);

    Wire.begin();

    pressureSensor.begin(Wire, LPS25HB_I2C_ADDR_DEF);  // Begin with I2C settings of your choice (see Example2_I2C_Configuration)

    if (pressureSensor.isConnected() == true) {
      if (pressureSensor.getStatus() == 0x00) {
      }
      Serial.print("Connected. Sensor Status: ");     // If it is connected but not responding (for example after a hot-swap) then it may need to be re-initialized
      Serial.print(pressureSensor.getStatus(), HEX);  // Read the sensor status, the datasheet can explain what the various codes mean
      Serial.print(", Pressure: ");
      Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa as determined by dividing the number of ADC counts by 4096 (according to the datasheet)
      Serial.print(", Temperature: ");
      Serial.println(pressureSensor.getTemperature_degC());  // Get the temperature in degrees C by dividing the ADC count by 480
    }

    Serial.println("Disconnected");  //Disconnecting and Restarting code since void loop is continuous
    pressureSensor.begin();
    delay(40);  // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
  }

  ready(false);  //true is debug on desk false is going on rocket
}

void ready(bool debug) {

  String dataString = "";


  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  


  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

  SD.println(dataString);
  // print to the serial port too:
  Serial.println(dataString);
  {
    Serial.begin(9600);

    Wire.begin();

    pressureSensor.begin(Wire, LPS25HB_I2C_ADDR_DEF);  // Begin with I2C settings of your choice (see Example2_I2C_Configuration)

    if (pressureSensor.isConnected() == true) {
      if (pressureSensor.getStatus() == 0x00) {
      }
      Serial.print("Connected. Sensor Status: ");     // If it is connected but not responding (for example after a hot-swap) then it may need to be re-initialized
      Serial.print(pressureSensor.getStatus(), HEX);  // Read the sensor status, the datasheet can explain what the various codes mean
      Serial.print(", Pressure: ");
      Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa as determined by dividing the number of ADC counts by 4096 (according to the datasheet)
      Serial.print(", Temperature: ");
      Serial.println(pressureSensor.getTemperature_degC());  // Get the temperature in degrees C by dividing the ADC count by 480
    }

    
    Serial.println("Disconnected");  //Disconnecting and Restarting code since void loop is continuous
    pressureSensor.begin();
    delay(40);  // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
  }

}else {

  {
    millis();
    String dataString = "";
  }


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
  // print to the serial port too:
  Serial.println(dataString);
  {
    Serial.begin(9600);

    Wire.begin();

    pressureSensor.begin(Wire, LPS25HB_I2C_ADDR_DEF);  // Begin with I2C settings of your choice (see Example2_I2C_Configuration)

    if (pressureSensor.isConnected() == true) {
      if (pressureSensor.getStatus() == 0x00) {
      }
      Serial.print("Connected. Sensor Status: ");     // If it is connected but not responding (for example after a hot-swap) then it may need to be re-initialized
      Serial.print(pressureSensor.getStatus(), HEX);  // Read the sensor status, the datasheet can explain what the various codes mean
      Serial.print(", Pressure: ");
      Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa as determined by dividing the number of ADC counts by 4096 (according to the datasheet)
      Serial.print(", Temperature: ");
      Serial.println(pressureSensor.getTemperature_degC());  // Get the temperature in degrees C by dividing the ADC count by 480
    }

    Serial.println("Disconnected");  //Disconnecting and Restarting code since void loop is continuous
    pressureSensor.begin();
    delay(40);  // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
  }
}
