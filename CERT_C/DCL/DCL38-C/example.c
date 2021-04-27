#include <stdlib.h>

struct flexArrayStruct_noncompliant {
  int num;
  int data[1];
};

void f_noncompliant(size_t array_size) {
  /* Space is allocated for the struct */
  struct flexArrayStruct_noncompliant *structP
    = (struct flexArrayStruct_noncompliant *)
     malloc(sizeof(struct flexArrayStruct_noncompliant)
          + sizeof(int) * (array_size - 1));
  if (structP == NULL) {
    /* Handle malloc failure */
    return;
  }

  structP->num = array_size;

  /*
   * Access data[] as if it had been allocated
   * as data[array_size].
   */
  for (size_t i = 0; i < array_size; ++i) {
    structP->data[i] = 1;
  }
}

struct flexArrayStruct_compliant {
  int num;
  int data[];
};

void f_compliant(size_t array_size) {
  /* Space is allocated for the struct */
  struct flexArrayStruct_compliant *structP
    = (struct flexArrayStruct_compliant *)
    malloc(sizeof(struct flexArrayStruct_compliant)
         + sizeof(int) * array_size);
  if (structP == NULL) {
    /* Handle malloc failure */
  }

  structP->num = array_size;

  /*
   * Access data[] as if it had been allocated
   * as data[array_size].
   */
  for (size_t i = 0; i < array_size; ++i) {
    structP->data[i] = 1;
  }
}

void main(void) {
  f_compliant(42);
  f_noncompliant(42);
}
