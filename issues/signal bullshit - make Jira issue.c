#include <signal.h>

void term_handler(int signum) {}
int main(void) {
  return signal(SIGTERM, term_handler) == SIG_ERR;
}
