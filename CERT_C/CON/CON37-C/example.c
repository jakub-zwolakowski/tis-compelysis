#include <signal.h>
#include <stddef.h>
#include <pthread.h>
  
volatile sig_atomic_t flag_noncompliant = 0;
 
void handler(int signum) {
  flag_noncompliant = 1;
}
 
/* Runs until user sends SIGUSR1 */
void *func_noncompliant(void *data) {
  while (!flag_noncompliant) {
    /* ... */
  }
  return 0;
}
 
int main_noncompliant(void) {
  signal(SIGUSR1, handler); /* Undefined behavior */
  pthread_t tid;
  flag_noncompliant = 0;
  if (0 != pthread_create(&tid, NULL, func_noncompliant, NULL)) {
    /* Handle error */
    return 0;
  }
  /* ... */
  return 0;
}

#include <stdatomic.h>
#include <stdbool.h>
  
atomic_bool flag_compliant = ATOMIC_VAR_INIT(false);
 
void *func_compliant(void *data) {
  while (!flag_compliant) {
    /* ... */
  }
  return NULL;
}
 
int main_compliant(void) {
  pthread_t tid;
   
  if (0 != pthread_create(&tid, NULL, func_compliant, NULL)) {
    /* Handle error */
    return 0;
  }
  /* ... */
  /* Set flag when done */
  flag_compliant = true;
 
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_CON37-C.c
// C17: https://cigix.me/c17#7.14.1.1.p7
// UB: "The signal function is used in a multi-threaded program"
// COMPILE: gcc -lpthread
