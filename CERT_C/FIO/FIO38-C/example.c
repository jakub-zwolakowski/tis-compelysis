#include <stdio.h>
  
int main_compliant(void) {
  FILE *my_stdout = stdout;
  if (fputs("Hello, World!\n", my_stdout) == EOF) {
    /* Handle error */
    return 0;
  }
  return 0;
}

int main_noncompliant(void) {
  FILE my_stdout = *stdout;
  if (fputs("Hello, World!\n", &my_stdout) == EOF) {
    /* Handle error */
    return 0;
  }
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_FIO38-C.c
// C17: https://cigix.me/c17#7.21.3.p6
// UB: I don't think this is an UB.
