#include <stdio.h>
#define sizeof_int sizeof(int)
unsigned srl(unsigned x, int k);
int sra(int x, int k);
int main(void)
{
    unsigned x = ~0;
    printf("%#.8x\n", x);
    printf("%#.8x\n", srl(x, 0));
    printf("%#.8x\n", srl(x, 4));
    printf("%#.8x\n", srl(x, 16));

    int y = ~0;
    printf("%#.8x\n", y);
    printf("%#.8x\n", sra(y, 0));
    printf("%#.8x\n", sra(y, 4));
    printf("%#.8x\n", sra(y, 16));

}

//k 0~w-1
unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int)x >> k;

    unsigned w = sizeof(int) << 3;
    //0xfff00000
    unsigned mask = ~(((1 << k) - 1) << (w - k));
    return mask & xsra;
}
int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;

    unsigned w = sizeof(int) << 3;

    unsigned mask = ~0 << (w-k);
    unsigned s = 1<<(w-1);
    mask = !(s&x) & mask;
    return mask ^ xsrl;
}