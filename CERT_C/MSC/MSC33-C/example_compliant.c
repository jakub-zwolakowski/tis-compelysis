#include <stdio.h>
#include <time.h>

enum { maxsize = 26 };
  
void func(struct tm *time) {
  char s[maxsize];
  /* Current time representation for locale */
  const char *format = "%c";
 
  size_t size = strftime(s, maxsize, format, time); // This is an UB too actually...
  
  printf("Time: %s", s);
}

int main(void) {
  struct tm time_tm = {
    .tm_sec = 99,
    .tm_min = 42,
    .tm_hour = 6,
    .tm_mday = 25,
    .tm_mon = 2,
    .tm_year = 89,
    .tm_wday = 6,
    .tm_yday = 0,
    .tm_isdst = 0
  };
  func(&time_tm);
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -cpp-extra-args=" -DTIS_DETERMINISTIC_LIBC" --interpreter example_compliant.c $TIS_HOME/share/tis-kernel/libc/langinfo.c
// C11: https://cigix.me/c17#7.27.3.1.p3 and https://cigix.me/c17#7.27.1.p4
// UB: "At least one member of the broken-down time passed to asctime contains a value outside its normal range, or the calculated year exceeds four digits or is less than the year 1000"
