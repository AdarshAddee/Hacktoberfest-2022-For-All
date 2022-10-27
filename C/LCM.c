#include <stdio.h>

int main()
{
    int a,b, m;

    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);
    
    m = (a > b) ? a : b;

    while (1)
    {
        if ((m % a == 0) && (m % b == 0))
        {
            printf("The LCM of %d and %d is %d.", a, b, m);
            break;
        }
        ++m;
    }
    return 0;
}
