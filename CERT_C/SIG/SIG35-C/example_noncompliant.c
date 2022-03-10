#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
 
volatile sig_atomic_t denom;
 
void sighandle(int s) {
  /* Fix the offending volatile */
  if (denom == 0) {
    denom = 1;
  }
}
 
int f(int argc, const char *argv[]) {
  if (argc < 2) {
    return 1;
  }
  
  char *end = NULL;
  long temp = strtol(argv[1], &end, 10);
  
  if (end == argv[1] || 0 != *end ||
      ((LONG_MIN == temp || LONG_MAX == temp) && errno == ERANGE)) {
    /* Handle error */
    return 2;
  }
  
  denom = (sig_atomic_t)temp;
  signal(SIGFPE, sighandle);
 
  long result = 100 / (long)denom;
  return 0;
}

int main(void) {
  const char *argv_one[2];
  argv_one[0] = "program";
  argv_one[1] = "1";
  f(2, argv_one);
  const char *argv_two[2];
  argv_two[0] = "program";
  argv_two[1] = "0";
  f(2, argv_two);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c -val-args=" 0 1 2"
// C17: ?
// UB: ?
