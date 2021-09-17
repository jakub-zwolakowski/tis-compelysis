#include <assert.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
// STUB log2
double log2(double x) {
  if (x == 2)
    return 1;
  else
    return -1;
}
#endif

/* Returns the number of set bits */
size_t popcount(uintmax_t num) {
  size_t precision = 0;
  while (num != 0) {
    if (num % 2 == 1) {
      precision++;
    }
    num >>= 1;
  }
  return precision;
}
#define PRECISION(umax_value) popcount(umax_value)

int main_compliant(void) {
  assert(PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX));
  long int big = 1234567890L;
  double approx = big;
  printf("%ld\n", (big - (long int)approx));
  return 0;
}

int main_noncompliant(void) {
  long int big = 1234567890L;
  float approx = big;
  printf("%ld\n", (big - (long int)approx));
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_FLP36-C_compliant.c
// C17: https://cigix.me/c17#6.3.1.5.p1
// UB: This is not an UB.
