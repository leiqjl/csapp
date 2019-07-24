#include <assert.h>
#include <limits.h>
#include <math.h>
float u2f(unsigned u);
unsigned f2u(float x);
float fpwr2(int x);
int equals(float a, float b);
int main(void)
{
    assert(equals(fpwr2(-200), 0.0));
    assert(equals(fpwr2(-149), powf(2, -149)));
    assert(equals(fpwr2(-126), powf(2, -126)));
    assert(equals(fpwr2(127), powf(2, 127)));
    return 0;
}
int equals(float a, float b)
{
    const float EPSINON = 0.00001;
    float c = a-b;
    return c<= EPSINON && c>= -EPSINON;
}
/**
 * k=8,n=23.bias=2^(8-1)-1=127
 * 最小非规格化数2^(1-127-23)=2^-149
 * 最小规格化数2^(1-127)=2^-126
 * 最大规格化数2^(2^8-127)=2^127
 */
float fpwr2(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;
    if (x < -149)
    {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    }
    else if (x <-126)
    {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (x+149);
    }
    else if (x < 128)
    {
        /* Normalized result. */
        exp = x + 127;
        frac = 0;
    } 
    else
    {
        /* Too big. Return +oo */
        exp = 255;
        frac = 0;
    }
    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}

float u2f(unsigned u)
{
    return *(float *)&u;
}

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}
