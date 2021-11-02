#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

void do_work(int *array, size_t size) {
  int i;
  for (i = 0; i < size; ++i)
    array[i] = i;
}

void f_noncompliant(size_t size) {
  int vla[size];
  do_work(vla, size);
}

enum { MAX_ARRAY = 1024 };

void f_compliant(size_t size) {
  if (0 == size || SIZE_MAX / sizeof(int) < size) {
    /* Handle error */
    return;
  }
  if (size < MAX_ARRAY) {
    int vla[size];
    do_work(vla, size);
  } else {
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
      /* Handle error */
      return;
    }
    do_work(array, size);
    free(array);
  }
}

int main(void) {
  f_compliant(42);
  f_compliant(0);
  f_compliant(INT_MAX);
  f_noncompliant(42);
  f_noncompliant(0);
  f_noncompliant(INT_MAX);
  return 0;
}
