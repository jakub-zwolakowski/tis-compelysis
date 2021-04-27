#include <limits.h>
#include <stddef.h>
#include <inttypes.h>
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

void f_noncompliant(unsigned int ui_a, unsigned int ui_b) {
  unsigned int uresult = ui_a << ui_b;
  /* ... */
}

void f_compliant(unsigned int ui_a, unsigned int ui_b) {
  unsigned int uresult = 0;
  if (ui_b >= PRECISION(UINT_MAX)) {
    /* Handle error */
  } else {
    uresult = ui_a << ui_b;
  }
  /* ... */
}

void main(void) {
  unsigned int a, b;
  a = 42;
  b = 42;
  f_compliant(a, b);
  f_noncompliant(a, b);
}
