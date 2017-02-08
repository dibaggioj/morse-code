# Lab 1: Arduino 1 - Morse Code on the Arduino
## IWKS 5120 The Internet of Things
### John DiBaggio

### Included:
- Morse class: Morse
    - Morse.h declares the Morse interface. It includes all of the constants related to timing of Morse code.
    - Morse.cpp implements the Morse interface. 
    - The Morse class first sets up the Morse code alphabet and English alphabet (arrays). It includes the logic for finding the binary literal representation of an English character and turning on and off the power to the pin connected to a light based on the value of each bit in the binary representation. It includes the translation of input into a photoresistor to English characters and printing of those characters.
- Arduino example of Morse code sending Arduino sketch (refactored): morse_code_sender
- Arduino exaple of Morse code receiving Arduino sketch: morse_code_receiver

