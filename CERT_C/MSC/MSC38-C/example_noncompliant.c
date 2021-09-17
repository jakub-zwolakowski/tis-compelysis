#include <assert.h>

typedef void (*handler_type)(int);

void execute_handler(handler_type handler, int value) {
  handler(value);
}

void func(int e) {
  execute_handler(&(assert), e < 0);
} 

int main(void) {
  func(42);
  return 0;
}

// DETECTED!
// CMD: tis-analyzer --interpreter test_MSC38-C_noncompliant.c
// C11: https://cigix.me/c17#7.2p2
// UB: "The macro definition of assert is suppressed in order to access an actual function"
