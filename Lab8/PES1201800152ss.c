#include<stdio.h>
#include<stdlib.h>
#include"quickSort.h"

ptrPair divide(int *a, int n)
{
    int q = getPartitionIndex(a,n);
    ptrPair myptr;
    myptr.first = a;
    myptr.firstLen = q+1;
    myptr.second = a+q+1;
    myptr.secondLen = n -1 -q;
    return myptr;

}
/**
 * getPartitionIndex():
 * Choose the first element from the array A[0..n-1] as the pivot element
 * Partition the array using hoare's partitioning scheme, 
 * and return the index of the split
 * HOARE-PARTITION(A, p, r)
    x = A[p]
    i = p - 1
    j = r + 1
    while true
        repeat
            j = j - 1
        until A[j] ≤ x
        repeat
            i = i + 1
        until A[i] ≥ x
        if i < j
            exchange A[i] with A[j]
        else return j
 */
int getPartitionIndex(int *a, int n)
{
    int x = a[0];
    int i = -1;
    int j = n;
    while(1)
    {
        do
        {
            j--;
        } while (a[j]>x && j>=0);
        do
        {
            i++;
        } while (a[i]<x && i<n);
        if(i<j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }        
        else 
        {
            return j;
        }
        
    }
}
/**
 * conquer():
 * Call the divide function to divide the array,
 * and then conquer the two sub arrays recursively
 */
void conquer(int *a, int n)
{
    if(n>1)
    {
        ptrPair myptr = divide(a,n);
        conquer(myptr.first,myptr.firstLen);
        conquer(myptr.second,myptr.secondLen);
    }
}

// Wrapper function to call conquer() for the first time.
void quickSort(int *a, int n)
{
    conquer(a,n);
}

// Check if an array is sorted.
// Return 1 if the array is sorted, 0 otherwise.
int isSorted(int *a, int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
         return 0;
    }
    return 1;
}