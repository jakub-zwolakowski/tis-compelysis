#include <stdio.h>
#include <float.h>
#include <math.h>

#ifdef __TRUSTINSOFT_ANALYZER__
float nextafterf(float x, float y) {
  return 42.0f;
}
#endif

void f_noncompliant(void) {
  if (sizeof(int) == sizeof(float)) {
    float f = 0.0f;
    int *ip = (int *)&f;
    (*ip)++;
    printf("float is %f\n", f);
  }
}
  
void f_compliant(void) {
  float f = 0.0f;
  f = nextafterf(f, FLT_MAX);
  printf("float is %f\n", f);
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}

// DETECTED (STRICT ALIASING)
// CMD: tis-analyzer --interpreter -sa test_EXP39-C.c
// C17: https://cigix.me/c17#6.5.p7
// UB: An object has its stored value accessed other than by an lvalue of an allowable type
// COMPILE: gcc -lm
