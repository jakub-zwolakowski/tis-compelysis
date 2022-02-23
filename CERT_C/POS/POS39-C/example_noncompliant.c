#include <inttypes.h>
#include <sys/socket.h>
#include <stdio.h>

static int sock = 0;

int main(void) {
  /* sock is a connected TCP socket */
  
  uint32_t num;
  
  if (recv(sock, (void *)&num, sizeof(uint32_t), 0) < (int)sizeof(uint32_t)) {
    /* Handle error */
    return 1;
  }
  
  printf("We received %u from the network!\n", (unsigned int)num);

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
