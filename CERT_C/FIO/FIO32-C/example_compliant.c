#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
#ifdef O_NOFOLLOW
  #define OPEN_FLAGS O_NOFOLLOW | O_NONBLOCK
#else
  #define OPEN_FLAGS O_NONBLOCK
#endif
 
void func(const char *file_name) {
  struct stat orig_st;
  struct stat open_st;
  int fd;
  int flags;
 
  if ((lstat(file_name, &orig_st) != 0) ||
      (!S_ISREG(orig_st.st_mode))) {
    /* Handle error */
    return;
  }
 
  /* Race window */
 
  fd = open(file_name, OPEN_FLAGS | O_WRONLY);
  if (fd == -1) {
    /* Handle error */
    return;
  }
 
  if (fstat(fd, &open_st) != 0) {
    /* Handle error */
    close(fd);
    return;
  }
 
  if ((orig_st.st_mode != open_st.st_mode) ||
      (orig_st.st_ino  != open_st.st_ino) ||
      (orig_st.st_dev  != open_st.st_dev)) {
    /* The file was tampered with */
    close(fd);
    return;
  }
 
  /*
   * Optional: drop the O_NONBLOCK now that we are sure
   * this is a good file.
   */
  if ((flags = fcntl(fd, F_GETFL)) == -1) {
    /* Handle error */
    close(fd);
    return;
  }
 
  if (fcntl(fd, F_SETFL, flags & ~O_NONBLOCK) == -1) {
    /* Handle error */
    close(fd);
    return;
  }
 
  /* Operate on the file */
 
  if (close(fd) == -1) {
    /* Handle error */
    return;
  }
}

int main(void) {
  func("/dev/zero");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
