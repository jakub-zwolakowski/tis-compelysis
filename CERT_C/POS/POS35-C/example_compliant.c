#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int f(const char *filename, const char *userbuf, const unsigned int userlen) {
  int fd = open(filename, O_RDWR|O_NOFOLLOW);
  if (fd == -1) {
    /* Handle error */
    return 1;
  }
  if (write(fd, userbuf, userlen) < userlen) {
    /* Handle error */
    return 2;
  }
  
  return 0;
}

int main(void) {
  char *userbuf = "I love you!";
  unsigned int userlen = strlen(userbuf);
  f("my_file", userbuf, userlen);
  f("my_file_link", userbuf, userlen);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
