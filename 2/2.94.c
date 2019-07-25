#include <assert.h>
typedef unsigned float_bits;
float_bits float_twice(float_bits f);
float u2f(unsigned u);
unsigned f2u(float x);
int equals(float a, float b);

int main(void)
{
    float x = 1.5f;
    unsigned ux = 0x7FFFFFFF;
    assert(equals(x * 2, u2f(float_twice(f2u(x)))));
    x = 0.5f;
    assert(equals(x * 2, u2f(float_twice(f2u(x)))));
    x = 2.5f;
    assert(equals(x * 2, u2f(float_twice(f2u(x)))));
    assert(ux == float_twice(ux));

    return 0;
}

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF)
    {
        /* frac != 0, NaN */
        /* frac == 0, oo */
        return f;
    }
    if (exp == 0)
    {
        /* Denormalized result */
        if (!(frac >> 22))
        {
            frac = frac << 1;
        }
        else
        {
            exp++;
            frac = frac << 10 >> 9;
        }
    }
    else
    {
        /* Normalized result. */
        if (exp != 0xFE)
        {
            exp++;
        }
        else
        {
            exp = 0xFF;
            frac = 0;
        }
    }
    return (sign << 31) | (exp << 23) | frac;
}

float u2f(unsigned u)
{
    return *(float *)&u;
}

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int equals(float a, float b)
{
    const float EPSINON = 0.00001;
    float c = a - b;
    return c <= EPSINON && c >= -EPSINON;
}