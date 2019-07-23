#include <assert.h>
#include <limits.h>
unsigned f2u(float x);
int float_le(float x, float y);
int main(void)
{
    assert(float_le(+0.0f, -0.0f) == 1);
    assert(float_le(-0.0f, +0.0f) == 1);
    assert(float_le(-5.0f, -1.0f) == 1);
    assert(float_le(5.0f, 1.0f) == 0);
    assert(float_le(3.0f, 3.0f) == 1);
    assert(float_le(-3.0f, 3.0f) == 1);
    return 0;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Given an expression using only ux, uy, sx, and sy */
    return (ux << 1 == 0 && uy << 1 == 0) || (sx && !sy) || (!sx && !sy && ux <= uy) || (sx && sy && ux >= uy);
}

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}
