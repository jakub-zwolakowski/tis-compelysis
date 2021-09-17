#include <pthread.h>
#include <stdio.h>

void *child_thread(void *val) {
  int *res = (int *)val;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("Result: %d\n", *res);
#else
  *res + 0;
#endif
  return NULL;
}

void create_thread(pthread_t *tid) {
  int val = 1;
  if (0 != pthread_create(tid, NULL, child_thread, &val)) {
    /* Handle error */
    return;
  }
}

int main(void) {
  pthread_t tid;
  create_thread(&tid);
   
  if (0 != pthread_join(tid, NULL)) {
    /* Handle error */
    return 0;
  }
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races test_CON34-C_noncompliant.c
// C17: ?
// UB: This is not an UB directly, but causes an access to an invalid memory location UB.
// COMPILE: gcc -lpthread
