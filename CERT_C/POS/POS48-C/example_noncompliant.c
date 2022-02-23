#include <pthread.h>
#include <stdio.h>

pthread_mutex_t theLock;
int data;
 
void *cleanupAndFinish(void *arg) {
  int result;
  if ((result = pthread_mutex_destroy(&theLock)) != 0) {
    /* Handle error */
  }
  data++;
  return &data;
}
 
void *worker(void *arg) {
  int value = *((int *)arg);
  int result;
  if ((result = pthread_mutex_lock(&theLock)) != 0) {
    /* Handle error */
    return NULL;
  }
  data += value;
  if ((result = pthread_mutex_unlock(&theLock)) != 0) {
    /* Handle error */
    return NULL;
  }
  return NULL;
}

enum { max_threads = 5 };

int main(void) {
  pthread_t worker_threads[max_threads];
  pthread_t cleanupAndFinish_thread;

  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&worker_threads[i], NULL, worker, &i)) {
      /* Handle error */
      return 1;
    }
  }
  if (0 != pthread_create(&cleanupAndFinish_thread, NULL, cleanupAndFinish, NULL)) {
    /* Handle error */
    return 2;
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_join(worker_threads[i], 0)) {
      /* Handle error */
      return 3;
    }
  }
  if (0 != pthread_join(cleanupAndFinish_thread, 0)) {
    /* Handle error */
    return 4;
  }

  // printf ("%d", data);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread example_noncompliant.c
// C17: ?
// UB: ?
