#include <limits.h>
#include <stdio.h>

foo_noncompliant(void) {
  return UINT_MAX;
}

unsigned int foo_compliant(void) {
  return UINT_MAX;
}

int main(void) {
  long long int c_compliant = foo_compliant();
  printf("%lld\n", c_compliant);
  long long int c_noncompliant = foo_noncompliant();
  printf("%lld\n", c_noncompliant);
  return 0;
}
