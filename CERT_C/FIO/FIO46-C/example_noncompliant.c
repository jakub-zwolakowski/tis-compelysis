#include <stdio.h>
#include <unistd.h>

int close_stdout(void) {
  if (fclose(stdout) == EOF) {
    return -1;
  }
  
  printf("stdout successfully closed.\n");
  return 0;
}

int main(void) {
  close_stdout();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_FIO46-C_noncompliant.c
// C17: https://cigix.me/c17#6.2.4
// UB: "The value of a pointer to a FILE object is used after the associated file is closed"
