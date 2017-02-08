/**
 * Morse.h
 *
 * Created by John DiBaggio on 1/28/17.
 * 
 * Timing:
 * Dot length               = 120 milliseconds
 * Dash length              = 3 x Dot length
 * Pause between elements   = Dot length
 * Pause between characters = 3 x Dot length
 * Pause between word       = 7 x Dot length
 *
 */

#ifndef Morse_h
#define Morse_h

#define MORSE_0        0
#define MORSE_1        1
#define MORSE_2        2
#define MORSE_3        3
#define MORSE_4        4
#define MORSE_5        5
#define MORSE_6        6
#define MORSE_7        7
#define MORSE_8        8
#define MORSE_9        9
#define MORSE_A        10
#define MORSE_B        11
#define MORSE_C        12
#define MORSE_D        13
#define MORSE_E        14
#define MORSE_F        15
#define MORSE_G        16
#define MORSE_H        17
#define MORSE_I        18
#define MORSE_J        19
#define MORSE_K        20
#define MORSE_L        21
#define MORSE_M        22
#define MORSE_N        23
#define MORSE_O        24
#define MORSE_P        25
#define MORSE_Q        26
#define MORSE_R        27
#define MORSE_S        28
#define MORSE_T        29
#define MORSE_U        30
#define MORSE_V        31
#define MORSE_W        32
#define MORSE_X        33
#define MORSE_Y        34
#define MORSE_Z        35
#define MORSE_PERIOD   36
#define MORSE_COMMA    37
#define MORSE_QUESTION 38
#define MORSE_HYPHEN   39
#define MORSE_SPACE    40

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
    #include "pins_arduino.h"
    #include "WConstants.h"
#endif

class Morse {
public:
    
    Morse(int pin_number);
    
    void writeMessage(char *message);
    
    void writeSingleCharMessage(char message);
    
    void read();
    
private:
    
    const static byte SIZE_ALPHABET =    41;
    const static int MORSE_UNIT =        120;
    const static int LENGTH_DOT =        1 * MORSE_UNIT;
    const static int BLINK_DAH =         3 * MORSE_UNIT;
    const static int SPACE_INTERUNIT =   1 * MORSE_UNIT;
    const static int SPACE_INTERCHAR =   3 * MORSE_UNIT;
    const static int SPACE_INTERWORD =   7 * MORSE_UNIT;
    const static int SPACE_INTERCHAR_REMAINING =   SPACE_INTERCHAR - SPACE_INTERUNIT; // character already ends with an inter-unit space, so deduct that
    const static int SPACE_FINAL =       2000;
    const static int MAX_UNITS_LENGTH =   24;
    const static int BASE_PHOTORESISTOR = 300; // TODO: adjust as necessary

    int pin;
    unsigned int current_unit_index;
    unsigned long start_time;
    unsigned long stop_time;
    unsigned long mask;
    unsigned long current_char_binary;
    bool is_on;
    char current_char;
    char alphabet_english[SIZE_ALPHABET];
    unsigned long alphabet_morse[SIZE_ALPHABET];
    
    void setupAlphabet();
    
    void on();
    
    void off();
    
    void finishMessage();
    
    void reset();

    void writeChar(const char c);
    
    void checkForValidChar();

    const int getEnglishIndex(const char c);

    const int getMorseIndex(const unsigned long c);

};

#endif
