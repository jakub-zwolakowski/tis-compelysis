#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
 
int f(int argc, const char *argv[]) {
  if (argc < 2) {
    return 1;
  }
  
  char *end = NULL;
  long denom = strtol(argv[1], &end, 10);
  
  if (end == argv[1] || 0 != *end ||
      ((LONG_MIN == denom || LONG_MAX == denom) && errno == ERANGE)) {
    /* Handle error */
    return 1;
  }
  
  long result = 100 / denom;
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
// CMD: tis-analyzer --interpreter example_compliant.c -val-args=" 0 1 2"
// C17: ?
// UB: ?
