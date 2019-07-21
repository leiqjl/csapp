#include <assert.h>
#include <limits.h>
int main(void)
{
    int x, y;
    //A.(x<y)==(-x>-y) F
    x = INT_MIN;
    y = INT_MAX;
    assert(((x < y) == (-x > -y)) == 0);
    
    //B.((x+y)<<4)+y-x==17*y+15*x  T
    //LEFT= ((((x+y)mod *16)mod+y)mod-x)mod=(16*(x+y)+y-x)mod=(17y+15x)mod
    //RIGHT= 17ymod+15xmod=(17y+15x)mod=LEFT
    
    //C.~x+~y+1==~(x+y) T
    //-x=~x+1
    //LEFT =(-x-1)+(-y-1)+1= -(x+y)-1
    //RIGHT=-(x+y)-1=RIGHT

    //D.(ux-uy)==-(unsigned)(y-x) T

    //E.((x>>2)<<2)<=x T

    return 0;
}
