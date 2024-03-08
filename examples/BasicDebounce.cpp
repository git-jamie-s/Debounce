/**
 * For this exaggerated example, we will debounce for
 * a full second so that you can visibly see the LED being debounced.
 * 
 * If you short PIN_A(5) to ground, the LED will light up for minimum 1 second.
 * 
*/
#include <Arduino.h>

/**
 *  See note about UNSAFE_DEBOUNCE in Debounce.h
*/
// #define UNSAFE_DEBOUNCE
#include <Debounce.h>

int const DEBOUNCE_TIME = 1000;

// Define some input pins to debounce
#define PIN_A 5
#define PIN_B 6
#define PIN_C 7

void setup()
{
    Serial.begin(115200);

    // Set the mode of the LED and pins
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PIN_A, INPUT_PULLUP);
    pinMode(PIN_B, INPUT_PULLUP);
    pinMode(PIN_C, INPUT_PULLUP);

    // Configure the Debounce library to support pins 5 to 7, 
    // and debounce for 1000 ms.
    debouncePins(PIN_A, PIN_C, DEBOUNCE_TIME);
}

void loop()
{
    int valueA = !debouncedDigitalRead(PIN_A);
    digitalWrite(LED_BUILTIN, valueA);

    // Do stuff with the other debounced inputs
    // int valueB =  !debouncedDigitalRead(PIN_B);
    // int valueC =  !debouncedDigitalRead(PIN_C);
}
