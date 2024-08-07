#include <inttypes.h>
#include <stddef.h>

void digitize(uint64_t n, uint8_t digits[], size_t *length_out) {
  int i = 0;

  do {
    digits[i] = n % 10; // use mod 10 to get last digit
    n /= 10;            // use int division by 10 to remove last digit
    i++;                // count number of digits
  } while (n); // stop loop when n == 0

  *length_out = i; // report the number of digits
}
