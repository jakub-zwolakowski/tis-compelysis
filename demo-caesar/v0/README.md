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
### gcc
```
```
### clang
```
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
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_encrypt (caesar.c:21)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_encrypt (caesar.c:25)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 5 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1643)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: gen_test (main.c:11)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: mempcpy (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1258)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1643)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: gen_test (main.c:11)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: mempcpy (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1258)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1643)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: gen_test (main.c:11)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 1 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1643)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: gen_test (main.c:13)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:35)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:37)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:37)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:37)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_decrypt (caesar.c:33)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:41)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 5 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_decrypt (caesar.c:33)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1643)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: gen_test (main.c:15)
==12345==    by 0x424242424242: main (main.c:26)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_decrypt (caesar.c:33)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:26)
==12345== 
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_encrypt (caesar.c:21)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:28)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:28)
==12345== 
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_encrypt (caesar.c:25)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:28)
==12345==  Address 0x424242424242 is 5 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:28)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:35)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:28)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:28)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:37)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:28)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:28)
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:37)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:28)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_encrypt (caesar.c:17)
==12345==    by 0x424242424242: gen_test (main.c:10)
==12345==    by 0x424242424242: main (main.c:28)
==12345== 
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:37)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:28)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_decrypt (caesar.c:33)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:28)
==12345== 
==12345== Invalid write of size 1
==12345==    at 0x424242424242: caesar_decrypt (caesar.c:41)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:28)
==12345==  Address 0x424242424242 is 5 bytes after a block of size 33 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: caesar_decrypt (caesar.c:33)
==12345==    by 0x424242424242: gen_test (main.c:14)
==12345==    by 0x424242424242: main (main.c:28)
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
==12345==   total heap usage: 5 allocs, 5 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 122 errors from 19 contexts (suppressed: 0 from 0)
```
