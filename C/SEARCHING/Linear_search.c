//LINEAR SEARCH USING C Program

#include <stdio.h>
int search(int arr[], int N, int x)
{
	int i;
	for (i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

/* Function to print an array */

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver's code
int main(void)
{
	int i, n, x;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in the array : ");
	for(i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element you want to search in the array : ");
	scanf("%d", &x);
	// Function call
	int result = search(arr, n, x);

	if(result == -1)
		printf("Element is not present in array");
    else
		printf("Element is present at index %d", result);

	return 0;
}
