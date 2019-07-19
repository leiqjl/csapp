#include <assert.h>
#include <limits.h>
int tsub_ok(int x, int y);
int main(void)
{
    assert(tsub_ok(INT_MAX, INT_MIN) == 0);
    assert(tsub_ok(12345, 54321) == 1);
    assert(tsub_ok(INT_MAX, INT_MAX) == 1);
    assert(tsub_ok(INT_MAX, -INT_MAX) == 0);
    assert(tsub_ok(1, INT_MIN) == 0);
    assert(tsub_ok(INT_MIN, INT_MIN) == 0);
    return 0;
}

/**
 * x>0,y<0,x-y<0
 * x<0,y>0,x-y>0
 */
int tsub_ok(int x, int y)
{
    int res = 1;

    (y == INT_MIN) && (res = 0);

    int differ = x - y;
    
    int pos_over = !(x & INT_MIN) && (y & INT_MIN) && (differ & INT_MIN);
    int neg_over = (x & INT_MIN) && !(y & INT_MIN) && !(differ & INT_MIN);
    
    return res && !pos_over && !neg_over;
}
