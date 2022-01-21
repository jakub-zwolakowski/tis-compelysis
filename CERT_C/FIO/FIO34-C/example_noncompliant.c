#include <stdio.h>
  
void func(void) {
  int c;
  
  do {
    c = getchar();
  } while (c != EOF);
}

int main(void) {
  func();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c 
// C17: ?
// UB: ?
