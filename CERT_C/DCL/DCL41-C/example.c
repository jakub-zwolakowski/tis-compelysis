#include <stdio.h>

void f(int i) {}

void f_noncompliant(int expr) {
  switch (expr) {
    int i = 4;
    f(i);
  case 0:
    i = 17;
    /* Falls through into default code */
  default:
    printf("%d\n", i);
  }
}

int f_compliant(int expr) {
  /*
   * Move the code outside the switch block; now the statements
   * will get executed.
   */
  int i = 4;
  f(i);

  switch (expr) {
    case 0:
      i = 17;
      /* Falls through into default code */
    default:
      printf("%d\n", i);
  }
  return 0;
}

int main(void) {
  f_compliant(0);
  f_compliant(42);
  f_noncompliant(0);
  f_noncompliant(42);
  return 0;
}
