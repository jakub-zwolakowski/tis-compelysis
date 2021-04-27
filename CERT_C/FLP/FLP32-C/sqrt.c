#include <math.h>

void f_noncompliant(double x) {
  double result;
  result = sqrt(x);
}

void f_compliant(double x) {
  double result;

  if (isless(x, 0.0)) {
    /* Handle domain error */
    x = 0.0;
  }

  result = sqrt(x);
}

void main(void) {
  f_compliant(1);
  f_compliant(-1);
  f_noncompliant(1);
  f_noncompliant(-1);
}
