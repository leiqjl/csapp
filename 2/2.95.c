#include <assert.h>
typedef unsigned float_bits;
float_bits float_half(float_bits f);
float u2f(unsigned u);
unsigned f2u(float x);
int main(void)
{
    float x = 1.5f;
    unsigned ux = 0x7FFFFFFF;
    
    assert(f2u(x*0.5) == float_half(f2u(x)));
    x = 0.5f;
    assert(f2u(x*0.5) == float_half(f2u(x)));
    x = 2.5f;
    assert(f2u(x*0.5) == float_half(f2u(x)));
    ux = 0x00FFFFFF;
    x = u2f(ux);
    assert(f2u(x*0.5) == float_half(ux));

    return 0;
}

/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    unsigned addition = (frac & 0x3) == 0x3;

    if (exp == 0xFF)
    {
        /* frac != 0, NaN */
        /* frac == 0, oo */
        return f;
    }
    if (exp == 0)
    {
        frac = frac >> 1;
        frac += addition;
    }
    else if (exp == 1)
    {
        if (frac == 0x7FFFFF)
        {
            exp = 1;
            frac = 0;
        }
        else
        {
            exp--;
            frac = (frac >> 1) | 0x400000;
            frac += addition;
        }
    }
    else
    {
        exp--;
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