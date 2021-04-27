#include <assert.h>

void func_noncompliant(void) {
  char c = 'x';
  int *ip = (int *)&c; /* This can lose information */
  char *cp = (char *)ip;

  /* Will fail on some conforming implementations */
  assert(cp == &c);
}

void func_compliant(void) {
  char c = 'x';
  int i = c;
  int *ip = &i;

  assert(ip == &i);
}

void main(void) {
  func_compliant();
  func_noncompliant();
}
