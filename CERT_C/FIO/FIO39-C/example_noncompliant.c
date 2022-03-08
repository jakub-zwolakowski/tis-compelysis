#include <stdio.h>
#include <string.h>
  
enum { BUFFERSIZE = 32 };
 
void initialize_data(char *data, size_t size) {
  memset(data, 42, size);
}
  
void func(const char *file_name) {
  char data[BUFFERSIZE];
  char append_data[BUFFERSIZE];
  FILE *file;
 
  file = fopen(file_name, "a+");
  if (file == NULL) {
    /* Handle error */
    return;
  }
  
  initialize_data(append_data, BUFFERSIZE);
 
  if (fwrite(append_data, 1, BUFFERSIZE, file) != BUFFERSIZE) {
    /* Handle error */
    goto close_file;
  }
  if (fread(data, 1, BUFFERSIZE, file) < BUFFERSIZE) {
    /* Handle there not being data */
    goto close_file;
  }
 
close_file:
  if (fclose(file) == EOF) {
    /* Handle error */
    return;
  }
}

int main(void) {
  func("example_file");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter -tis-config-load test_FIO39-C.json -tis-config-select 3
// C17: https://cigix.me/c17#7.21.5.3
// UB: "An output operation on an update stream is followed by an input operation without an intervening call to the fflush function or a file positioning function, or an input operation on an update stream is followed by an output operation with an intervening call to a file positioning function"
