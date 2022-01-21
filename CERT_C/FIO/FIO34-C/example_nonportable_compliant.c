#include <assert.h>
#include <stdio.h>
#include <limits.h>
 
void func(void) {
  int c;
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
// CMD: tis-analyzer --interpreter example_nonportable_compliant.c 
// C17: ?
// UB: ?
