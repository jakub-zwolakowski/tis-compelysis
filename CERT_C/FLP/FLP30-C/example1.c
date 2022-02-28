#include <stdio.h>

void f_noncompliant(void) {
  float old_x = -1;
  for (float x = 100000001.0f; x <= 100000010.0f; x += 1.0f) {
    /* Loop may not terminate */
    if (x != old_x) {
      /* This conditional was added in order to avoid creating enormous output files. */
      printf("f_noncompliant, x = %f\n", x);
      old_x = x;
    }
  }
}

void f_compliant(void) {
  for (size_t count = 1; count <= 10; ++count) {
    float x = 100000000.0f + (count * 1.0f);
    printf("f_compliant, x = %f\n", x);
    /* Loop iterates exactly 10 times */
  }
}

int main(void) {
  f_compliant();
  f_noncompliant(); // This is not terminating!
  return 0;
}
