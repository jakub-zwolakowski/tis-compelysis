#include <stddef.h>
#include <pthread.h>
  
void *thread_func(void *arg) {
  /* Do work */
  return NULL;
}
 
int main_noncompliant(void) {
  pthread_t t;
  if (0 != pthread_create(&t, NULL, thread_func, NULL)) {
    /* Handle error */
    return 0;
  }
  if (0 != pthread_join(t, 0)) {
    /* Handle error */
    return 0;
  }
  if (0 != pthread_join(t, 0)) {
    /* Handle error */
    return 0;
  }
  return 0;
}
 
int main_compliant(void) {
  pthread_t t;
  if (0 != pthread_create(&t, NULL, thread_func, NULL)) {
    /* Handle error */
    return 0;
  }
  if (0 != pthread_join(t, 0)) {
    /* Handle error */
    return 0;
  }
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// Does not match creating and joining a thread.
// CMD: tis-analyzer --interpreter test_CON39-C.c
// COMPILE: gcc -lpthread
