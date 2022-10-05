//GitHub username = maazm007
//Aim = This program is used to convert the 12 Hour Clock System into 24 Hour Clock System
//Date of Coding = 05/10/22

#include <stdio.h>
#include <string.h>
int main()
{
    char arr[100], i, j;
    scanf("%s", arr);
    if (arr[8] == 80)
    {
        if (arr[0] != 1 || arr[1] != 2)
        {
            arr[0] = arr[0] + 1;
            arr[1] = arr[1] + 2;
        }
    }
    else if (arr[8] == 65)
    {
        if (arr[0] == '1' && arr[1] == '2')
        {
            arr[0] = '0';
            arr[1] = '0';
        }
    }
    for (i = 0; i < strlen(arr) - 2; i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}