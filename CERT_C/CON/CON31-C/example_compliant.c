#include <stdatomic.h>
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;
/* Atomic so multiple threads can increment safely */
atomic_int completed = ATOMIC_VAR_INIT(0);
enum { max_threads = 5 };

void *do_work(void *dummy) {
  /* Lock */
  if (0 != pthread_mutex_lock(&lock)) {
    /* Handle error */
    return NULL;
  }
  /* Access data protected by the lock */
  atomic_fetch_add(&completed, 1);
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("compliant %d\n", completed);
#endif
  /* Unlock */
  if (0 != pthread_mutex_unlock(&lock)) {
    /* Handle error */
    return NULL;
  }
 
  return NULL;
}

int main(void) {
  pthread_t threads[max_threads];
 
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("compliant beginning\n");
#endif
  if (0 != pthread_mutex_init(&lock, NULL)) {
    /* Handle error */
    return 0;
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&threads[i], NULL, do_work, NULL)) {
      /* Handle error */
      return 0;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_join(threads[i], 0)) {
      /* Handle error */
      return 0;
    }
  }
 
  pthread_mutex_destroy(&lock);
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("compliant end\n");
#endif
  return 0;
}

// NOT DETECTED
// Does not match creating and joining a thread.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races test_CON31-C_compliant.c
// COMPILE: gcc -lpthread
