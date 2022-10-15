// Github username: Ritikraja07
// Aim: To print a star patter using C
// Date: 15/10/2022

// start coding

#include<stdio.h>
int main()
{
    int i,j,k;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5-i;j++)
            printf(" ");
        for(k=1;k<=2*i-1;k++)
            printf("*");
            printf("\n");
    }
    return 0;
}
