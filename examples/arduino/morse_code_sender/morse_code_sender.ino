/**
 * IWKS 5120 Lab 1 Exercise 1 - Refactored
 * Transmits Morse code on an external LED for SOS followed by the coordinates of Denver, Colorado
 * 
 * created 27 Jan 2017
 * by John DiBaggio
 * 
 */

#include <Morse.h>

const int LED_EXTERNAL = 10;

int pin_number;
Morse* morse;

void doSOS() {
  const char sos_denver[] = "SOS 39.7392 N, 104.9903 W";

  morse->writeMessage(sos_denver);
}

void setup() {
  pin_number = LED_EXTERNAL; // use LED_BUILTIN instead of LED_EXTERNAL to use the built-in LED
  pinMode(pin_number, OUTPUT);
  morse = new Morse(pin_number);
}

void loop() {  
  doSOS();

}

