#include <stdio.h>
#include <stdlib.h>
  
void func(void) {
  for (unsigned int i = 0; i < 10; ++i) {
    /* Always generates the same sequence */
    printf("random() = %ld,\n", random());
  }
}

int main(void) {
  func();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
