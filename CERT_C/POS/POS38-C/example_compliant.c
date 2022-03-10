#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define filename "my_file"

int main(void) {
  char c;

  pid_t pid;

  /* Open file and remember file status  */
  struct stat orig_st;
  if (lstat( filename, &orig_st) != 0) {
    /* handle error */
    return 1;
  }
  int fd = open(filename, O_RDWR);
  if (fd == -1) {
    /* Handle error */
    return 2;
  }
  struct stat new_st;
  if (fstat(fd, &new_st) != 0) {
    /* handle error */
    return 3;
  }
  if (orig_st.st_dev != new_st.st_dev ||
      orig_st.st_ino != new_st.st_ino) {
    /* file was tampered with while opening */
  }

  /* file is good, operate on fd */

  if (read(fd, &c, 1) < 0) {
    close(fd);
    return 4;
  }
  printf("root process:%c\n",c);

  pid = fork();
  if (pid == -1) {
    /* Handle error */
    return 5;
  }

  if (pid == 0){ /*child*/
    close(fd);

    /* Reopen file, creating new file descriptor */
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
      /* Handle error */
      return 6;
    }
    if (fstat(fd, &new_st) != 0) {
      /* handle error */
      return 7;
    }
    if (orig_st.st_dev != new_st.st_dev ||
        orig_st.st_ino != new_st.st_ino) {
      /* file was tampered with between opens */
      return 8;
    }

    if (read(fd, &c, 1) < 0) {
      close(fd);
      return 9;
    }
    if (read(fd, &c, 1) < 0) {
      close(fd);
      return 10;
    }

    printf("child:%c\n", c);
    close(fd);
  }

  else { /*parent*/
    if (read(fd, &c, 1) < 0) {
      close(fd);
      return 11;
    }

    printf("parent:%c\n", c);
    close(fd);
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
