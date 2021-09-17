#include <signal.h>
#include <stddef.h>
#include <pthread.h>
  
volatile sig_atomic_t flag = 0;
 
void handler(int signum) {
  flag = 1;
}
 
/* Runs until user sends SIGUSR1 */
void *func(void *data) {
  while (!flag) {
    /* ... */
  }
  return 0;
}
 
int main(void) {
  signal(SIGUSR1, handler); /* Undefined behavior */
  pthread_t tid;
  flag = 0;
  if (0 != pthread_create(&tid, NULL, func, NULL)) {
    /* Handle error */
    return 0;
  }
  /* ... */
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_CON37-C_noncompliant.c
// C17: https://cigix.me/c17#7.14.1.1.p7
// UB: "The signal function is used in a multi-threaded program"
// COMPILE: gcc -lpthread
