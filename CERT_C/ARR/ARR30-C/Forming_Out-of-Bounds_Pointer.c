#include <stdlib.h>

enum { TABLESIZE = 100 };

static int table[TABLESIZE];

int *f_noncompliant(int index) {
  if (index < TABLESIZE) {
    return table + index;
  }
  return NULL;
}

int *f_compliant(int index) {
  if (index >= 0 && index < TABLESIZE) {
    return table + index;
  }
  return NULL;
}

void main(void) {
  f_compliant(-1);
  f_noncompliant(-1);
}
