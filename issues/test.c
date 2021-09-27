#include <stdio.h>
#include <time.h>

/*
https://cigix.me/c17#7.27.1.p4

The tm structure shall contain at least the following members, in any order. The semantics of the
members and their normal ranges are expressed in the comments.

int tm_sec;   // seconds after the minute -- [0, 60]
int tm_min;   // minutes after the hour -- [0, 59]
int tm_hour;  // hours since midnight -- [0, 23]
int tm_mday;  // day of the month -- [1, 31]
int tm_mon;   // months since January -- [0, 11]
int tm_year;  // years since 1900

int tm_wday;  // days since Sunday -- [0, 6]
int tm_yday;  // days since January 1 -- [0, 365]
int tm_isdst; // Daylight Saving Time flag

The value of tm_isdst is positive if Daylight Saving Time is in effect, zero if Daylight Saving Time
is not in effect, and negative if the information is not available.

NOTE: The range [0, 60] for tm_sec allows for a positive leap second.
NOTE (Kuba): Also, from the following, we should add: // tm_year -- [-900, 8099]

7.27.3.1 The asctime function
paragraph3 (https://cigix.me/c17#7.27.3.1.p3)

If any of the members of the broken-down time contain values that are outside their normal
ranges, the behavior of the asctime function is undefined. Likewise, if the calculated year
exceeds four digits or is less than the year 1000, the behavior is undefined.
*/

// char *asctime(const struct tm *timeptr) {
//     static const char wday_name[7][3] = {
//           "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
//     };
//     static const char mon_name[12][3] = {
//           "Jan", "Feb", "Mar", "Apr", "May", "Jun",
//           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
//     };
//     static char result[26];
  
//     sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
//           wday_name[timeptr->tm_wday],
//           mon_name[timeptr->tm_mon],
//           timeptr->tm_mday, timeptr->tm_hour,
//           timeptr->tm_min, timeptr->tm_sec,
//           1900 + timeptr->tm_year);
//     return result;
// }

int main(void) {
  struct tm time_tm = {
    .tm_sec = 99,
    .tm_min = 99,
    .tm_hour = 99,
    .tm_mday = 19,
    .tm_mon = 3,
    .tm_year = 86,
    .tm_wday = 6,
    .tm_yday = 0,
    .tm_isdst = 0
  };
  char *time = asctime(&time_tm);
  printf("Time: %s", time);
  return 0;
}

// tis-analyzer -cpp-extra-args=" -DTIS_DETERMINISTIC_LIBC" --interpreter test.c $TIS_HOME/share/tis-kernel/libc/langinfo.c