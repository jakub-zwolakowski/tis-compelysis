#include <stdio.h>
#include <float.h>
#include <math.h>

void f(void) {
  if (sizeof(int) == sizeof(float)) {
    float f = 0.0f;
    int *ip = (int *)&f;
    (*ip)++;
    printf("float is %f\n", f);
  }
}

int main(void) {
  f();
  return 0;
}

// DETECTED (STRICT ALIASING)
// CMD: tis-analyzer --interpreter -sa test_EXP39-C_noncompliant.c
// C17: https://cigix.me/c17#6.5.p7
// UB: An object has its stored value accessed other than by an lvalue of an allowable type
// COMPILE: gcc -lm
