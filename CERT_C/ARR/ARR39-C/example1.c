enum { INTBUFSIZE = 80 };

int getdata(void) {
  return 42;
}

int buf[INTBUFSIZE];

void f_noncompliant(void) {
  int *buf_ptr = buf;

  while (buf_ptr < (buf + sizeof(buf))) {
    *buf_ptr++ = getdata();
  }
}

void f_compliant(void) {
  int *buf_ptr = buf;

  while (buf_ptr < (buf + INTBUFSIZE)) {
    *buf_ptr++ = getdata();
  }
}

void main(void) {
  f_compliant();
  f_noncompliant();
}
