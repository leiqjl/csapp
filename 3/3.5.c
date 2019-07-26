#include <stdio.h>
void decode1(long *xp, long *yp, long *zp);
int main(void)
{
    long x = 3;
    long y = 4;
    long z = 5;
    printf("x=%ld, y=%ld, z=%ld\n", x, y, z);
    decode1(&x, &y, &z);
    printf("x=%ld, y=%ld, z=%ld\n", x, y, z);
    return 0;
}
/* xp in %rdi, yp in %rsi, zp in %rdx */
void decode1(long *xp, long *yp, long *zp)
{
    long a = *xp;
    long b = *yp;
    long c = *zp;
    *yp = a;
    *zp = b;
    *xp = c;
}