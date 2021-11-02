#include <float.h>
#include <limits.h>

void f_noncompliant(void) {
  float f = FLT_MAX;
  int i = f;
  float g = -21474836490;
  int j = g;
}

void f_compliant(void) {
  float f = FLT_MAX;
  int i = 0;
  if (f < INT_MAX)
      i = f;
  float g = -21474836490;
  int j = 0;
  if (INT_MIN < g)
      j = g;
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
