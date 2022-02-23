#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

volatile int a = 5;
volatile int b = 10;

/* Lock to enable threads to access a and b safely */
pthread_mutex_t global_lock = PTHREAD_MUTEX_INITIALIZER;

void* worker_thread(void* dummy) {
  int c;
  int result;
 
  while (1) {
    if ((result = pthread_mutex_lock(&global_lock)) != 0) {
      /* handle error */
      return NULL;
    }
    c = b;
    b = a;
    a = c;
    if ((result = pthread_mutex_unlock(&global_lock)) != 0) {
      /* handle error */
      return NULL;
    }
 
    /* now we're safe to cancel, creating cancel point */
    pthread_testcancel();
  }
  return NULL;
}

int main(void) {
  int result;
  pthread_t worker;

  if ((result = pthread_create( &worker, NULL, worker_thread, NULL)) != 0) {
    /* handle error */
    return 1;
  }

  /* .. Do stuff...meanwhile worker thread runs for some time */

  /* since we don't know when the character is read in, the program could continue at any time */
  if ((result = pthread_cancel(worker)) != 0) {
    /* handle error */
    return 2;
  }
  /* pthread_join waits for the thread to finish up before continuing */
  if ((result = pthread_join(worker, 0)) != 0) {
    /* handle error */
    return 3;
  }

  if ((result = pthread_mutex_lock(&global_lock)) != 0) {
    /* handle error */
    return 4;
  }
  printf("a: %i | b: %i", a, b);
  if ((result = pthread_mutex_unlock(&global_lock)) != 0) {
    /* handle error */
    return 5;
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread example_compliant.c
// C17: ?
// UB: ?
