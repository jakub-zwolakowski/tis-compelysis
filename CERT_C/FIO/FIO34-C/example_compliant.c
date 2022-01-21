#include <stdio.h>
 
void func(void) {
  int c;
 
  do {
    c = getchar();
  } while (c != EOF || (!feof(stdin) && !ferror(stdin)));
}

int main(void) {
  func();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c 
// C17: ?
// UB: ?
