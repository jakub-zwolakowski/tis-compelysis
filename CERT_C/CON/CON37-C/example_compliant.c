#include <signal.h>
#include <stddef.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>

atomic_bool flag = ATOMIC_VAR_INIT(false);
 
void *func(void *data) {
  while (!flag) {
    /* ... */
  }
  return NULL;
}
 
int main(void) {
  pthread_t tid;
   
  if (0 != pthread_create(&tid, NULL, func, NULL)) {
    /* Handle error */
    return 0;
  }
  /* ... */
  /* Set flag when done */
  flag = true;
 
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_CON37-C_compliant.c
// C17: https://cigix.me/c17#7.14.1.1.p7
// UB: "The signal function is used in a multi-threaded program"
// COMPILE: gcc -lpthread
