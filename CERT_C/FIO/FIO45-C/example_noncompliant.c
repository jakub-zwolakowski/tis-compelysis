#include <stdio.h>

void open_some_file(const char *file) {
  FILE *f = fopen(file, "r");
  if (NULL != f) {
    /* File exists, handle error */
    fclose(f);
    return;
  } else {
    if (fclose(f) == EOF) {
      /* Handle error */
      return;
    }
    f = fopen(file, "w");
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
}

int main(void) {
  open_some_file("example_file");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c 
// C17: ?
// UB: ?
