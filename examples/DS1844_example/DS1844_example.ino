/*
  DS1844.h - Library for controlling a Maxim Integrated DS1844 Quad Digital Potentiometer
  Created by Matt Westwick; March 23, 2013
  Released into the public domain.
  
  This example demonstrates how to use the Maxim DS1844 and the DS1844 library
  to fade 4 LEDs. The setup is as follows:
  
  DS1844 pins 1, 2, 3, 18, 19, and 20 connect to Arduino +5v
  DS1844 pins 5, 6, 8, 9, 10, 11, 15, 16 connect to Arduino GND
  DS1844 pin 4 -> [+LED1-] -> [100ohm Resistor] -> [Arduino GND]
  DS1844 pin 7 -> [+LED2-] -> [100ohm Resistor] -> [Arduino GND]
  DS1844 pin 14 -> [+LED3-] -> [100ohm Resistor] -> [Arduino GND]
  DS1844 pin 17 -> [+LED4-] -> [100ohm Resistor] -> [Arduino GND]
  DS1844 pin 12 -> Arduino SDA (on UNO this is Analog4)
  DS1844 pin 13 -> Arduino SCL (on UNO this is Analog5)
  
  A video of the circuit in action can be found online at [INSERT SITE HERE]
  
*/


#include <DS1844.h>
#include <Wire.h>

int brightness[4];         //This creates a 4 element array for the brightness values of the 4 LEDS
int readout;               //This is the DS1844's returned value
const int address = 0x28;  //This is the address of the DS1844 chip with all three address pins grounded.

/*
Addresses for common configurations of address pins:
A0, A1, A2 low -> 0101000 -> 0x28
A0 high; A1, A2 low -> 0101001 -> 0x29
A0, A1 high; A2 low -> 0101011 -> 0x2B
A0, A1, A2 high -> 0101111 -> 0x2F
*/

//Create an instance of the DS1844 class
DS1844 ds1844(address);

void setup() {
  //Start serial communication
  Serial.begin(9600);
}

void loop() {
  
  //Increment through the potentiometers
  for (int i = 0; i <= 3; i++) {
                                        //NOTE: DS1844 RANGE IS 0-63 (6 bit integer) 
    while (brightness[i] <63) {
      brightness[i]++;                  //Increment brightness
      ds1844.write(i, brightness[i]);   //Write the brightness to the selected potentiometer
      readout = ds1844.read(i);         //Display the newly written value to the serial monitor
      Serial.println(readout);
      delay(50);
    }
  }
  
  //Wait a second
  delay(1000);
  
  //Turn all pots back to zero
  for (int i = 0; i <= 3; i++) {
      ds1844.write(i, 0);
      brightness[i] = 0;
  }
}
