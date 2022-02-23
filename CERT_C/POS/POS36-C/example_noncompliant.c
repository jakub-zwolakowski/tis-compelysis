#include <unistd.h>

int main(void) {  
  /* Drop superuser privileges in incorrect order */
   
  if (setuid(getuid()) == -1) {
    /* handle error condition */
    return 1;
  }
  if (setgid(getgid()) == -1) {
    /* handle error condition */
    return 2;
  }
   
  /* It is still possible to regain group privileges due to
   * incorrect relinquishment order */
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
