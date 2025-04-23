// Write a C program to implement the bubble sort algorithm.
// Best Case: O(n)
// Avearge/Worst Case: O(n^2)
#include <stdio.h>

void bubble_sort(int arr[], int len)
{
	for(int i=0; i<len-1; i++)
	{
		for(int j=0; j<len-(i+1); j++)
		{
			if (arr[j]>arr[j+1])
			{
				arr[j]=arr[j]^arr[j+1];
				arr[j+1]=arr[j]^arr[j+1];
				arr[j]=arr[j]^arr[j+1];
			}
		}
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
	bubble_sort(arr, n);
	printf("Sorted Elements: ");
	for(int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
/*
Ouput: -
Enter the size of array: 5
Enter elements: 5 4 3 2 1
Sorted Elements: 1 2 3 4 5
*/