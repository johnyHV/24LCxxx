  /*
  E24LCxxx.cpp - An Arduino library for EEPROM 24LCxxx.

  Copyright (C) 2015 M. Pivovarsky <miroslav.pivovarsky@gmail.com>
  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 */

#include "E24LCxxx.h"

/**
 *
 * @info Initial EEPROM. Support all 24LCxxx memory
 * @param address EEPROM memory
 * @return void
 */
E24LCxxx::E24LCxxx(int add) {
    Wire.begin();
    device_address = add;
}

/**
 *
 * @info Initial EEPROM memory. Support all 24LCxxx memory. For external initial.
 * @param address EEPROM memory
 * @return void
 */
void E24LCxxx::init(int add){
    Wire.begin();
    device_address = add;
}

/**
 *
 * @info Write to EEPROM
 * @param EEPROM data cell
 * @param data for write
 * @return void
 */
void E24LCxxx::Write(unsigned int data_address, byte data) {
    Wire.beginTransmission(device_address);
    Wire.write((int) (data_address >> 8)); 
    Wire.write((int) (data_address & 0xFF)); 
    Wire.write(data);
    Wire.endTransmission();
    delay(10);
}

/**
 *
 * @info Read from EEPROM memory
 * @param address data cell in EEPROM memory
 * @return void
 */
byte E24LCxxx::Read(unsigned int data_address) {
    byte result; 
    Wire.beginTransmission(device_address); 
    Wire.write((int) (data_address >> 8)); 
    Wire.write((int) (data_address & 0xFF)); 
    Wire.endTransmission();
    Wire.requestFrom(device_address, 1); 
    return Wire.read(); 
}

