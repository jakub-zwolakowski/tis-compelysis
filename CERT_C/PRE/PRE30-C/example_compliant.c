#define assign(ucn, val) ucn = val
  
void func(void) {
  int \u0401;
  /* ... */
  assign(\u0401, 4);
  /* ... */
}

int main(void) {
  func();
  return 0;
}

// DETECTED! BUT ALSO FALSE POSITIVE...
// CMD: tis-analyzer --interpreter test_PRE30-C_compliant.c
// C17: https://cigix.me/c17#5.1.1.2 bullet point 4
// UB: "Token concatenation produces a character sequence matching the syntax of a universal character name"
