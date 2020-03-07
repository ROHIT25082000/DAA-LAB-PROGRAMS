#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mergeSort.h"


// Merges two sorted halfs of an array into a single sorted array
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
    int n1 = mid - start +1;
    int n2 = end - mid;
    int *left = (int *)malloc(sizeof(int)*n1);
    int *right = (int *)malloc(sizeof(int)*n2);
    for(int i = 0;i<n1;i++)
        left[i] = a[start+i];
    for(int i = 0;i<n2;i++)
        right[i] = a[mid+1+i];
    int i=0;
    int j=0;
    int k=start;
    while(i< n1 && j< n2)
    {
        if(left[i]<=right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else 
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = right[j];
        j++;
        k++; 
    }
}

// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end)
{
    if(start<end)
    {
        int mid = start + (end-start)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        mergeSortedHalfs(a,start,mid,end);
    }
}

// Implement insertion sort
// n - number of elements in the array
void insertionSort(int *a, int start, int end)
{
    int n = end-start+1;
    int i;
    int j;
    for(i=1+start;i<n;i++)
    {
        j = i-1;
        int swap = a[i];
        while(a[j]>swap && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = swap;
    }
}

// Implement a function which applies merge sort only if
// size of the array is larger than that of parameter
// if not apply insertion sort.
// Use mergeSortedHalfs() and insertionSort() declared above to do the same.
void selectiveMergeSort(int *a, int start, int end, int parameter)
{
    if(end-start+1>parameter)
    {
        mergeSort(a,start,end);
    }
    else 
    {
        insertionSort(a,start,end);
    }
}