#include <limits.h>
#include <stddef.h>
#include <stdint.h>

/* Returns the number of set bits */
size_t popcount(uintmax_t num) {
  size_t precision = 0;
  while (num != 0) {
    if (num % 2 == 1) {
      precision++;
    }
    num >>= 1;
  }
  return precision;
}
#define PRECISION(umax_value) popcount(umax_value)

unsigned int pow2_noncompliant(unsigned int exp) {
  if (exp >= sizeof(unsigned int) * CHAR_BIT) {
    /* Handle error */
    return 0;
  }
  return ((unsigned int) 1) << exp;
}

unsigned int pow2_compliant(unsigned int exp) {
  if (exp >= PRECISION(UINT_MAX)) {
    /* Handle error */
    return 0;
  }
  return ((unsigned int) 1) << exp;
}

int main(void) {
  pow2_compliant(1);
  pow2_compliant(31);
  pow2_compliant(32);
  pow2_noncompliant(1);
  pow2_noncompliant(31);
  pow2_noncompliant(32);
  return 0;
}
