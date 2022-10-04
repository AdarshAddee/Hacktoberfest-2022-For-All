// Github username: shivamvats2102
// Aim: added a Hollow Pyramid pattern in c++
// Date: 04-10-2022
// CPP program to print a hollow pyramid pattern
#include <iostream>
using namespace std;
void printPattern(int);
int main()
{
	int n = 6;

	printPattern(n);
}
void printPattern(int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++) // row=6
	{
		// Print spaces
		for (j = i; j < n; j++) {
			cout << " ";
		}
		// Print #
		while (k != (2 * i - 1)) {
			if (k == 0 || k == 2 * i - 2)
				cout << "*";
			else
				cout << " ";
			k++;
		}
		k = 0;
		cout << endl; // print next row
	}
	// print last row
	for (i = 0; i < 2 * n - 1; i++) {
		cout << "*";
	}
}

