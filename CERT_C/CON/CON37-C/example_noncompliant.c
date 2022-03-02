#include <signal.h>
#include <stddef.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif
  
volatile sig_atomic_t flag = 0;
 
void handler(int signum) {
  flag = 1;
}
 
/* Runs until user sends SIGUSR1 */
int func(void *data) {
  while (!flag) {
    /* ... */
  }
  return 0;
}
 
int main(void) {
  signal(SIGUSR1, handler); /* Undefined behavior */
  thrd_t tid;
   
  if (thrd_success != thrd_create(&tid, func, NULL)) {
    /* Handle error */
    return 1;
  }
  /* ... */
  raise(SIGUSR1);

  thrd_join(tid, NULL);

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: https://cigix.me/c17#7.14.1.1.p7
// UB: "The signal function is used in a multi-threaded program"
// COMPILE: gcc -lpthread
