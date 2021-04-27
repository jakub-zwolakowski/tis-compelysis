#include <stddef.h>

void init(int **ptr, int *i) {
  if (*i < 13) {
    *ptr = i;
  }
}

int f_noncompliant(int i) {
  int *p = NULL;
  init(&p, &i);
  return *p;
}

int f_compliant(int i) {
  int *p = NULL;
  init(&p, &i);
  if (NULL == p) {
    return 0;
  }
  return *p;
}

void main(void) {
  f_compliant(0);
  f_compliant(42);
  f_noncompliant(0);
  f_noncompliant(42);
}
