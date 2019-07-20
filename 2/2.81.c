#include <assert.h>
#include <limits.h>
int main(void)
{
    int k = 4;
    //A 1(w-k)0(k)
    assert((~0<<k) == 0xFFFFFFF0);
    int j = 4;
    //B 0(w-k-j)1(w)0(j)
    assert((~(~0<<k)<<j) == 0xF0);
    return 0;
}
