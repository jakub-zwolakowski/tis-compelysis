#include <inttypes.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <pthread.h>

int sockets[2];

void *thread_recv(void *arg) {
  int sock = sockets[0];

  /* sock is a connected TCP socket */

  uint32_t num;

  if (recv(sock, (void *)&num, sizeof(uint32_t), 0) < (int)sizeof(uint32_t)) {
    /* Handle error */
  }

  num = ntohl(num);
  printf("We recieved %u from the network!\n", (unsigned int)num);
  return NULL;
}

void *thread_send(void *arg) {
  int sock = sockets[1];

  /* sock is a connected TCP socket */
  
  uint32_t num = 42;
  printf("We are sending %u to the network!\n", (unsigned int)num);

  /* converting to network byte ordering */
  num = htonl(num);
  
  if (send(sock, (void *)&num, sizeof(uint32_t), 0) < (int)sizeof(uint32_t)) {
    /* Handle error */
    return NULL;
  }

  
  return NULL;
}

int main(void) {
  socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);
  pthread_t thread[2];

  pthread_create(&thread[0], NULL, &thread_recv, NULL);
  pthread_create(&thread[1], NULL, &thread_send, NULL);
  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread example_compliant.c
// C17: ?
// UB: ?
