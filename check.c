#include <stdio.h>
#define LONG_MIN -2147483648

int main()
{
    int i = -2147483648LL;


    if (i == LONG_MIN)
        printf("%d",i * -1);

    return (0);
}