#include <stdio.h>
  
void func(const char *file_name) {
  FILE *fptr = NULL;
  int c = 'a';
  
  while (c <= 'z') {
    if (putc(c++, fptr ? fptr :
         (fptr = fopen(file_name, "w"))) == EOF) {
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
// CMD: tis-analyzer --interpreter example_noncompliant.c 
// C17: ?
// UB: ?
