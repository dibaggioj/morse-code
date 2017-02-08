/**
 * IWKS 5120 Lab 1 Exercise 1 - Refactored
 * Transmits Morse code on an external LED for SOS followed by the coordinates of Denver, Colorado
 * 
 * created 27 Jan 2017
 * by John DiBaggio
 * 
 */

#include <Morse.h>

const int PHOTORESISTOR = 0;

int pin_number;
Morse* morse;

void doSOS() {
  const char sos_denver[] = "SOS 39.7392 N, 104.9903 W";

  morse->writeMessage(sos_denver);
}

void setup() {
  Serial.begin(9600);
  pin_number = PHOTORESISTOR;
  pinMode(pin_number, INPUT);
  morse = new Morse(pin_number);
  Serial.println("Awaiting Morse code transmission...\n");
}

void loop() {
  morse->read();  
}

