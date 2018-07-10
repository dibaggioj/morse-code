/**
 * Morse.cpp
 *
 * Created by John DiBaggio on 1/28/17.
 *
 */

#include <math.h>

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
    #include "pins_arduino.h"
    #include "WConstants.h"
#endif

#include "Morse.h"

Morse::Morse(int pin_number) {
    pin = pin_number;

    reset();

    setupAlphabet();
}

void Morse::setupAlphabet() {
    alphabet_morse[MORSE_0] =        0b000011101110111011101110;
    alphabet_morse[MORSE_1] =        0b000000101110111011101110;
    alphabet_morse[MORSE_2] =        0b1010111011101110;
    alphabet_morse[MORSE_3] =        0b0010101011101110;
    alphabet_morse[MORSE_4] =        0b0000101010101110;
    alphabet_morse[MORSE_5] =        0b0000001010101010;
    alphabet_morse[MORSE_6] =        0b0000111010101010;
    alphabet_morse[MORSE_7] =        0b0011101110101010;
    alphabet_morse[MORSE_8] =        0b1110111011101010;
    alphabet_morse[MORSE_9] =        0b000000111011101110111010;
    alphabet_morse[MORSE_A] =        0b00101110;
    alphabet_morse[MORSE_B] =        0b0000001110101010;
    alphabet_morse[MORSE_C] =        0b0000111010111010;
    alphabet_morse[MORSE_D] =        0b11101010;
    alphabet_morse[MORSE_E] =        0b00000010;
    alphabet_morse[MORSE_F] =        0b0000001010111010;
    alphabet_morse[MORSE_G] =        0b0000001110111010;
    alphabet_morse[MORSE_H] =        0b10101010;
    alphabet_morse[MORSE_I] =        0b00001010;
    alphabet_morse[MORSE_J] =        0b0010111011101110;
    alphabet_morse[MORSE_K] =        0b0000001110101110;
    alphabet_morse[MORSE_L] =        0b0000001011101010;
    alphabet_morse[MORSE_M] =        0b11101110;
    alphabet_morse[MORSE_N] =        0b00111010;
    alphabet_morse[MORSE_O] =        0b0000111011101110;
    alphabet_morse[MORSE_P] =        0b0000101110111010;
    alphabet_morse[MORSE_Q] =        0b0011101110101110;
    alphabet_morse[MORSE_R] =        0b10111010;
    alphabet_morse[MORSE_S] =        0b00101010;
    alphabet_morse[MORSE_T] =        0b00001110;
    alphabet_morse[MORSE_U] =        0b10101110;
    alphabet_morse[MORSE_V] =        0b0000001010101110;
    alphabet_morse[MORSE_W] =        0b0000001011101110;
    alphabet_morse[MORSE_X] =        0b0000111010101110;
    alphabet_morse[MORSE_Y] =        0b0011101011101110;
    alphabet_morse[MORSE_Z] =        0b0000111011101010;
    alphabet_morse[MORSE_PERIOD] =   0b000000101110101110101110;
    alphabet_morse[MORSE_COMMA] =    0b000011101110101011101110;
    alphabet_morse[MORSE_QUESTION] = 0b1010111011101010;
    alphabet_morse[MORSE_HYPHEN] =   0b1110101010101110;
    alphabet_morse[MORSE_SPACE] =    0b00000000;

    alphabet_english[MORSE_0] =        '0';
    alphabet_english[MORSE_1] =        '1';
    alphabet_english[MORSE_2] =        '2';
    alphabet_english[MORSE_3] =        '3';
    alphabet_english[MORSE_4] =        '4';
    alphabet_english[MORSE_5] =        '5';
    alphabet_english[MORSE_6] =        '6';
    alphabet_english[MORSE_7] =        '7';
    alphabet_english[MORSE_8] =        '8';
    alphabet_english[MORSE_9] =        '9';
    alphabet_english[MORSE_A] =        'A';
    alphabet_english[MORSE_B] =        'B';
    alphabet_english[MORSE_C] =        'C';
    alphabet_english[MORSE_D] =        'D';
    alphabet_english[MORSE_E] =        'E';
    alphabet_english[MORSE_F] =        'F';
    alphabet_english[MORSE_G] =        'G';
    alphabet_english[MORSE_H] =        'H';
    alphabet_english[MORSE_I] =        'I';
    alphabet_english[MORSE_J] =        'J';
    alphabet_english[MORSE_K] =        'K';
    alphabet_english[MORSE_L] =        'L';
    alphabet_english[MORSE_M] =        'M';
    alphabet_english[MORSE_N] =        'N';
    alphabet_english[MORSE_O] =        'O';
    alphabet_english[MORSE_P] =        'P';
    alphabet_english[MORSE_Q] =        'Q';
    alphabet_english[MORSE_R] =        'R';
    alphabet_english[MORSE_S] =        'S';
    alphabet_english[MORSE_T] =        'T';
    alphabet_english[MORSE_U] =        'U';
    alphabet_english[MORSE_V] =        'V';
    alphabet_english[MORSE_W] =        'W';
    alphabet_english[MORSE_X] =        'X';
    alphabet_english[MORSE_Y] =        'Y';
    alphabet_english[MORSE_Z] =        'Z';
    alphabet_english[MORSE_PERIOD] =   '.';
    alphabet_english[MORSE_COMMA] =    ',';
    alphabet_english[MORSE_QUESTION] = '?';
    alphabet_english[MORSE_HYPHEN] =   '-';
    alphabet_english[MORSE_SPACE] =    ' ';
}

