#include <inttypes.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <strings.h>

static int sock = 0;

int main(void) {
  /* Socket creation */
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in servaddr;

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(8000);
  inet_pton(AF_INET, "149.202.170.74", &servaddr.sin_addr);

  /* Connect request to listening socket of server */ 
  int ret_val = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  if (ret_val == -1) {
    /* Handle error */
    return 1;
  }

  /* sock is a connected TCP socket */
 
  uint32_t num;
  
  if (recv(sock, (void *)&num, sizeof(uint32_t), 0) < (int)sizeof(uint32_t)) {
    /* Handle error */
    return 2;
  }
  
  num = ntohl(num);
  printf("We recieved %u from the network!\n", (unsigned int)num);

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
