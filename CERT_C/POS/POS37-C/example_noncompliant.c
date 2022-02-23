#include <unistd.h>

#define need_more_privileges 1

int main(void) {  
  /* Code intended to run with elevated privileges */
  
  /* Temporarily drop privileges */
  if (seteuid(getuid()) != 0) {
    /* Handle error */
    return 1;
  }
  
  /* Code intended to run with lower privileges */

  if (need_more_privileges) {
    /* Restore privileges */
    if (seteuid(0) != 0) {
      /* Handle error */
      return 2;
    }
  
    /* Code intended to run with elevated privileges */
  }
  
  /* ... */
  
  /* Permanently drop privileges */
  if (setuid(getuid()) != 0) {
    /* Handle error */
    return 3;
  }
  
  /*
  * Code intended to run with lower privileges,
  * but if privilege relinquishment failed,
  * attacker can regain elevated privileges!
  */

  /* Try to regain privileges. */
  if (need_more_privileges) {
    /* Restore privileges */
    if (seteuid(0) != 0) {
      /* Handle error */
      return 4;
    }
  
    /* Code intended to run with elevated privileges */
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
