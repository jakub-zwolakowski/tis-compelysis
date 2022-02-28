#include <pthread.h>
#include <inttypes.h>
#include <sys/socket.h>

int sockets[2];

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

void *thread_foo(void *ptr) {
  uint32_t num;
  int result;
  int sock;

  /* sock is a connected TCP socket */
  sock = sockets[0];

  if ((result = pthread_mutex_lock(&mutex)) != 0) {
    /* Handle Error */
    return NULL;
  }

  if ((result = recv(sock, (void *)&num, sizeof(uint32_t), 0)) < 0) {
    /* Handle Error */
    return NULL;
  }

  /* ... */

  if ((result = pthread_mutex_unlock(&mutex)) != 0) {
    /* Handle Error */
    return NULL;
  }
  return NULL;
}

void *thread_bar(void *ptr) {
  uint32_t num;
  int result;
  int sock;

  /* sock is a connected TCP socket */
  sock = sockets[0];

  if ((result = pthread_mutex_lock(&mutex)) != 0) {
    /* Handle Error */
    return NULL;
  }

  if ((result = send(sock, (void *)&num, sizeof(uint32_t), 0)) < 0) {
    /* Handle Error */
    return NULL;
  }

  /* ... */

  if ((result = pthread_mutex_unlock(&mutex)) != 0) {
    /* Handle Error */
    return NULL;
  }
  return NULL;
}

int main() {
  socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);

  pthread_t thread[2];
  int result;

  if ((result = pthread_mutexattr_settype(
      &attr, PTHREAD_MUTEX_ERRORCHECK)) != 0) {
    /* Handle Error */
    return 1;
  }

  if ((result = pthread_mutex_init(&mutex, &attr)) != 0) {
    /* Handle Error */
    return 2;
  }

  if (pthread_create(&thread[0], NULL, & thread_foo, NULL) != 0) {
    /* Handle Error */
    return 3;
  }
  if (pthread_create(&thread[1], NULL, & thread_bar, NULL) != 0) {
    /* Handle Error */
    return 4;
  }

  /* ... */

  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);

  if ((result = pthread_mutex_destroy(&mutex)) != 0) {
    /* Handle Error */
    return 5;
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_noncompliant.c
// C17: ?
// UB: ?
