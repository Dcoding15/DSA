// Write a C program to implement the selection sort algorithm.
// Best/Avearge/Worst Case: O(n^2)
#include <stdio.h>

void selection_sort(int arr[], int len)
{
	for(int i=0; i<len-1; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if (arr[i]>arr[j])
			{
				arr[i]=arr[i]^arr[j];
				arr[j]=arr[i]^arr[j];
				arr[i]=arr[i]^arr[j];
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
	selection_sort(arr, n);
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