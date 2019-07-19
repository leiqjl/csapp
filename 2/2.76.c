#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size);
int main(void)
{
    return 0;
}

void *calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
    {
        return NULL;
    }
    size_t s =  nmemb * size;
    if (s/size != nmemb)
    {
        return NULL;
    }
    void* p;
    memset(p, 0, s);
    return p;    
}
