#include <limits.h>

void f_noncompliant(signed long s_a, signed long s_b) {
  signed long result;
  if ((s_a == LONG_MIN) && (s_b == -1)) {
    /* Handle error */
  } else {
    result = s_a / s_b;
  }
  /* ... */
}

void f_compliant(signed long s_a, signed long s_b) {
  signed long result;
  if ((s_b == 0) || ((s_a == LONG_MIN) && (s_b == -1))) {
    /* Handle error */
  } else {
    result = s_a / s_b;
  }
  /* ... */
}

int main(void) {
  f_compliant(42, 42);
  f_compliant(42, 1);
  f_compliant(42, 0);
  f_noncompliant(42, 42);
  f_noncompliant(42, 1);
  f_noncompliant(42, 0);
  return 0;
}
