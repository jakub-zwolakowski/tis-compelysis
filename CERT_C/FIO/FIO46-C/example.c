#include <stdio.h>
#include <unistd.h>
  
int close_stdout_noncompliant(void) {
  printf("noncompliant\n");
  if (fclose(stdout) == EOF) {
    return -1;
  }
  
  printf("noncompliant: stdout successfully closed.\n");
  return 0;
}

int close_stdout_compliant(void) {
  printf("compliant\n");
  if (fclose(stdout) == EOF) {
    return -1;
  }
 
  fputs("compliant: stdout successfully closed.\n", stderr);
  return 0;
}

int main(void) {
  int saved_stdout = dup(STDOUT_FILENO);
  close_stdout_compliant();
  dup2(saved_stdout, STDOUT_FILENO);
  freopen("/dev/stdout", "a", stdout);
  close_stdout_noncompliant();
  return 0;
}

// NOT WORKING IN A SINGLE FILE!!!
// NOT DETECTED
// CMD: tis-analyzer --interpreter test_FIO46-C.c
// C17: https://cigix.me/c17#6.2.4
// UB: "The value of a pointer to a FILE object is used after the associated file is closed"
