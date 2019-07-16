#include <stdio.h>
int int_shifts_are_arithmetic();
int main(void)
{
    printf("%#.8x\n", -1);
    printf("%d\n", int_shifts_are_arithmetic());
}
int int_shifts_are_arithmetic()
{
    return (-1>>1)==-1;
}