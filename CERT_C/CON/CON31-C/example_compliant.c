#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

mtx_t lock;
/* Atomic so multiple threads can increment safely */
atomic_int completed = ATOMIC_VAR_INIT(0);
enum { max_threads = 5 };

int do_work(void *dummy) {
  if (thrd_success != mtx_lock(&lock)) {
    /* Handle error */
    return thrd_error;
  }
  /* Access data protected by the lock */
  atomic_fetch_add(&completed, 1);
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("compliant %d\n", completed);
#endif
  if (thrd_success != mtx_unlock(&lock)) {
    /* Handle error */
    return thrd_error;
  }
 
  return 0;
}

int main(void) {
  thrd_t threads[max_threads];
   
  if (thrd_success != mtx_init(&lock, mtx_plain)) {
    /* Handle error */
    return 1;
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_create(&threads[i], do_work, NULL)) {
      /* Handle error */
      return 2;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_join(threads[i], 0)) {
      /* Handle error */
      return 3;
    }
  }
 
  mtx_destroy(&lock);
  return 0;
}

// NOT DETECTED
// Does not match creating and joining a thread.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races -val-continue-on-pointer-library-function example_compliant.c
// COMPILE: gcc -lpthread
