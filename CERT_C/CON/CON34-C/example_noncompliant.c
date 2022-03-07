#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

int child_thread(void *val) {
  int *res = (int *)val;
#ifndef __TRUSTINSOFT_ANALYZER__
  /* Bug (probably) in mthread - backtrace if printf is used here. */
  printf("Result: %d\n", *res);
#else
  *res + 0;
#endif
  return 0;
}

void create_thread(thrd_t *tid) {
  int val = 1;
  if (thrd_success != thrd_create(tid, child_thread, &val)) {
    /* Handle error */
    return;
  }
}

int main(void) {
  thrd_t tid = 0;
  create_thread(&tid);
   
  if (thrd_success != thrd_join(tid, NULL)) {
    /* Handle error */
    return 1;
  }
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_noncompliant.c
// C17: ?
// UB: This is not an UB directly, but causes an access to an invalid memory location UB.
// COMPILE: gcc -lpthread
