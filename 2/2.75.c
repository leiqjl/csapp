#include <assert.h>
#include <limits.h>
#include <inttypes.h>
unsigned unsigned_high_prod(unsigned x, unsigned y);
int signed_high_prod(int x, int y);
int main(void)
{
    unsigned x = ~0;
    unsigned y = ~0;
    assert(unsigned_high_prod(x, y) == ((uint64_t)x * y >> 32));
    return 0;
}

/**
 * x'= x + xw-1 * 2^w
 * y'= y + yw-1 * 2^w
 * (x'*y')mod2^w = (xy +(xw-1 * y + yw-1 * x)*2^w + xw-1 * yw-1 * 2^2w)mod2^w
 */
unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int signed_high = signed_high_prod(x, y);
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    unsigned high_prod = signed_high + sig_x * y + sig_y * x;
    return high_prod;
}
int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}
