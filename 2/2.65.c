#include <stdio.h>
int odd_ones(unsigned x);
int main(void)
{
    unsigned x = ~0;
    printf("%d\n", odd_ones(x));
    printf("%d\n", odd_ones(0x101));
    printf("%d\n", odd_ones(0x111));
    printf("%d\n", odd_ones(0x11110000));
    printf("%d\n", odd_ones(0x11111000));
    return 0;
}
//Return 1 when x contains an odd number of 1s; 0 otherwise.
int odd_ones(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}