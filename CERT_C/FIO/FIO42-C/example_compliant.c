#include <stdio.h>
  
int func(const char *filename) {
  FILE *f = fopen(filename, "r");
  if (NULL == f) {
    return -1;
  }
  /* ... */
  if (fclose(f) == EOF) {
    return -1;
  }
  return 0;
}

int main(void) {
  func("example_file");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c 
// C17: ?
// UB: ?
