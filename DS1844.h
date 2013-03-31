/*
  DS1844.h - Library for controlling a Maxim Integrated DS1844 Quad Digital Potentiometer
  Created by Matt Westwick; March 23, 2013
  Released into the public domain.
*/

#ifndef DS1844_h
#define DS1844_h
#include "Arduino.h"
#include <Wiring.h>

class DS1844
{
  int address;
  public:
    DS1844(int address);
    void write(int pot, int value);
    int read(int pot);
  //private:
    //int _address;
};

#endif
