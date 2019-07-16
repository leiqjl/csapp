#include <stdio.h>
unsigned replace_byte(unsigned x, int i, unsigned char b);

int main(void)
{

    unsigned x = 0x12345678;
    printf("%#.8x\n", x);
    printf("%#.8x\n", replace_byte(x, 2, 0xAB));
    printf("%#.8x\n", replace_byte(x, 0, 0xAB));
}

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    return (x & ~(0xFF << (i << 3))) | b << (i << 3);
}