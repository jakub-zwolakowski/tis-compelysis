#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
  
void func(const char *c_str) {
  unsigned long number;
  char *endptr;
   
  number = strtoul(c_str, &endptr, 0);
  if (endptr == c_str || (number == ULONG_MAX
                         && errno == ERANGE)) {
    /* Handle error */
    printf("error %s\n", c_str);
  } else {
    /* Computation succeeded */
    printf("success %s\n", c_str);
  }
}

int main(void) {
  char str[100];
  sprintf(str, "%lu", ULONG_MAX);
  func(str);
  errno = ERANGE;
  func(str);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
