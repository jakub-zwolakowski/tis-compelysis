#include <signal.h>
#include <stddef.h>
#include <stdatomic.h>
#include <stdbool.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

atomic_bool flag = ATOMIC_VAR_INIT(false);
 
int func(void *data) {
  while (!flag) {
    /* ... */
  }
  return 0;
}
 
int main(void) {
  thrd_t tid;
   
  if (thrd_success != thrd_create(&tid, func, NULL)) {
    /* Handle error */
    return 1;
  }
  /* ... */
  /* Set flag when done */
  flag = true;

  thrd_join(tid, NULL);
 
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: https://cigix.me/c17#7.14.1.1.p7
// UB: "The signal function is used in a multi-threaded program"
// COMPILE: gcc -lpthread
