#include <limits.h>

void f_noncompliant(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum = ui_a + ui_b;
  /* ... */
}

void f_compliant(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    /* Handle error */
  } else {
    usum = ui_a + ui_b;
  }
  /* ... */
}

int main(void) {
  unsigned int a, b, c;
  a = UINT_MAX;
  b = 42;
  f_compliant(a, b);
  f_noncompliant(a, b);
  return 0;
}
