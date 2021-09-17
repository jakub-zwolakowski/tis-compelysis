#include <stdatomic.h>
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
  
pthread_mutex_t lock;
/* Atomic so multiple threads can modify safely */
atomic_int completed = ATOMIC_VAR_INIT(0);
enum { max_threads = 5 };

void *do_work(void *arg) {
  int *i = (int *)arg;
 
  if (*i == 0) { /* Creation thread */
    if (0 != pthread_mutex_init(&lock, NULL)) {
      /* Handle error */
      return NULL;
    }
    atomic_store(&completed, 1);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Creation %d\n", *i, completed);
  #endif
  } else if (*i < max_threads - 1) { /* Worker thread */
    if (0 != pthread_mutex_lock(&lock)) {
      /* Handle error */
      return NULL;
    }
    /* Access data protected by the lock */
    atomic_fetch_add(&completed, 1);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Worker %d\n", *i, completed);
  #endif
    if (0 != pthread_mutex_unlock(&lock)) {
      /* Handle error */
      return NULL;
    }
  } else { /* Destruction thread */
    pthread_mutex_destroy(&lock);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Destruction %d\n", *i, completed);
  #endif
  }
  return NULL;
}
  
int main(void) {
  pthread_t threads[max_threads];

#ifndef __TRUSTINSOFT_ANALYZER__
  printf("noncompliant beginning\n");
#endif
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&threads[i], NULL, do_work, &i)) {
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
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("noncompliant end\n");
#endif
  return 0;
}

// NOT DETECTED
// Does not match creating and joining a thread.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races test_CON31-C_noncompliant.c
// COMPILE: gcc -lpthread
