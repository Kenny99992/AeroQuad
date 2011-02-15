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

#ifndef Gyro_h
#define Gyro_h

#include <WProgram.h>

class Gyro {
public:
  #define XAXIS 0
  #define YAXIS 1
  #define YAWAXIS 2
  #define LASTAXIS 3
  int data[3];
  int zero[3];
  
  virtual void initialize(void);
  virtual void measure(void);
  virtual void calibrate(void);
  const int getData(byte);
  const int getZero(byte);
  void setZero(byte, int);
};

#endif