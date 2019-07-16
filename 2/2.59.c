#include <stdio.h>

int main(void)
{
    int x = 0x89ABCDEF;
    int y = 0x765432EF;
    int z = (x & 0xFF) | (y & ~0xFF);
    printf("%.8x", z);
    return 0;
}
