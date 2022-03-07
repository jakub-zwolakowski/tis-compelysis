#include <stdio.h>
#include <string.h>
  
int main(int argc, char *argv[]) {
  FILE *out;
  FILE *in;
  size_t size;
  char *ptr;
  
  if (argc != 2) {
    /* Handle error */
    return 1;
  }
  
  in = fmemopen(argv[1], strlen(argv[1]) + 1, "r");
  /* Use in */
  
  out = open_memstream(&ptr, &size);
  /* Use out */
  
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter -val-args=" 42" example_noncompliant.c
// C17: ?
// UB: ?
