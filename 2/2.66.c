#include <stdio.h>
int leftmost_one(unsigned x);
int main(void)
{
    unsigned x = ~0;
    printf("%.8x\n", leftmost_one(x));
    printf("%.8x\n", leftmost_one(0));
    printf("%.8x\n", leftmost_one(0xFF00));
    printf("%.8x\n", leftmost_one(0x6600));
    printf("%.8x\n", leftmost_one(0x00110000));
    printf("%.8x\n", leftmost_one(0x01100110));
    printf("%.8x\n", leftmost_one(0x80000000));
    return 0;
}
/**
 * Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 */
int leftmost_one(unsigned x)
{

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + (x && 1);
}