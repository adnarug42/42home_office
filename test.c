#include <stdio.h>
#include <unistd.h>

int main()
{
    char *s;

    s = "check";
    write(1, &s, 10);

    return(0);
}