#include <stdio.h>
int any_odd_one(unsigned x);
int main(void)
{
    unsigned x = ~0;
    printf("%d\n", any_odd_one(x));
    printf("%d\n", any_odd_one(0x55));
    printf("%d\n", any_odd_one(0x505));
    printf("%d\n", any_odd_one(0xAAA));
    printf("%d\n", any_odd_one(0x1));
    printf("%d\n", any_odd_one(0x3));
    return 0;
}

//Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w = 32;
int any_odd_one(unsigned x)
{
    //0101……
    unsigned t = 0x55555555;
    return !!(t & x);
}