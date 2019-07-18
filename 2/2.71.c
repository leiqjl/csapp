#include <stdio.h>
#define sizeof_int sizeof(int)
typedef unsigned packed_t;
int xbyte_wrong(packed_t word, int bytenum);
int xbyte(packed_t word, int bytenum);
int main(void)
{
    printf("%d\n", xbyte(0xFFFFFF11, 0));
    printf("%d\n", xbyte(0xFFFFFF11, 1));
    printf("%d\n", xbyte(0xFFA0FF11, 2));
    printf("%d\n", xbyte(0xAABBCCDD, 1));
    printf("%d\n", xbyte(0x00112233, 2));
}
//A：无法正确展示负数
int xbyte_wrong(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) && 0xFF;
}
//B
int xbyte(packed_t word, int bytenum)
{
    int shift_left = (sizeof_int - 1 - bytenum) << 3;
    int shift_right = (sizeof_int - 1) << 3;
    return (int)word << shift_left >> shift_right;
}