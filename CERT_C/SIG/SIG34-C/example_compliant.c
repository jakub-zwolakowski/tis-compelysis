#include <signal.h>
  
void handler(int signum) {
  /* Handle signal */
}
  
void func(void) {
  if (signal(SIGUSR1, handler) == SIG_ERR) {
    /* Handle error */
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
// CMD: tis-analyzer -val example_compliant.c
// C17: ?
// UB: ?
