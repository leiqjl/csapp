#include <assert.h>
#include <limits.h>
int mul3div4(int x);
int main(void)
{
    int x = 0x87654321;
    assert(mul3div4(x) == x * 3 / 4);
    return 0;
}

int mul3div4(int x)
{
    int k = 2;
    x = (x << 1) + x;

    (x & INT_MIN) && (x = x + (1 << k) - 1);
    
    return x >> k;

}