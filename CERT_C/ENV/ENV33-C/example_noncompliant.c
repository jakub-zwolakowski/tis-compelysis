#include <stdio.h>
#include <stdlib.h>
  
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
enum { BUFFERSIZE = 512 };
 
void func(const char *input) {
  char cmdbuf[BUFFERSIZE];
  int len_wanted = snprintf(cmdbuf, BUFFERSIZE,
                            "any_cmd '%s'", input);
  if (len_wanted >= BUFFERSIZE) {
    /* Handle error */
    return;
  } else if (len_wanted < 0) {
    /* Handle error */
    return;
  } else if (system(cmdbuf) == -1) {
    /* Handle error */
    return;
  }
}

int main(void) {
  func("happy'; echo 'attacker");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
