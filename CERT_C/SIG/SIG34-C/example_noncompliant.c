#include <signal.h>
  
void handler(int signum) {
  if (signal(signum, handler) == SIG_ERR) {
    /* Handle error */
    return;
  }
  /* Handle signal */
}
  
void func(void) {
  if (signal(SIGUSR1, handler) == SIG_ERR) {
    /* Handle error */
    return;
  }
}
 
int main(void) {
  func();

  if (raise(SIGUSR1) != 0) {
    /* Handle error */
    return 1;
  }

  return 0;
}

// BUG
// CMD: tis-analyzer -val example_noncompliant.c
// C17: ?
// UB: ?
