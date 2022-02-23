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
  read(fd, &c, 1);
  printf("root process:%c\n",c);
  
  pid = fork();
  if (pid == -1) {
    /* Handle error */
    return 2;
  }
  
  if (pid == 0) { /*child*/
    read(fd, &c, 1);
    printf("child:%c\n",c);
  }
  else { /*parent*/
    read(fd, &c, 1);
    printf("parent:%c\n",c);
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
