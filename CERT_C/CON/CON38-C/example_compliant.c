#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

enum { NTHREADS = 5 };

mtx_t mutex;
cnd_t cond;

int run_step(void *t) {
  static size_t current_step = 0;
  size_t my_step = *(size_t *)t;
 
  if (thrd_success != mtx_lock(&mutex)) {
    /* Handle error */
    mtx_unlock(&mutex);
    return thrd_error;
  }
 
  printf("Thread %zu has the lock\n", my_step);
 
  while (current_step != my_step) {
    printf("Thread %zu is sleeping...\n", my_step);
 
    if (thrd_success != cnd_wait(&cond, &mutex)) {
      /* Handle error */
      mtx_unlock(&mutex);
      return thrd_error;
    }
 
  printf("Thread %zu woke up\n", my_step);
  }
 
  /* Do processing ... */
  printf("Thread %zu is processing...\n", my_step);
 
  current_step++;
 
  /* Signal ALL waiting tasks */
  if (thrd_success != cnd_broadcast(&cond)) {
    /* Handle error */
    return thrd_error;
  }
 
  printf("Thread %zu is exiting...\n", my_step);
 
  if (thrd_success != mtx_unlock(&mutex)) {
    /* Handle error */
    return thrd_error;
  }
  return 0;
}

int main(void) {
  thrd_t threads[NTHREADS];
  size_t step[NTHREADS];
 
  if (thrd_success != mtx_init(&mutex, mtx_plain)) {
    /* Handle error */
    return 1;
  }
 
  if (thrd_success != cnd_init(&cond)) {
    /* Handle error */
    return 2;
  }
 
  /* Create threads */
  for (size_t i = 0; i < NTHREADS; ++i) {
    step[i] = i;
 
    if (thrd_success != thrd_create(&threads[i], run_step,
                                    &step[i])) {
      /* Handle error */
      return 3;
    }
  }
 
  /* Wait for all threads to complete */
  for (size_t i = NTHREADS; i != 0; --i) {
    if (thrd_success != thrd_join(threads[i-1], NULL)) {
      /* Handle error */
      return 4;
    }
  }
 
  mtx_destroy(&mutex);
  cnd_destroy(&cond);
  return 0;
} 

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_compliant.c
// C17: ?
// UB: ?
// COMPILE: gcc -lpthread
