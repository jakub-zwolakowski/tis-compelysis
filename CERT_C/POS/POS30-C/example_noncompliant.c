#include <unistd.h>
#include <stdio.h>

int main(void) {
  char buf[1024];
  ssize_t len = readlink("/usr/bin/dupa", buf, sizeof(buf));
  printf("%zd\n", len);
  buf[len] = '\0';
  printf("%s\n", buf);
  return 0;
}

// DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
