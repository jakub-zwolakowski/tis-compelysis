#include <stdio.h>
 
void open_some_file(const char *file) {
  FILE *f = fopen(file, "wx");
  if (NULL == f) {
    /* Handle error */
    return;
  }
  /* Write to file */
  if (fclose(f) == EOF) {
    /* Handle error */
    return;
  }
}

int main(void) {
  open_some_file("example_file");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c 
// C17: ?
// UB: ?
