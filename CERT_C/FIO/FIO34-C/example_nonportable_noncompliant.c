#include <assert.h>
#include <limits.h>
#include <stdio.h>
 
void func(void) {
  char c;
  static_assert(UCHAR_MAX < UINT_MAX, "FIO34-C violation");
 
  do {
    c = getchar();
  } while (c != EOF);
}

int main(void) {
  func();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_nonportable_noncompliant.c 
// C17: ?
// UB: ?
