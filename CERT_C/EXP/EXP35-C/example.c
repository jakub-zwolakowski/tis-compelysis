#include <stdio.h>

struct X { int a[6]; };

struct X addressee(void) {
  struct X result = { { 1, 2, 3, 4, 5, 6 } };
  return result;
}

int main_noncompliant(void) {
  printf("%x", ++(addressee().a[0]));
  return 0;
}

int main_compliant(void) {
  struct X my_x = addressee();
  printf("%x", ++(my_x.a[0]));
  return 0;
}

void main(void) {
  main_compliant();
  main_noncompliant();
}
