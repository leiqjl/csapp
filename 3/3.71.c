#include <stdio.h>
#define SIZE_OF_BUFFER 12
int main(void)
{
    char buf[SIZE_OF_BUFFER];
    while (1)
    {
        char *c = fgets(buf, SIZE_OF_BUFFER, stdin);
        if (c == NULL)
        {
            break;
        }
        printf("%s",c);
    }
    return 0;
}