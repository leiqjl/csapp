#include <assert.h>
int main(void)
{
    int x = 1;
    //only + - <<
    //A.K=17
    assert((x * 17) == ((x << 4) + x));
    //B.K=-7
    assert((x * -7) == (x - (x << 3)));
    //C.K=60
    assert((x * 60) == ((x << 6) - (x << 2)));
    //D.K=-112
    assert((x * -112) == ((x << 4) - (x << 7)));
    return 0;
}
