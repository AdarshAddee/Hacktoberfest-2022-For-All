#include<stdio.h>

int main() {
  int n, r, sum = 0, temp;
  printf("Enter a number: \n");
  scanf("%d", & n);
  temp = n;
  while (n > 0) {
    r = n % 10;
    sum = (sum * 10) + r;
    n = n / 10;
  }
  if (temp == sum)
    printf("This is a palindrome number ");
  else
    printf("This is not a palindrome number");
  return 0;
}
