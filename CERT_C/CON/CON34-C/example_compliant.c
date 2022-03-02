#include <stdio.h>
#include <stdlib.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

int child_thread(void *val) {
  int *result = (int *)val;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("Result: %d\n", *result);  /* Correctly prints 1 */
#else
  *result + 0;
#endif
  return 0;
}

void create_thread(thrd_t *tid, int *value) {
  *value = 1;
  if (thrd_success != thrd_create(tid, child_thread,
                                  value)) {
    /* Handle error */
  }
}
  
int main(void) {
  thrd_t tid;
  int *value = (int *)malloc(sizeof(int));
  if (!value) {
    /* Handle error */
    return 1;
  }
  create_thread(&tid, value);
  if (thrd_success != thrd_join(tid, NULL)) {
    /* Handle error */
    return 2;
  }
  free(value);
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_compliant.c
// C17: ?
// UB: This is not an UB directly, but causes an access to an invalid memory location UB.
// COMPILE: gcc -lpthread
