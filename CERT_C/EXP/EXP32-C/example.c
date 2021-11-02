#include <stdio.h>

void f_noncompliant(void) {
  static volatile int **ipp;
  static int *ip;
  static volatile int i = 0;

  printf("i = %d.\n", i);

  ipp = &ip; /* May produce a warning diagnostic */
  ipp = (int**) &ip; /* Constraint violation; may produce a warning diagnostic */
  *ipp = &i; /* Valid */
  if (*ip != 0) { /* Valid */
    /* ... */
    return;
  }
  return;
}

void f_compliant(void) {
  static volatile int **ipp;
  static volatile int *ip;
  static volatile int i = 0;

  printf("i = %d.\n", i);

  ipp = &ip;
  *ipp = &i;
  if (*ip != 0) {
    /* ... */
    return;
  }
  return;
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
