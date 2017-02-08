# Lab 1: Arduino 1 - Morse Code on the Arduino
## IWKS 5120 The Internet of Things
### John DiBaggio

#### Initial Morse code sending code written by John DiBaggio and Eric Holguin-Sanchez
#### Updated Morse code sending written by John DiBaggio

After initially building the Morse code sender in class, I wasn't happy with the long switch statement and thought that Morse code could be better represented as binary literals instead of separate function calls. When thinking about how to build a Morse code receiver, it seemed that this new representation might be easily reused when translating the signals. 

TODO: Test the Morse code receiving

### Included:
- Morse class: Morse
    - Morse.h declares the Morse interface. It includes all of the constants related to timing of Morse code.
    - Morse.cpp implements the Morse interface. 
    - The Morse class first sets up the Morse code alphabet and English alphabet (arrays). It includes the logic for finding the binary literal representation of an English character and turning on and off the power to the pin connected to a light based on the value of each bit in the binary representation. It includes the translation of input into a photoresistor to English characters and printing of those characters.
- Version 1 of Morse code sending Arduino sketch: morse_code_sender_1
    - Uses large switch statement for the Morse code alphabet.
- Version 2 of Morse code sending Arduino sketch (refactored): morse_code_sender_2
- Morse code receiving Arduino sketch: morse_code_receiver

