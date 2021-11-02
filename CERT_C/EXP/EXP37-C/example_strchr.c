#include <stdio.h>
#include <string.h>

char *(*fp_noncompliant)();

void f_noncompliant(void) {
  const char *c;
  fp_noncompliant = strchr;
  c = fp_noncompliant('e', "Hello");
  printf("%s\n", c);
}

char *(*fp_compliant)(const char *, int);

void f_compliant(void) {
  const char *c;
  fp_compliant = strchr;
  c = fp_compliant("Hello",'e');
  printf("%s\n", c);
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