void Morse::on() {
    digitalWrite(pin, HIGH);
}

void Morse::off() {
    digitalWrite(pin, LOW);
}

void Morse::finishMessage() {
    delay(SPACE_FINAL);
}

void Morse::reset() {
	start_time = 0;
	stop_time = 0;
	current_unit_index = 0;
	current_char = ' ';
	current_char_binary = 0b000000000000000000000000;
	mask = 0b100000000000000000000000;
}

void Morse::writeMessage(char *message) {
    char * c;
    for (c = message; *c != '\0'; ++c) {
        writeChar(*c);
    }
    
    finishMessage();
}

void Morse::writeSingleCharMessage(char message) {
    writeChar(message);
    
    finishMessage();
}

void Morse::checkForValidChar() {
	int i = getMorseIndex(current_char_binary);
	if (i > -1) {
		current_char = alphabet_english[i];
		Serial.print(current_char);
		reset();
	}
}

const int Morse::getEnglishIndex(const char c) {
	for (int i = 0; i < SIZE_ALPHABET; ++i) {
		if (alphabet_english[i] == c) {
			return i;
		}
	}
	return -1;
}

const int Morse::getMorseIndex(const unsigned long c) {
	for (int i = 0; i < SIZE_ALPHABET; ++i) {
		if (alphabet_morse[i] == c) {
			return i;
		}
	}
	return -1;
}

void Morse::read() {
    int sensor_value = analogRead(pin);

    if (is_on) {
        if (sensor_value <= BASE_PHOTORESISTOR) {	// interunit space
            is_on = false;
            stop_time = millis();
            unsigned long interval = stop_time - start_time;
            start_time = millis();
            int bits = round(interval / MORSE_UNIT);

            if (bits > 1) { 						// more than one interunit space, so must have finished transmitting an entire character
				bits = 1;
            	checkForValidChar();
			} else {
				for (int i; i < bits; ++i) {
					++current_unit_index;
					if (current_unit_index < MAX_UNITS_LENGTH - 1) {
						current_char_binary |= mask;
						mask >>= 1;
					} else {
						Serial.print("\nError receiving transmission. Resetting...\n");
						reset();
					}
				}
			}
        }
    } else {
        if (sensor_value > BASE_PHOTORESISTOR) {	// a character unit has started being transmitted
            is_on = true;
            if (start_time == 0) {  				// started for the first time
                start_time = millis();
                current_unit_index = 0;
            } else {                				// end of an interunit space
                stop_time = millis();
                unsigned long interval = stop_time - start_time;
                start_time = millis();
                int bits = round(interval / MORSE_UNIT);

                if (bits > 3) { 					// more than one intercharacter space, so must have transmitted an interword space
					checkForValidChar();
				} else {
					for (int i; i < bits; ++i) {
						++current_unit_index;
						if (current_unit_index < MAX_UNITS_LENGTH - 1) {
							mask >>= 1;
						} else {
							Serial.print("\nError receiving transmission. Resetting...\n");
							reset();
						}
					}
				}
            }
        }
    }
}

void Morse::writeChar(const char c) {
    bool leading_zeros_removed = false;
    unsigned long mask = 0b100000000000000000000000;
    
    int i = getEnglishIndex(c);
    if (i == -1) {
    	Serial.print("Invalid character: " + c + '\n');
    	i = 0;
    }

    unsigned long morse_char_number = alphabet_morse[i];
    if (morse_char_number == 0) {
        delay(SPACE_INTERWORD);
    } else {
        // iterate through bit mask until first nonzero bit is encountered
        while (!leading_zeros_removed) {
            mask >>= 1;
            leading_zeros_removed = morse_char_number & mask;
        }
        
        // iterate through bit mask after leading zeros have been ignored
        for (; mask != 0; mask >>= 1) {
            if (morse_char_number & mask) { // 1
                on();
            } else { // 0
                off();
            }
            
            delay(SPACE_INTERUNIT);
        }
        
        off();
        
        delay(SPACE_INTERCHAR_REMAINING);
    }
}

