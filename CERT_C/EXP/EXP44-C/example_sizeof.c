#include <stdio.h>

void f_noncompliant(void) {
  int a = 14;
  int b = sizeof(a++);
  printf("%d, %d\n", a, b);
}

void f_compliant(void) {
  int a = 14;
  int b = sizeof(a);
  ++a;
  printf("%d, %d\n", a, b);
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
