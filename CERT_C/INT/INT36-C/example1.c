void func_noncompliant(unsigned int flag) {
  char c = 42;
  char *ptr = &c;
  /* ... */
  unsigned int number = (unsigned int)ptr;
  number = (number & 0x7fffff) | (flag << 23);
  ptr = (char *)number;
}

struct ptrflag {
  char *pointer;
  unsigned int flag : 9;
} ptrflag;

void func_compliant(unsigned int flag) {
  char *ptr;
  /* ... */
  ptrflag.pointer = ptr;
  ptrflag.flag = flag;
}

int main(void) {
  func_compliant(0);
  func_noncompliant(0);
  return 0;
}
