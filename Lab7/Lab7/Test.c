#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mergeSort(int arr[],int l,int r);
void merge(int arr[],int l,int m,int r);

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int * arr  = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted array\n");

    for(int i= 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l<r){
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    }
}
void merge(int arr[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int * arr1 = (int *)malloc(sizeof(int)*n1);
    int * arr2 = (int *)malloc(sizeof(int)*n2);
    for(int i=0;i<n1;i++)
        arr1[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        arr2[i] = arr[m+1+i];
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else if(arr1[i]>=arr2[j])
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}