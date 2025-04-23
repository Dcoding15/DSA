// Write a C program to implement the quick sort algorithm.
// Best/Average Case: O(n log n)
// Worst Case: O(n^2)
#include <stdio.h>

int partition(int low, int high, int arr[])
{
	int pivot=arr[low];
	int i=low, j=high;
	while(i<j)
	{
		while (arr[i]<=pivot)
		{
			i++;
		}
		while (arr[j]>pivot)
		{
			j--;
		}
		if (i<j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	arr[low] = arr[j];
	arr[j] = pivot;
	return j;
}

void quick_sort(int low, int high, int arr[])
{
	if (low<high)
	{
		int pivot=partition(low, high, arr);
		quick_sort(low, pivot-1, arr);
		quick_sort(pivot+1, high, arr);
	}
}

int main()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(n-n, n-1, arr);
	printf("Sorted Elements: ");
	for(int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
/*
Output: -
Enter the size of array: 5
Enter elements: 5 4 3 2 1
Sorted Elements: 1 2 3 4 5
*/
