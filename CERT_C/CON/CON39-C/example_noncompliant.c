#include <stddef.h>
#include <unistd.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif
  
int thread_func(void *arg) {
  /* Do work */
  sleep(1);
  thrd_detach(thrd_current());
  return 0;
}
 
int main(void) {
  thrd_t t;
 
  if (thrd_success != thrd_create(&t, thread_func, NULL)) {
    /* Handle error */
    return 1;
  }
  sleep(2);
  if (thrd_success != thrd_join(t, 0)) {
    /* Handle error */
    return 2;
  }
  return 0;
}

// NOT DETECTED
// Does not match creating and joining a thread.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_noncompliant.c
// COMPILE: gcc -lpthread
