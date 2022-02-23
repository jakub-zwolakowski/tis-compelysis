#include <unistd.h>

int main(void) {  
  /*  Drop superuser privileges in correct order */
   
  if (setgid(getgid()) == -1) {
    /* handle error condition */
    return 1;
  }
  if (setuid(getuid()) == -1) {
    /* handle error condition */
    return 2;
  }
   
  /*
   * Not possible to regain group privileges due to correct relinquishment order
   */
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
