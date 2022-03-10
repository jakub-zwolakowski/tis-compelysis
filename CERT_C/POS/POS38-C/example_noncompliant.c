#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define filename "my_file"

int main(void) {
  char c;
  pid_t pid;
  
  int fd = open(filename, O_RDWR);
  if (fd == -1) {
    /* Handle error */
    return 1;
  }
  if (read(fd, &c, 1) < 0) {
    close(fd);
    return 2;
  }
  printf("root process:%c\n",c);
  
  pid = fork();
  if (pid == -1) {
    /* Handle error */
    return 3;
  }
  
  if (pid == 0) { /*child*/
    if (read(fd, &c, 1) < 0) {
      close(fd);
      return 4;
    }
    printf("child:%c\n",c);
  }
  else { /*parent*/
    if (read(fd, &c, 1) < 0) {
      close(fd);
      return 5;
    }
    printf("parent:%c\n",c);
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
