/**
 * IWKS 5120 Lab 1 Exercise 1
 * Transmits Morse code on an external LED for SOS followed by the coordinates of Denver, Colorado
 * 
 * created 26 Jan 2017
 * by John DiBaggio and Eric Holguin-Sanchez
 * 
 * modified 27 Jan 2017
 * by John DiBaggio
 * 
 * Timing:
 * Dot length               = 120 milliseconds
 * Dash length              = 3 x Dot length
 * Pause between elements   = Dot length
 * Pause between characters = 3 x Dot length
 * Pause between word       = 7 x Dot length
 */

const int LED_EXTERNAL =      10;
const int MORSE_UNIT =        120;
const int BLINK_DIT =         1 * MORSE_UNIT;
const int BLINK_DAH =         3 * MORSE_UNIT;
const int SPACE_INTERUNIT =   1 * MORSE_UNIT;
const int SPACE_INTERCHAR =   3 * MORSE_UNIT - SPACE_INTERUNIT; // character already ends with an inter-unit space, so deduct that
const int SPACE_INTERWORD =   7 * MORSE_UNIT - SPACE_INTERCHAR; // word already ends with an inter-character space, so deduct that
const int SPACE_FINAL =       2000;

int pin_number;

// the setup function runs once when you press reset or power the board
void setup() {  
  pin_number = LED_EXTERNAL;  // use LED_BUILTIN to use the built-in LED instead
  pinMode(pin_number, OUTPUT);
}

void finish_message() {
  delay(SPACE_FINAL);
}

void dit() {
  digitalWrite(pin_number, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(BLINK_DIT);
  digitalWrite(pin_number, LOW);  // turn the LED off (LOW is the voltage level)
  delay(SPACE_INTERUNIT);
}

void dah() {
  digitalWrite(pin_number, HIGH);
  delay(BLINK_DAH);
  digitalWrite(pin_number, LOW);
  delay(SPACE_INTERUNIT);
}

void write_char(char c) {
  switch(c) {
    case '0':
      dah(); dah(); dah(); dah(); dah();
      break;
    case '1':
      dit(); dah(); dah(); dah(); dah();
      break;
    case '2':
      dit(); dit(); dah(); dah(); dah();
      break;
    case '3':
      dit(); dit(); dit(); dah(); dah();
      break;
    case '4':
      dit(); dit(); dit(); dit(); dah();
      break;
    case '5':
      dit(); dit(); dit(); dit(); dit();
      break;
    case '6':
      dah(); dit(); dit(); dit(); dit();
      break;
    case '7':
      dah(); dah(); dit(); dit(); dit();
      break;
    case '8':
      dah(); dah(); dah(); dit(); dit();
      break;
    case '9':
      dah(); dah(); dah(); dah(); dit();
      break;  
    case 'A':
      dit(); dah();
      break;
    case 'B':
      dah(); dit(); dit(); dit();
      break;
    case 'C':
      dah(); dit(); dah(); dit();
      break;
    case 'D':
      dah(); dit(); dit();
      break;
    case 'E':
      dit();
      break;
    case 'F':
      dit(); dit(); dah(); dit();
      break;
    case 'G':
      dah(); dah(); dit();
      break;
    case 'H':
      dit(); dit(); dit(); dit();
      break;
    case 'I':
      dit(); dit();
      break;
    case 'J':
      dit(); dah(); dah(); dah();
      break;
    case 'K':
      dah(); dit(); dah();
      break;
    case 'L':
      dit(); dah(); dit(); dit();
      break;
    case 'M':
      dah(); dah();
      break;
    case 'N':
      dah(); dit();
      break;
    case 'O':
      dah(); dah(); dah();
      break;
    case 'P':
      dit(); dah(); dah(); dit();
      break;
    case 'Q':
      dah(); dah(); dit(); dah();
      break;
    case 'R':
      dit(); dah(); dit();
      break;
    case 'S':
      dit(); dit(); dit();
      break;
    case 'T':
      dah();
      break;
    case 'U':
      dit(); dit(); dah();
      break;
    case 'V':
      dit(); dit(); dit(); dah();
      break;
    case 'W':
      dit(); dah(); dah();
      break;
    case 'X':
      dah(); dit(); dit(); dah();
      break;
    case 'Y':
      dah(); dit(); dah(); dah();
      break;
    case 'Z':
      dah(); dah(); dit(); dit();
      break;
    case '.':
      dit(); dah(); dit(); dah(); dit(); dah();
      break;
    case ',':
      dah(); dah(); dit(); dit(); dah(); dah();
      break;
    case '?':
      dit(); dit(); dah(); dah(); dit(); dit();
      break;
    case ' ':
      delay(SPACE_INTERWORD);
      break;
    case '-':
      dah(); dit(); dit(); dit(); dit(); dah();
      break;    
    default:
      break;
  }
  
  delay(SPACE_INTERCHAR);
}

void doSOS() {
  const char sos_denver[] = "SOS 39.7392 N, 104.9903 W";

  for (int i = 0; i < strlen(sos_denver); i++) {
    write_char(sos_denver[i]);
  }

  finish_message(); // end message with a gap before another message is started
}

// the loop function runs over and over again forever
void loop() {  
  doSOS();

}
