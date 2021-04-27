#include <stddef.h>

void copy_noncompliant(size_t n, char src[n], char dest[n]) {
   size_t i;

   for (i = 0; src[i] && (i < n); ++i) {
     dest[i] = src[i];
   }
   dest[i] = '\0';
}

void copy_compliant(size_t n, char src[n], char dest[n]) {
   size_t i;

   for (i = 0; src[i] && (i < n - 1); ++i) {
     dest[i] = src[i];
   }
   dest[i] = '\0';
}

void main(void) {
   char src[5] = "12345";
   char dest[5];
   copy_compliant(5, src, dest);
   copy_noncompliant(5, src, dest);
}
