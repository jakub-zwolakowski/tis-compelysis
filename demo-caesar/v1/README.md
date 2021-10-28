# Examples
## main
### Test
```
Test 1: Shift with a negative input
Encrypt text 'People of Earth, your attention please'
Result: Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh
Decrypt text 'Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh'
Result: People of Earth, your attention please

Test 2: Shift with a positive input
Encrypt text 'People of Earth, your attention please'
Result: Wlvwsl vm Lhy{o3 €v|y h{{lu{pvu wslhzl
Decrypt text 'Wlvwsl vm Lhy{o3 €v|y h{{lu{pvu wslhzl'
Result: People of Earth, your attention please
```
### UBSan
```
Test 1: Shift with a negative input
Encrypt text 'People of Earth, your attention please'
Result: Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh
Decrypt text 'Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh'
Result: People of Earth, your attention please

Test 2: Shift with a positive input
Encrypt text 'People of Earth, your attention please'
Result: Wlvwsl vm Lhy{o3 €v|y h{{lu{pvu wslhzl
Decrypt text 'Wlvwsl vm Lhy{o3 €v|y h{{lu{pvu wslhzl'
Result: People of Earth, your attention please
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./main.out
==12345== 
Test 1: Shift with a negative input
Encrypt text 'People of Earth, your attention please'
Result: Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh
Decrypt text 'Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh'
Result: People of Earth, your attention please

Test 2: Shift with a positive input
Encrypt text 'People of Earth, your attention please'
Result: Wlvwsl vm Lhy{o3 €v|y h{{lu{pvu wslhzl
Decrypt text 'Wlvwsl vm Lhy{o3 €v|y h{{lu{pvu wslhzl'
Result: People of Earth, your attention please
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 5 allocs, 5 frees, 4,252 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
