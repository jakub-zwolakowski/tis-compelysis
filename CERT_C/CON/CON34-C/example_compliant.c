#include <pthread.h>
#include <stdio.h>

void *child_thread(void *v) {
  int *result = (int *)v;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("Result: %d\n", *result);  /* Correctly prints 1 */
#else
  *result + 0;
#endif
  return NULL;
}
  
void create_thread(pthread_t *tid) {
  static int val = 1;
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
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races test_CON34-C_compliant.c
// C17: ?
// UB: This is not an UB directly, but causes an access to an invalid memory location UB.
// COMPILE: gcc -lpthread
