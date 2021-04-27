int f_noncompliant(int a, int b) {
  if (a = b) {
    return 0;
  }
  return 1;
}

int f_compliant(int a, int b) {
  if (a == b) {
    return 0;
  }
  return 1;
}

void main(void) {
  int a = 13;
  int b = 42;
  f_noncompliant(a, b);
  f_compliant(a, b);
}
