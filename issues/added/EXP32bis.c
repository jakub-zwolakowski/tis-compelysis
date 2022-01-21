int main(void) {
    static int *ip;
    static volatile int i = 0;

    ip = &i;
    if (*ip != 0) { return 1; }
    return 0;
}
