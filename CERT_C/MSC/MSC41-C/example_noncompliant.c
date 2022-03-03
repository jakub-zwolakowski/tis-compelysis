#include <stdio.h>

/* Returns nonzero if authenticated */
extern int authenticate(const char* code);
 
int main() {
  if (!authenticate("correct code")) {
    printf("Authentication error\n");
    return -1;
  }
 
  printf("Authentication successful\n");
  // ...Work with system...
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c example_auth.c
// C17: ?
// UB: ?
