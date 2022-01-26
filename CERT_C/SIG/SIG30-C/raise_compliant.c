#include <signal.h>
#include <stdlib.h>
  
void term_handler(int signum) {
  /* SIGTERM handler */
}
  
void int_handler(int signum) {
  /* SIGINT handler */
  /* Pass control to the SIGTERM handler */
  term_handler(SIGTERM);
}
  
int main(void) {
  if (signal(SIGTERM, term_handler) == SIG_ERR) {
    /* Handle error */
    return EXIT_FAILURE;
  }
  if (signal(SIGINT, int_handler) == SIG_ERR) {
    /* Handle error */
    return EXIT_FAILURE;
  }
  
  /* Program code */
  if (raise(SIGINT) != 0) {
    /* Handle error */
    return EXIT_FAILURE;
  }
  /* More code */
  
  return EXIT_SUCCESS;
}

// BUG
// CMD: tis-analyzer --interpreter raise_compliant.c
// C17: ?
// UB: ?
