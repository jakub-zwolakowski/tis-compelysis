/* Uncomment the following line to get the compliant version: */
// #define COMPLIANT 1

#include <stdlib.h>

#define SIZE_MAX 64

static int *table = NULL;
static size_t size = 0;

int insert_in_table(size_t pos, int value) {
#ifndef COMPLIANT
  if (size < pos) {
    int *tmp;
    size = pos + 1;
    tmp = (int *)realloc(table, sizeof(*table) * size);
    if (tmp == NULL) {
      return -1;   /* Failure */
    }
    table = tmp;
  }
#else
  if (size <= pos) {
    if ((SIZE_MAX - 1 < pos) ||
        ((pos + 1) > SIZE_MAX / sizeof(*table))) {
      return -1;
    }

    int *tmp = (int *)realloc(table, sizeof(*table) * (pos + 1));
    if (tmp == NULL) {
      return -1;   /* Failure */
    }
    /* Modify size only after realloc() succeeds */
    size  = pos + 1;
    table = tmp;
  }
#endif
  table[pos] = value;
  return 0;
}

void main(void) {
  insert_in_table(3, 43);
  insert_in_table(2, 42);
  insert_in_table(1, 41);
  insert_in_table(4, 44);
}
