// include headers
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>



// testing var below
//

const int xpin = A2;                  // x-axis of the accelerometer
const int ypin = A3;                  // y-axis of accelerometer





// setting up data files
File dataFileX;
File dataFileY;


void setup() {
  
  // wait for serial port to open and connect
  Serial.begin(9600);

  
  // slave select (SS) pin 10, selecting SD card
  pinMode(10, OUTPUT);

  // checking SD module
  if (!SD.begin(10)){
    Serial.println("ERROR: SD Not Initialized");
    return;
  }
}


// SAVING SENSOR DATA TO STRING

void loop() {

  Serial.println("Accel (X): ");
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.println("Accel (Y): ");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");




   
  // save X-axis data
  String dataStringX = "";
  // selecting pin
  int analogPinX = 7;
  int sensorX = analogRead(analogPinX);
  dataStringX += String(sensorX);

  // save Y-axis data
  String dataStringY = "";
  int analogPinY = 6;
  int sensorY = analogRead(analogPinY);
  dataStringY += String(sensorY);

 

  // ************** FILE CREATION ***************************************
  dataFileX = SD.open("accel_x.txt", FILE_WRITE);
  dataFileY = SD.open("accel_y.txt", FILE_WRITE);
  // ************** FILE CREATION ***************************************


  // ********************** DATA LOGGING ********************************

  // print contents of string to file
  if (dataFileX){
    dataFileX.println(dataStringX);
    dataFileX.close();
    Serial.println(dataStringX);
  }  
  else {
    Serial.println("error opening file.txt");
  }
  

  if (dataFileY){
    dataFileY.println(dataStringY);
    dataFileY.close();
    Serial.println(dataStringY);
  }  
  else {
    Serial.println("error opening file.txt");
  }
  
  delay(2000);  
}
