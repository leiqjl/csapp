#include <assert.h>
#include <limits.h>
int saturationg_add(int x, int y);
int main(void)
{
    assert(saturationg_add(INT_MAX, INT_MAX) == INT_MAX);
    assert(saturationg_add(INT_MIN, -1) == INT_MIN);
    assert(saturationg_add(12345, 54321) == (12345+54321));
    return 0;
}

/**
 * x>0,y>0,x+y<0
 * x<0,y<0,x+y>0
 */
int saturationg_add(int x, int y)
{
    int sum = x + y;

    int pos_over = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
    int neg_over = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);
    
    (pos_over&&(sum=INT_MAX)) || (neg_over&&(sum=INT_MIN));

    return sum;
}
