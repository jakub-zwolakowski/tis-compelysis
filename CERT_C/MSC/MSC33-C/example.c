#include <stdio.h>
#include <time.h>

void func(struct tm *time_tm)
{
    char *time = asctime(time_tm);
    /* ... */
    printf("Time: %s", time);
}

void main(void) {
  struct tm time_tm = {
    .tm_sec = 42,
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
}

// NOT FINISHED
