#include <stdlib.h>
#include <string.h>
#include <wchar.h>

void f(void) {
  wchar_t wide_str1[] = L"0123456789";
  wchar_t *wide_str2 = (wchar_t *)malloc(
    (wcslen(wide_str1) + 1) * sizeof(wchar_t));
  if (wide_str2 == NULL) {
    /* Handle error */
    return;
  }
  /* ... */
  wide_str2[3] = wide_str2[0];

  free(wide_str2);
  wide_str2 = NULL;
}

int main(void) {
  f();
  return 0;
}
