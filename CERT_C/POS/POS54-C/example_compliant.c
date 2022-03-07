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
 
  if (in == NULL){
    /* Handle error */
    return 2;
  }
  /* Use in */
  
  out = open_memstream(&ptr, &size);
 
  if (out == NULL){
    /* Handle error */
    return 3;
  }

  /* Use out */
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter -val-args=" 42" example_compliant.c
// C17: ?
// UB: ?
