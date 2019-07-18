#include <stdio.h>
#define sizeof_int sizeof(int)
int fits_bits(int x, int n);
int main(void)
{
    printf("%d\n", fits_bits(0, 2));
    printf("%d\n", fits_bits(0xFFFFFFF0, 5));
    printf("%d\n", fits_bits(0xFF0FFFF0, 5));
    printf("%d\n", fits_bits(0x000000F0, 9));
    
}

/**
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n)
{
    unsigned w = sizeof_int << (1 << 3);

    return x == (x << (w-n) >> (w-n));
}