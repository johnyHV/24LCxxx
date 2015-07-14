/* 
 * File:   24LCxxx.h
 * Author: Miroslav Pivovarsky
 *
 * Created on June 16, 2015, 10:39 PM

  E24LCxxx.h - An Arduino library for EEPROM 24LCxxx.
  
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

#ifndef _E_24LCXXX_H_
#define	_E_24LCXXX_H_

#include <Wire.h>
#include <Arduino.h>

class E24LCxxx {
private:
    int device_address;
    
public:
    void init(int add);  // initial memory via constructor or method init
    void Write(unsigned int data_address, byte data); // write data
    byte Read(unsigned int data_address); // read data
    
    E24LCxxx() {};  // constructor
    E24LCxxx(int add);  // constructor with EEPROM address 
    ~E24LCxxx() {};     // destructor
    
};

#endif	/* 24LCXXX_H */

