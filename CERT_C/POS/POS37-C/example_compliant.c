#include <unistd.h>

#define need_more_privileges 1

int main(void) {  
  /* Store the privileged ID for later verification */
  uid_t privid = geteuid();
  
  /* Code intended to run with elevated privileges   */
  
  /* Temporarily drop privileges */
  if (seteuid(getuid()) != 0) {
    /* Handle error */
    return 1;
  }
  
  /* Code intended to run with lower privileges  */
  
  if (need_more_privileges) {
    /* Restore Privileges */
    if (seteuid(privid) != 0) {
      /* Handle error */
      return 2;
    }
  
    /* Code intended to run with elevated privileges   */
  }
  
  /* ... */
  
  /* Restore privileges if needed */
  if (geteuid() != privid) {
    if (seteuid(privid) != 0) {
      /* Handle error */
      return 3;
    }
  }
  
  /* Permanently drop privileges */
  if (setuid(getuid()) != 0) {
    /* Handle error */
    return 4;
  }
  
  if (setuid(0) != -1) {
    /* Privileges can be restored, handle error */
    return 5;
  }
  
  /*
  * Code intended to run with lower privileges;
  * attacker cannot regain elevated privileges
  */

  /* Try to regain privileges. */
  if (need_more_privileges) {
    /* Restore Privileges */
    if (seteuid(privid) != 0) {
      /* Handle error */
      return 6;
    }
  
    /* Code intended to run with elevated privileges   */
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
