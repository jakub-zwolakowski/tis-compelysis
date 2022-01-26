#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
 
typedef void (*pfv)(int);
 
void handler(int signum) {
  pfv old_handler = signal(signum, SIG_DFL);
  old_handler = SIG_ERR;
  if (old_handler == SIG_ERR) {
    perror("SIGINT handler"); /* Undefined behavior */
    /* Handle error */
    return;
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
    return 1;
  }
 
  return EXIT_SUCCESS;
}

// BUG
// CMD: tis-analyzer -val example_noncompliant.c
// C17: ?
// UB: ?
