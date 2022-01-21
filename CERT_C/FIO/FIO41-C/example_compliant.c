#include <stdio.h>
  
void func(const char *file_name) {
  int c = 'a';
  FILE *fptr = fopen(file_name, "w");
  
  if (fptr == NULL) {
    /* Handle error */
    return;
  }
 
  while (c <= 'z') {
    if (putc(c++, fptr) == EOF) {
      /* Handle error */
      return;
    }
  }
 
  if (fclose(fptr) == EOF) {
    /* Handle error */
    return;
  }
}

int main(void) {
  func("example_file");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c 
// C17: ?
// UB: ?
