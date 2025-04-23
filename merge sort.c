// Write a C program to implement the quick sort algorithm.
// Best/Average/Worst Case: O(n log n)
#include <stdio.h>
void merge(int low, int mid, int high, int arr[])
{
    int i=0, j=0, k=low, n1=mid-low+1, n2=high-mid;
    int a[n1],b[n2];
    while(i<n1)
    {
        a[i]=arr[i+low];
        i++;
    }
    i=0;
    while(i<n2)
    {
        b[i]=arr[i+mid+1];
        i++;
    }
    i=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++; k++;
        }
        else
        {
            arr[k]=b[j];
            j++; k++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        i++; k++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        j++; k++;
    }
}
void merge_sort(int low, int high, int arr[])
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        merge_sort(low, mid, arr);
        merge_sort(mid+1, high, arr);
        merge(low, mid, high, arr);
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
	merge_sort(n-n, n-1, arr);
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
