#include <assert.h>
typedef unsigned float_bits;
int float_f2i(float_bits f);
float u2f(unsigned u);
unsigned f2u(float x);
int main(void)
{
    float x = 1.5;
    unsigned ux = 0x37FFFFFF;
    assert((int)x == float_f2i(f2u(x)));
    assert((int)u2f(ux) == float_f2i(ux));
    x = 0.5;
    assert((int)x == float_f2i(f2u(x)));
    return 0;
}

/** Compute (int)f.
 *  If conversion causes overflow or f is NaN, then return 0x80000000. 
 */
int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0x7F;

    int num;
    unsigned E;
    unsigned M;

    if (exp >= 0 && exp < bias)
    {
        num = 0;
    }
    else if (exp >= 31 + bias)
    {
        num = 0x80000000;
    }
    else
    {
        E = exp - bias;
        M = frac | 0x800000;
        if (E >= 23)
        {
            num = M << (E - 23);
        }
        else
        {
            num = M >> (23 - E);
        }
    }

    return sign ? -num : num;
}

float u2f(unsigned u)
{
    return *(float *)&u;
}

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}