#include <stdio.h>

enum { BUFFER_SIZE = 1024 };

void func_noncompliant(FILE *file) {
  char buf[BUFFER_SIZE];
 
  if (fgets(buf, sizeof(buf), file) == NULL) {
    /* Set error flag and continue */
  }
  printf("%c", buf[0]);
}

void func_compliant(FILE *file) {
  char buf[BUFFER_SIZE];
 
  if (fgets(buf, sizeof(buf), file) == NULL) {
    /* Set error flag and continue */
    *buf = '\0';
  }
  printf("%c", buf[0]);
}

#define FILENAME "empty_file"

int main(void) {
  FILE *file;
  // Prepare an empty file
  file = fopen(FILENAME, "w");
  fclose(file);
  // Open the empty file for reading
  file = fopen(FILENAME, "r");
  // Test compliant
  func_compliant(file);
  // Close the file
  fclose(file);
  // Prepare an empty file
  file = fopen(FILENAME, "w");
  fclose(file);
  // Open the empty file for reading
  file = fopen(FILENAME, "r");
  // Test noncompliant
  func_noncompliant(file);
  // Close the file
  fclose(file);
  return 0;
}

// DETECTED
// CMD: tis-analyzer --interpreter test_FIO40-C.c
// C17: https://cigix.me/c17#7.21.7.2p3
// UB: "The contents of the array supplied in a call to the fgets, gets, or fgetws function are used after a read error occurred"
