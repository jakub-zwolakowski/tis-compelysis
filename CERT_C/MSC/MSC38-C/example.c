#include <assert.h>
  
typedef void (*handler_type)(int);
  
void execute_handler(handler_type handler, int value) {
  handler(value);
}
  
void func_noncompliant(int e) {
  execute_handler(&(assert), e < 0);
} 

static void assert_handler(int value) {
  assert(value);
}
  
void func_compliant(int e) {
  execute_handler(&assert_handler, e < 0);
}

int main(void) {
  func_noncompliant(42);
  func_compliant(42);
  return 0;
}

// DETECTED!
// CMD: tis-analyzer --interpreter test_MSC38-C.c
// C11: https://cigix.me/c17#7.2p2
// UB: "The macro definition of assert is suppressed in order to access an actual function"
