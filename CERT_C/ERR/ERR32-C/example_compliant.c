#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
 
typedef void (*pfv)(int);
 
void handler(int signum) {
  pfv old_handler = signal(signum, SIG_DFL);
  if (old_handler == SIG_ERR) {
    abort();
  }
}
 
int main(void) {
  pfv old_handler = signal(SIGINT, handler);
  if (old_handler == SIG_ERR) {
    perror("SIGINT handler");
    /* Handle error */
    return 1;
  }
 
  /* Main code */
  if (raise(SIGINT) != 0) {
    /* Handle error */
    return EXIT_FAILURE;
  }
 
  return EXIT_SUCCESS;
}

// BUG
// CMD: tis-analyzer -val example_compliant.c
// C17: ?
// UB: ?
