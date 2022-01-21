#include <stdio.h>
  
void func(const char *file_name) {
  FILE *file;
  if ((file = fopen(file_name, "wb")) == NULL) {
    /* Handle error */
    return;
  }
 
  /* Operate on the file */
 
  if (fclose(file) == EOF) {
    /* Handle error */
    return;
  }
}

int main(void) {
  func("/dev/zero");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
