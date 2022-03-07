#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int f(const char *filename, const char *userbuf, const unsigned int userlen) {
  struct stat lstat_info;
  int fd;
  /* ... */
  if (lstat(filename, &lstat_info) == -1) {
    return 1;
  }
  
  if (!S_ISLNK(lstat_info.st_mode)) {
    fd = open(filename, O_RDWR);
    if (fd == -1) {
      return 2;
    }
    if (write(fd, userbuf, userlen) < userlen) {
      return 3;
    }
    close(fd);
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
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
