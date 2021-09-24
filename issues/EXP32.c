int main(void) {
    static volatile int **ipp;
    static int *ip;
    static volatile int i = 0;

    ipp = &ip;
    *ipp = &i;
    if (*ip != 0) { return 1; }
    return 0;
}
