#include <stdio.h>

void f_noncompliant(void) {
  for (float x = 100000001.0f; x <= 100000010.0f; x += 1.0f) {
    printf("f_noncompliant, x = %f\n", x);
    /* Loop may not terminate */
  }
}

void f_compliant(void) {
  for (size_t count = 1; count <= 10; ++count) {
    float x = 100000000.0f + (count * 1.0f);
    printf("f_compliant, x = %f\n", x);
    /* Loop iterates exactly 10 times */
  }
}

void main(void) {
  f_compliant();
  f_noncompliant(); // This is not terminating!
}
