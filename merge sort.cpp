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
    int n=5;
    int arr[]={5,4,3,2,1};
    merge_sort(0,n-1,arr);
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
