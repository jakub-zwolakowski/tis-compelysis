#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

mtx_t lock;
/* Atomic so multiple threads can modify safely */
atomic_int completed = ATOMIC_VAR_INIT(0);
enum { max_threads = 5 };

int do_work(void *arg) {
  int *i = (int *)arg;
 
  if (*i == 0) { /* Creation thread */
    if (thrd_success != mtx_init(&lock, mtx_plain)) {
      /* Handle error */
      return thrd_error;
    }
    atomic_store(&completed, 1);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Creation %d\n", *i, completed);
  #endif
  } else if (*i < max_threads - 1) { /* Worker thread */
    if (thrd_success != mtx_lock(&lock)) {
      /* Handle error */
      return thrd_error;
    }
    /* Access data protected by the lock */
    atomic_fetch_add(&completed, 1);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Worker %d\n", *i, completed);
  #endif
    if (thrd_success != mtx_unlock(&lock)) {
      /* Handle error */
      return thrd_error;
    }
  } else { /* Destruction thread */
    mtx_destroy(&lock);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Destruction %d\n", *i, completed);
  #endif
  }
  return 0;
}

int main(void) {
  thrd_t threads[max_threads];

  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_create(&threads[i], do_work, &i)) {
      /* Handle error */
      return 1;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_join(threads[i], 0)) {
      /* Handle error */
      return 2;
    }
  }

  return 0;
}

// NOT DETECTED
// Does not match creating and joining a thread.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races -val-continue-on-pointer-library-function example_noncompliant.c
// COMPILE: gcc -lpthread
