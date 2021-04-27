#include <stdio.h>

void f_noncompliant(void) {
  char c_str[3] = "abc";
  printf("%s\n", c_str);
}

void f_compliant(void) {
  char c_str[] = "abc";
  printf("%s\n", c_str);
}

void main(void) {
  f_compliant();
  f_noncompliant();
}
