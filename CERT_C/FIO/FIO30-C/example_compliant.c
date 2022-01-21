#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
void incorrect_password(const char *user) {
  int ret;
  /* User names are restricted to 256 or fewer characters */
  static const char msg_format[] = "%s cannot be authenticated.\n";
  size_t len = strlen(user) + sizeof(msg_format);
  char *msg = (char *)malloc(len);
  if (msg == NULL) {
    /* Handle error */
    return;
  }
  ret = snprintf(msg, len, msg_format, user);
  if (ret < 0) { 
    /* Handle error */ 
    return;
  } else if (ret >= len) { 
    /* Handle truncated output */ 
    return;
  }
  fputs(msg, stderr);
  free(msg);
}

int main(void) {
  const char user1[] = "password";
  incorrect_password(user1);
  const char user2[] = "password %d";
  incorrect_password(user2);
  return 0;
}

// DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: https://cigix.me/c17#7.21.6.1.p2
// UB: There are insufficient arguments for the format in a call to one of the formatted input/output functions, or an argument does not have an appropriate type
