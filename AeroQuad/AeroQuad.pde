/*
  AeroQuad v3.0 - February 2011
  www.AeroQuad.com
  Copyright (c) 2011 Ted Carancho.  All rights reserved.
  An Open Source Arduino based multicopter.
 
  This program is free software: you can redistribute it and/or modify 
  it under the terms of the GNU General Public License as published by 
  the Free Software Foundation, either version 3 of the License, or 
  (at your option) any later version. 

  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  GNU General Public License for more details. 

  You should have received a copy of the GNU General Public License 
  along with this program. If not, see <http://www.gnu.org/licenses/>. 
*/

#include "Configuration.h"
#include <Wire.h>
#include <I2C.h>          // I2C Utility Functions
#include <Accel.h>        // Accelerometer Sensor
#include <Gyro.h>         // Gyro Sensor
//#include <Compass.h>      // Compass Sensor
//#include <Altitude.h>     // Altitude Sensor
//#include <Filter.h>       // Low Pass Filters
//#include <Kinematics.h>   // Kinematics
//#include <Motors.h>       // Motor Control
//#include <Control.h>      // Control Law (PID, Fuzzy Logic, etc)
//#include <Receiver.h>     // Receive External Commands

#if defined(APM)
  #include <APM_ADC.h>
#elif defined(WII)
  #include <Wii.h>
#endif

// Common declaration of all objects from parent class
// Forces all future objects to conform to parent class
Accel *accel = &tempAccel;
Gyro  *gyro  = &tempGyro;

void setup() {
  Serial.begin(115200);
  accel->initialize();
  gyro->initialize();
  
  accel->calibrate();
  gyro->calibrate();
}

void loop() {
  accel->measure();
  gyro->measure();
  delay(500);
}
  
