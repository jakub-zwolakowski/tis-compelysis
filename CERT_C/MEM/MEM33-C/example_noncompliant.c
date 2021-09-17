#include <stddef.h>
#include <stdlib.h>

struct flex_array_struct {
  size_t num;
  int data[];
};

void func(void) {
  struct flex_array_struct flex_struct;
  size_t array_size = 4;
 
  /* Initialize structure */
  flex_struct.num = array_size;
 
  for (size_t i = 0; i < array_size; ++i) {
    flex_struct.data[i] = 0;
  }
}
int main(void) {
  func();
  return 0;
}

// DETECTED!
// CMD: tis-analyzer --interpreter test_MEM33-C_noncompliant.c
// C17: https://cigix.me/c17#6.7.2.1.p18
// UB: This is not an UB directly, but causes indirectly an an Out-of-bound Write UB.
