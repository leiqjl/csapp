#include <stdio.h>
#define sizeof_int sizeof(int)
int lower_one_mask(int n);
int main(void)
{
    printf("%#.8x\n", lower_one_mask(1));
    printf("%#.8x\n", lower_one_mask(6));
    printf("%#.8x\n", lower_one_mask(17));
    printf("%#.8x\n", lower_one_mask(32));
}

/**
 * Mask with least signficant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Asume 1 <= n <= w
 */
int lower_one_mask(int n)
{
    unsigned x = 1 << (n-1);
    return x | (x-1);
}