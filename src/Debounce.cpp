#include <Arduino.h>
#include "Debounce.h"

typedef struct {
    unsigned int value:1;
    unsigned long timestamp:31;
} PinInfo_t;

PinInfo_t *debouncedPin = NULL;
int debouncedPinLow;
int debouncedPinHigh;
int debounceTime;

void debouncePins(int low, int high, int ms)
{
    int count = high - low + 1;
    debouncedPin = (PinInfo_t *)malloc(count * sizeof(PinInfo_t));
    debouncedPinLow = low;
    debouncedPinHigh = high;
    debounceTime = ms;
}

int unsafeDebouncedDigitalRead(int pin)
{
    PinInfo_t & pinInfo = debouncedPin[pin - debouncedPinLow];
    int input = digitalRead(pin);
    int saved = pinInfo.value;
    if (saved != input)
    {
        unsigned long now = millis();
        if (now - pinInfo.timestamp > debounceTime)
        {
            pinInfo.timestamp = now;
            pinInfo.value = input;
        }
    }
    return pinInfo.value;
}

int debouncedDigitalRead(int pin)
{
    if (debouncedPin == NULL) {
        Serial.print("Debounce Pin not correctly configured!\n");
        Serial.print("Be sure to call 'debouncePins' before using.\n");
        delay(10000);
        return 0;
    }
    if (pin < debouncedPinLow || pin > debouncedPinHigh) {
        Serial.print("Debounce Pin not correctly configured!\n");
        Serial.print("Pin ");
        Serial.print(pin);
        Serial.print(" is outside configured range ");
        Serial.print(debouncedPinLow);
        Serial.print(" to ");
        Serial.println(debouncedPinHigh);

        delay(10000);
        return 0;
    }
    return unsafeDebouncedDigitalRead(pin);
}
