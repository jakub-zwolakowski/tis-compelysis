#include <limits.h>

void f_noncompliant(void) {
  unsigned long int u_a = ULONG_MAX;
  signed char sc;
  sc = (signed char)u_a; /* Cast eliminates warning */
  /* ... */
}

void f_compliant(void) {
  unsigned long int u_a = ULONG_MAX;
  signed char sc;
  if (u_a <= SCHAR_MAX) {
    sc = (signed char)u_a;  /* Cast eliminates warning */
  } else {
    /* Handle error */
  }
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
