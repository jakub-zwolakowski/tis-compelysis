#include <stdio.h>
 
int main(void) {
  long int big = 1234567890L;
  float approx = big;
  printf("%ld\n", (big - (long int)approx));
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_FLP36-C_compliant.c
// C17: https://cigix.me/c17#6.3.1.5.p1
// UB: This is not an UB.
