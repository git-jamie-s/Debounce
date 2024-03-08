### Debounce
This library lets you read debounced digital input pins similar to reading a raw digital pin.

IE., 
Instead of calling:
```
int value = digitalRead(int pin);
```

you would call:
```
int value = debouncedDigitalRead(int pin);
```

#### Configuration
To use the library, you must first tell it what pins you want to use!
Debounce will allocate 4 bytes per pin.

To initialize, call:
```
int debouncePins(int lowestPin, int highestPin, int debounceTimeout);
```
The default for debounceTimeout is 50ms.

For example, if you wanted to debounce pins 5, 7, and 12, with the default
timeout of 50ms, you would call:
```
debounce(5, 12);
```

If you only wanted to debounce a single pin (pin 6), you would call:
```
debounce(6, 6);
```

#### Use
Once the library is configured, go ahead and call `int debouncedDigitalRead(int pin)` just as you would call `int digitalRead(int pin)`:

#### Example
```
#include <Arduino.h>
#include <Debounce.h>

int const BUTTON_1=5;
int const BUTTON_2=6;
int const BUTTON_3=7;

void setup() {
  debouncePins(BUTTON_1, BUTTON_3);
}

void loop() {
  int value1 = debouncedDigitalRead(BUTTON_1);
  // use value1 for something...
  
  int value2 = debouncedDigitalRead(BUTTON_2);
  // etc...
}
```


### Production Mode
By default, the Debounce code provides some safety checks to make sure you aren't
calling `debouncedDigitalRead()` on some pin that hasn't been configured.

However, if you are sure that your code has configured the library correctly, you can then configure it to skip the tests, speeding up the code.  To do so, set `UNSAFE_DEBOUNCE` before including the header:

```
#define UNSAFE_DEBOUNCE
#include <Debounce.h>
```