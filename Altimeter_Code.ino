/*
 MPL3115A2 Barometric Pressure Sensor Library Example Code
 By: Nathan Seidle
 SparkFun Electronics
 Date: September 24th, 2013
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
*/

#include <Wire.h>
#include "SparkFunMPL3115A2.h"

MPL3115A2 myPressure;

void setup()
{
  Wire.begin();        
  Serial.begin(9600);  
  myPressure.begin(); 

  myPressure.setModeAltimeter(); 
  
  myPressure.setOversampleRate(7); 
  myPressure.enableEventFlags(); 
}

void loop()
{
  float altitude = myPressure.readAltitude();
  Serial.print("Altitude(m):");
  Serial.print(altitude, 2);

  Serial.println();
}
