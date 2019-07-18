#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
void copy_int(int val, void *buf, int maxbytes);
void copy_int_wrong(int val, void *buf, int maxbytes);
int main(int argc, char *argv[])
{
    int maxbytes = sizeof(int) * 5;
    void *buf = malloc(maxbytes);

    int val = 0x12345678;
    copy_int(val, buf, maxbytes);
    assert(*(int *)buf == val);

    val = 0x87654321;
    copy_int(val, buf, 1);
    assert(*(int *)buf != val);

    free(buf);
    return 0;
}
// (maxbytes-sizeof(val) -> unsigned -> >=0
void copy_int_wrong(int val, void *buf, int maxbytes)
{
    if (maxbytes - sizeof(val) >= 0)
    {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}

void copy_int(int val, void *buf, int maxbytes)
{

    if ((maxbytes < 0))
    {
        return;
    }

    if (maxbytes >= sizeof(val))
    {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}