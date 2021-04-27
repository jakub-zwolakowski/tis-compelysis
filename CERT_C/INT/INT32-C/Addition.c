#include <limits.h>

void f_noncompliant(signed int si_a, signed int si_b) {
  signed int sum = si_a + si_b;
  /* ... */
}

void f_compliant(signed int si_a, signed int si_b) {
  signed int sum;
  if (((si_b > 0) && (si_a > (INT_MAX - si_b))) ||
      ((si_b < 0) && (si_a < (INT_MIN - si_b)))) {
    /* Handle error */
  } else {
    sum = si_a + si_b;
  }
  /* ... */
}

void main(void) {
  f_compliant(INT_MAX, 1);
  f_noncompliant(INT_MAX, 1);
}
