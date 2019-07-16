#include <stdio.h>
#define sizeof_int sizeof(int)
int method_A(int x);
int method_B(int x);
int method_C(int x);
int method_D(int x);
int main(void)
{
    int x,y;
    x = ~0;
    y = 0xFFFFFF00;
    printf("%#.8x\n", x);
    printf("A:%#.8x---%d\n", x, method_A(x));
    printf("A:%#.8x---%d\n", y, method_A(y));
    x = 0;
    printf("B:%#.8x---%d\n", x, method_B(x));
    x = ~0;
    y = 0x0F;
    printf("C:%#.8x---%d\n", x, method_C(x));
    printf("C:%#.8x---%d\n", y, method_C(y));

    x = 0x00FFFFFF;
    y = 0x0FFFFFFF;
    printf("D:%#.8x---%d\n", x, method_D(x));
    printf("D:%#.8x---%d\n", y, method_D(y));
}
//x的任何位都等于1
int method_A(int x)
{
    return !(~x);
}
//x的任何位都等于0
int method_B(int x)
{
    return !x;
}
//x的最低有效字节中的位都等于1
int method_C(int x)
{
    return !((x ^ 0xFF)<<((sizeof_int-1)<<3));
}
//x的最高有效字节中的位都等于0
int method_D(int x)
{
    return !(x >> ((sizeof_int-1)<<3));
}