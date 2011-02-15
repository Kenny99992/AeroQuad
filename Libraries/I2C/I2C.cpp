/*
  AeroQuad v2.1 - January 2011
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

#include "I2C.h"
#include <Wire.h>


I2C::I2C(void) { }

void I2C::sendByte(int deviceAddress, byte dataValue) {
  Wire.beginTransmission(deviceAddress);
  Wire.send(dataValue);
  Wire.endTransmission();
}

byte I2C::readByte(int deviceAddress) {
  Wire.requestFrom(deviceAddress, 1);
  return Wire.receive();
}

int I2C::readWord(int deviceAddress) {
  Wire.requestFrom(deviceAddress, 2);
  return (Wire.receive() << 8) | Wire.receive();
}

int I2C::readWordWait(int deviceAddress) {
  unsigned char msb, lsb;
  Wire.requestFrom(deviceAddress, 2); // request two bytes
  while(!Wire.available()); // wait until data available
  msb = Wire.receive();
  while(!Wire.available()); // wait until data available
  lsb = Wire.receive();
  return (((int)msb<<8) | ((int)lsb));
}

int I2C::readReverseWord(int deviceAddress) {
  byte lowerByte;
  Wire.requestFrom(deviceAddress, 2);
  lowerByte = Wire.receive();
  return (Wire.receive() << 8) | lowerByte;
}

byte I2C::readWho(int deviceAddress) {
  // read the ID of the I2C device
  Wire.beginTransmission(deviceAddress);
  Wire.send(0x00);
  Wire.endTransmission();
  delay(100);
  Wire.requestFrom(deviceAddress, 1);
  return Wire.receive();
}

void I2C::updateRegister(int deviceAddress, byte dataAddress, byte dataValue) {
  Wire.beginTransmission(deviceAddress);
  Wire.send(dataAddress);
  Wire.send(dataValue);
  Wire.endTransmission();
}  