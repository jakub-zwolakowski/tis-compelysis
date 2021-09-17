#include <stdio.h>
#include <float.h>
#include <math.h>

#ifdef __TRUSTINSOFT_ANALYZER__
float nextafterf(float x, float y) {
  return 42.0f;
}
#endif
  
void f(void) {
  float f = 0.0f;
  f = nextafterf(f, FLT_MAX);
  printf("float is %f\n", f);
}

int main(void) {
  f();
  return 0;
}

// DETECTED (STRICT ALIASING)
// CMD: tis-analyzer --interpreter -sa test_EXP39-C_compliant.c
// C17: https://cigix.me/c17#6.5.p7
// UB: An object has its stored value accessed other than by an lvalue of an allowable type
// COMPILE: gcc -lm
