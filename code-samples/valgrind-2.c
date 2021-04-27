#include <stdlib.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    x[0] = 0;
} // problem 2: memory leak -- x not freed

int main(void)
{
    f();
#ifdef __TRUSTINSOFT_ANALYZER__
    tis_check_leak();
#endif
    return 0;
}