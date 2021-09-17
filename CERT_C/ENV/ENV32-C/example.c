#include <stdlib.h>
#include <stdio.h>

int some_condition;

void exit1(void) {
  printf("exit1\n");
  /* ... Cleanup code ... */
  return;
}
  
void exit2_noncompliant(void) {
  printf("exit2_noncompliant\n");
  extern int some_condition;
  if (some_condition) {
    printf("exit2_noncompliant : some_condition\n");
    /* ... More cleanup code ... */
    exit(0);
  }
  return;
}

void exit2_compliant(void) {
  printf("exit2_compliant\n");
  extern int some_condition;
  if (some_condition) {
    printf("exit2_compliant : some_condition\n");
    /* ... More cleanup code ... */
  }
  return;
}

int main(void) {
  if (atexit(exit1) != 0) {
    /* Handle error */
  }
  if (atexit(exit2_noncompliant) != 0) {
    /* Handle error */
  }
  if (atexit(exit2_compliant) != 0) {
    /* Handle error */
  }
  /* ... Program code ... */
  some_condition = 1;
  exit(0);
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_ENV32-C.c
// C17: https://cigix.me/c17#7.22.4.4.p2
// UB: "The program calls the exit or quick_exit function more than once, or calls both functions"
