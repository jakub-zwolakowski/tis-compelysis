#include <stdlib.h>
#include <string.h>
#include <stdio.h>
  
void func(void) {
  char *tmpvar;
  char *tempvar;
 
  tmpvar = getenv("TMP");
  if (!tmpvar) {
    /* Handle error */
    return;
  }
  tempvar = getenv("TEMP");
  if (!tempvar) {
    /* Handle error */
    return;
  }
  if (strcmp(tmpvar, tempvar) == 0) {
    printf("TMP and TEMP are the same.\n");
  } else {
    printf("TMP and TEMP are NOT the same.\n");
  }
}

int main(void) {
  setenv("TMP", "I love you", 1);
  setenv("TEMP", "I love you", 1);
  func();
  setenv("TEMP", "I hate you", 1);
  func();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
