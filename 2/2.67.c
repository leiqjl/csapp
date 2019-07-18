#include <stdio.h>
int int_size_is_32();
int main(void)
{
    printf("%d\n", int_size_is_32());
    return 0;
}

int int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond = set_msb << 1;
    return set_msb && !beyond;
}

int int_size_is_32_in_16()
{
    int set_msb = 1 << 15 << 15;
    int beyond = set_msb << 1;
    return set_msb && !beyond;
}