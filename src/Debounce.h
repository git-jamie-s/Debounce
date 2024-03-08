#ifndef __DEBOUNCE_H__
#define __DEBOUNCE_H__


/**
 * debouncePins
 * Configure the library to support debouncing of the specifed pin range.
 * Call this just once before using debouncedDigitalRead().
 * inputs:
 * low: The lowest pin number that you want to debounce
 * high: The highest pin number that you want to debounce.
 * ms: The number of milliseconds to debounce over (50 is a good choice).
 * 
 * (This allocates 4 bytes per pin.)
*/
void debouncePins(int low, int high, int ms=50);

/**
 * To use this library, use `debouncedDigitalRead(pin)` in your code.
 * When you are confident that you have correctly configured the library
 * using `debouncePins`, you may then predefine #define UNSAFE_DEBOUNCE
 * to make your code faster and leaner.
*/
#ifdef UNSAFE_DEBOUNCE
#define debouncedDigitalRead unsafeDebouncedDigitalRead
#endif

int unsafeDebouncedDigitalRead(int pin);
int debouncedDigitalRead(int pin);

#endif
