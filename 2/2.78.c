#include <assert.h>
#include <limits.h>
int divide_power2(int x, int k);
int main(void)
{
    assert(divide_power2(-5, 1) == -5/2);
    assert(divide_power2(5, 1) == 5/2);
    return 0;
}

int divide_power2(int x, int k)
{
    (x & INT_MIN) && (x = x + (1 << k) - 1);

    return x >> k;
}
