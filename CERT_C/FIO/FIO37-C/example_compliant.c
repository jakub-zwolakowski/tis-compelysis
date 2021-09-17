#include <stdio.h>
#include <string.h>
#include <unistd.h>
  
enum { BUFFER_SIZE = 1024 };
 
void func(void) {
  char buf[BUFFER_SIZE];
  char *p;
 
  if (fgets(buf, sizeof(buf), stdin)) {
    p = strchr(buf, '\n');
    if (p) {
      *p = '\0';
    }
  } else {
    /* Handle error */
    return;
  }
}

#define FILENAME "three_zeros"
char three_zeroes[] = { 0, 0, 0 };

int main(void) {
  FILE *file;
  // Prepare a file with a leading zero
  file = fopen(FILENAME, "w");
  fwrite(three_zeroes, sizeof(char), 3, file);
  fclose(file);
  // Open the file for reading and use it as standard input
  file = fopen(FILENAME, "r");
  dup2(fileno(file), STDIN_FILENO);
  // Test
  func();
  return 0;
}

// DETECTED
// CMD: tis-analyzer --interpreter test_FIO37-C_compliant.c
// C17: https://cigix.me/c17#7.21.7.2
// UB: This is not an UB directly, but causes an out of bounds access UB.
