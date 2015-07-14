#include <Wire.h>
#include "E24LCxxx.h"

E24LCxxx EEPROM(0x51);


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("MCU start");

  // write and read char
  EEPROM.Write(0,'a');
  char c = EEPROM.Read(0);
  Serial.println(c);
  Serial.println((char)EEPROM.Read(0));

  //write and read int
  EEPROM.Write(1,10);
  Serial.println(EEPROM.Read(1));
}


void loop() {
}

