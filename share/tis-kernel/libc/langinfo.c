/**************************************************************************/
/*                                                                        */
/*  This file is part of TrustInSoft Kernel.                              */
/*                                                                        */
/*    Copyright (C) 2016-2021 TrustInSoft                                 */
/*                                                                        */
/*  TrustInSoft Kernel is released under GPLv2                            */
/*                                                                        */
/**************************************************************************/

#include "langinfo.h"

#ifdef TIS_DETERMINISTIC_LIBC

#include "stdio.h"
#include "locale.h"

static const char *c_time[] = {
    "", "",
    // D_T_FMT
	"%a %b %e %T %Y",
    // D_FMT
	"%m/%d/%y",
    // T_FMT
	"%H:%M:%S",
    // T_FMT_AMPM
	"%I:%M:%S %p",
    // AM_STR, PM_STR
	"AM", "PM",
    // DAY_1 ... DAY_7
	"Sunday", "Monday", "Tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday",
    // ABDAY_1 ... ABDAY_7
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
    // MON_1 ... MON_12
	"January",   "February", "March",    "April",
	"May",       "June",     "July",     "August",
	"September", "October",  "November", "December",
    // ABMON_1 ... ABMON_12
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
    // ERA
    "",
    // ERA_D_FMT
	"%m/%d/%y",
    // ERA_D_T_FMT
	"%a %b %e %T %Y",
    // ERA_T_FMT
	"%H:%M:%S",
    // ALT_DIGITS
	"0123456789"
};

char *__tis_deterministic_nl_langinfo_l(nl_item item, locale_t loc)
{
    // loc is ignored, since locale dependent behavior is not yet implemented

    if (item >= D_T_FMT && item <= ALT_DIGITS) {
        return c_time[item];
    }

    //@ assert unimplemented_langinfo: \false;
    return 0;
}

char *nl_langinfo_l(nl_item item, locale_t loc) __attribute__((__weak__))
{
    printf("[TIS LIBC STUBS]: using deterministic nl_langinfo_l()\n");
    return __tis_deterministic_nl_langinfo_l(item, loc);
}

char *__tis_deterministic_nl_langinfo(nl_item item)
{
    // __tis_global_locale is used here only as an unused placeholder
    // "current locale" should probably be used instead
    return __tis_deterministic_nl_langinfo_l(item, __tis_global_locale);
}

char *nl_langinfo(nl_item item) __attribute__((__weak__))
{
    printf("[TIS LIBC STUBS]: using deterministic nl_langinfo()\n");
    return __tis_deterministic_nl_langinfo(item);
}

#endif // TIS_DETERMINISTIC_LIBC
