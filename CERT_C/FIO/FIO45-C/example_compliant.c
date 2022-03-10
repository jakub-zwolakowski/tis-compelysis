#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 3

void open_some_file(const char *file) {
  FILE *f = fopen(file, "wx");
  if (NULL == f) {
    /* Handle error */
    return;
  }
  /* Write to file */
  char data[BUFFERSIZE];
  memset(data, 81, BUFFERSIZE);
  if (fwrite(data, BUFFERSIZE, 1, f) < BUFFERSIZE) {
    /* Handle error */
    fclose(f);
    return;
  }
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
