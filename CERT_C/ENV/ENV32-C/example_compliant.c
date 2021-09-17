#include <stdlib.h>
#include <stdio.h>

int some_condition;

void exit1(void) {
  printf("exit1\n");
  /* ... Cleanup code ... */
  return;
}

void exit2(void) {
  printf("exit2\n");
  extern int some_condition;
  if (some_condition) {
    printf("exit2 : some_condition\n");
    /* ... More cleanup code ... */
  }
  return;
}

int main(void) {
  if (atexit(exit1) != 0) {
    /* Handle error */
  }
  if (atexit(exit2) != 0) {
    /* Handle error */
  }
  /* ... Program code ... */
  some_condition = 1;
  exit(0);
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_ENV32-C_compliant.c
// C17: https://cigix.me/c17#7.22.4.4.p2
// UB: "The program calls the exit or quick_exit function more than once, or calls both functions"
