#include <stddef.h>
#include <stdlib.h>
 
struct flex_array_struct {
  size_t num;
  int data[];
};
  
void func_noncompliant(void) {
  struct flex_array_struct flex_struct;
  size_t array_size = 4;
 
  /* Initialize structure */
  flex_struct.num = array_size;
 
  for (size_t i = 0; i < array_size; ++i) {
    flex_struct.data[i] = 0;
  }
}
  
void func_compliant(void) {
  struct flex_array_struct *flex_struct;
  size_t array_size = 4;
 
  /* Dynamically allocate memory for the struct */
  flex_struct = (struct flex_array_struct *)malloc(
    sizeof(struct flex_array_struct)
    + sizeof(int) * array_size);
  if (flex_struct == NULL) {
    /* Handle error */
    return;
  }
 
  /* Initialize structure */
  flex_struct->num = array_size;
 
  for (size_t i = 0; i < array_size; ++i) {
    flex_struct->data[i] = 0;
  }

  free(flex_struct);
}

int main(void) {
  func_compliant();
  func_noncompliant();
  return 0;
}

// DETECTED!
// CMD: tis-analyzer --interpreter test_MEM33-C.c
// C17: https://cigix.me/c17#6.7.2.1.p18
// UB: This is not an UB directly, but causes indirectly an an Out-of-bound Write UB.
