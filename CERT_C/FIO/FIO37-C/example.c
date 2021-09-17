#include <stdio.h>
#include <string.h>
#include <unistd.h>
  
enum { BUFFER_SIZE = 1024 };
 
void func_compliant(FILE *file) {
  char buf[BUFFER_SIZE];
  char *p;
 
  if (fgets(buf, sizeof(buf), file)) {
    p = strchr(buf, '\n');
    if (p) {
      *p = '\0';
    }
  } else {
    /* Handle error */
    return;
  }
}

void func_noncompliant(FILE *file) {
  char buf[BUFFER_SIZE];
 
  if (fgets(buf, sizeof(buf), file) == NULL) {
    /* Handle error */
    return;
  }
  buf[strlen(buf) - 1] = '\0';
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
  // Test
  func_compliant(file);
  fclose(file);
  // Prepare a file with a leading zero
  file = fopen(FILENAME, "w");
  fwrite(three_zeroes, sizeof(char), 3, file);
  fclose(file);
  // Open the file for reading and use it as standard input
  file = fopen(FILENAME, "r");
  // Test
  func_noncompliant(file);
  fclose(file);
  return 0;
}

// DETECTED
// CMD: tis-analyzer --interpreter test_FIO37-C.c
// C17: https://cigix.me/c17#7.21.7.2
// UB: This is not an UB directly, but causes an out of bounds access UB.
