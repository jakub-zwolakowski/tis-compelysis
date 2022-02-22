#include <unistd.h>
#include <stdio.h>


enum { BUFFERSIZE = 1024 };

int main(void) {
  char buf[BUFFERSIZE];
  ssize_t len = readlink("/usr/bin/dupa", buf, sizeof(buf)-1);
  printf("%zd\n", len);

  if (len != -1) {
    buf[len] = '\0';
    printf("%s\n", buf);
  }
  else {
    /* handle error condition */
    return 1;
  }

  return 0;
}

// DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
