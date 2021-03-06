#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void *func(void *foo) {
  /* Execution of thread */
  while (1) {
    sleep(10);
  }
  return NULL;
}
 
int main(void) {
  int result;
  pthread_t thread;
 
  if ((result = pthread_create(&thread, NULL, func, 0)) != 0) {
    /* Handle Error */
    return 1;
  }
  if ((result = pthread_cancel(thread)) != 0) {
    /* Handle Error */
    return 2;
  }
  pthread_join(thread, NULL);
 
  /* Continue executing */
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread example_compliant.c
// C17: ?
// UB: ?
