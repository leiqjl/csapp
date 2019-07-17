#include <stdio.h>
#define sizeof_int sizeof(int)
unsigned rotate_left(unsigned x, int n);
int main(void)
{
    printf("%#.8x\n", rotate_left(0x12345678, 0));
    printf("%#.8x\n", rotate_left(0x12345678, 4));
    printf("%#.8x\n", rotate_left(0x12345678, 20));
    printf("%#.8x\n", rotate_left(0x12345678, 28));
}

/**
 * Do rotating left shift. Assume 0 <= n < w
 * Examples when x = 0x12345678 and w =32:
 *     n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n)
{
    unsigned w = sizeof_int << (1 << 3);
    return x << n | x >> (w - n);
}