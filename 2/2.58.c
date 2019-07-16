#include <stdio.h>

int is_little_endian();

int main(void)
{

    printf("%d\n", is_little_endian());

    int x = 0x89ABCDEF;
    int y = 0x76643211;
    printf("%x\n", (x & 0xFF) | (y&~0xFF));
}

int is_little_endian(){
    int a = 1;
    return *((char*)&a);
}