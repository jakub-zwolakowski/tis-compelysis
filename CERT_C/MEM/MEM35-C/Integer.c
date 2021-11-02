#include <stdint.h>
#include <stdlib.h>

void f_noncompliant(size_t len) {
  long *p;
  if (len == 0 || len > SIZE_MAX / sizeof(long)) {
    /* Handle overflow */
    return;
  }
  p = (long *)malloc(len * sizeof(int));
  if (p == NULL) {
    /* Handle error */
    return;
  }
  int i;
  for(i = 0; i < len; i++) {
    p[i] = i;
  }
  free(p);
}

void f_compliant(size_t len) {
  long *p;
  if (len == 0 || len > SIZE_MAX / sizeof(long)) {
    /* Handle overflow */
    return;
  }
  p = (long *)malloc(len * sizeof(long));
  if (p == NULL) {
    /* Handle error */
    return;
  }
  int i;
  for(i = 0; i < len; i++) {
    p[i] = i;
  }
  free(p);
}

int main(void) {
  f_compliant(42);
  f_noncompliant(42);
  return 0;
}
