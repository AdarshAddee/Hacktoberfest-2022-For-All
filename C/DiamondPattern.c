//Github username: Tikshita-Singh
// Aim: Diamond Pattern in c
// Date: 4/10/2022

#include <stdio.h>
int main()
{
  int n, i, j;
  printf("Enter number of rows\n");
  scanf("%d", &n);
  for(i = 1; i<= n; i++)
  {
    for(j = 1; j <= n-i; j++)
    {
         printf(" ");
    }
    for(j = 1; j <= 2*i-1; j++)
    {
         printf("*");
    }
    printf("\n");
  }

  for(i = 1; i <= n - 1; i++)
  {
    for (j = 1;  j<= i; j++)
    {
        printf(" ");
    }
    for (j = 1 ; j <= 2*(n-i)-1; j++)
    {
        printf("*");
    }
    printf("\n");
  }
  return 0;
}
