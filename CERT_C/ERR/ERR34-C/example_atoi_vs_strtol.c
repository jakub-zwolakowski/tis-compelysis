#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int x = 1;

void f_noncompliant(const char *buff) {
  int si;

  if (buff) {
    si = atoi(buff);
    x = si;
  } else {
    /* Handle error */
  }
}

void f_compliant(const char *buff) {
  char *end;
  int si;

  errno = 0;

  const long sl = strtol(buff, &end, 10);

  if (end == buff) {
    fprintf(stderr, "%s: not a decimal number\n", buff);
  } else if ('\0' != *end) {
    fprintf(stderr, "%s: extra characters at end of input: %s\n", buff, end);
  } else if ((LONG_MIN == sl || LONG_MAX == sl) && ERANGE == errno) {
    fprintf(stderr, "%s out of range of type long\n", buff);
  } else if (sl > INT_MAX) {
    fprintf(stderr, "%ld greater than INT_MAX\n", sl);
  } else if (sl < INT_MIN) {
     fprintf(stderr, "%ld less than INT_MIN\n", sl);
  } else {
    si = (int)sl;

    /* Process si */
    x = si;
  }
}

int main(void) {
  f_compliant("2");
  printf("x = %d\n", x);
  f_compliant("foo");
  printf("x = %d\n", x);
  f_compliant("12345678901234567890");
  printf("x = %d\n", x);
  f_noncompliant("2");
  printf("x = %d\n", x);
  f_noncompliant("foo");
  printf("x = %d\n", x);
  f_noncompliant("12345678901234567890");
  printf("x = %d\n", x);
  return 0;
}
