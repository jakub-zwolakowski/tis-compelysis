#include <stdio.h>
  
int func(const char *filename) {
  FILE *f = fopen(filename, "w");
  if (NULL == f) {
    return -1;
  }
  /* ... */
  return 0;
}

int main(void) {
  func("example_file");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c 
// C17: ?
// UB: ?
