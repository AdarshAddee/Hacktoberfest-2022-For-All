#include <stdio.h>
#include <stdlib.h>
int main(int argc, char argv)
{
    union
    {
        short s;
        char c[sizeof(short)];
    } un;
    un.s = 0x0102;
    if (sizeof(short) == 2)
    {
        if (un.c[0] == 1 && un.c[1] == 2)
            printf("big endian");
        else if (un.c[0] == 2 && un.c[1] == 1)
            printf("little endian");
        else
            printf("unknown");
    }
    else
    {
        printf("sizeof (short) = %d n", sizeof(short));
    }
    exit(0);
}