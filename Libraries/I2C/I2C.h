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

#ifndef I2C_h
#define I2C_h

#include <WProgram.h>

class I2C {
public:
  I2C(void);
  void sendByte(int, byte);
  byte readByte(int);
  int readWord(int);
  int readWordWait(int);
  int readReverseWord(int);
  byte readWho(int);
  void updateRegister(int, byte, byte);
};

#endif