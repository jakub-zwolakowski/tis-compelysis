#include <string.h>
#include <wchar.h>

static const char str[] = "Hello world";
static const wchar_t w_str[] = L"Hello world";

void f_noncompliant(void) {
  char buffer[32];
  wchar_t w_buffer[32];
  memcpy(buffer, str, sizeof(str)); /* Compliant */
  wmemcpy(w_buffer, w_str, sizeof(w_str)); /* Noncompliant */
}

void f_compliant(void) {
  char buffer[32];
  wchar_t w_buffer[32];
  memcpy(buffer, str, strlen(str) + 1);
  wmemcpy(w_buffer, w_str, wcslen(w_str) + 1);
}

void main(void) {
  f_compliant();
  f_noncompliant();
}
