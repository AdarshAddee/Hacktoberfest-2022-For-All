//GitHub username = maazm007
//Aim = This code is use to merge two different sorted arrays
//Date = 05/10/22


#include <iostream>
using namespace std;
void merge(int a[], int n, int b[], int m, int c[])
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < (m + n); i++) //this loop will run upto number of elements in both arrays
    {
        if (a[k] > b[j])
        {
            c[i] = b[j];
            j = j + 1;
        }
        else
        {
            c[i] = a[k];
            k = k + 1;
        }
    }
    for (i = 0; i < (n + m); i++)
    {
        cout << c[i] << " ";
    }
}
int main()
{
    int a[10], b[10];
    int c[10], n, m;
    // a array is one sorted array
    // b is another sorted array
    // c is the array in which we are merging both sorted array
    cin >> n; // number of elements in array 1
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m; // number of elements in array 2
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    merge(a, n, b, m, c);
}