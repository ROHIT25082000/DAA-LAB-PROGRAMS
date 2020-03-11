#include<stdio.h>
#include<stdlib.h>
#include"heapSort.h"

// Header file for the implementation of Heap sort
/*
typedef struct
{
    int *a;
    int size;
} Heap;
*/
/**
 * Given an array a[], build a max heap by calling maxHeapify on each parent 
 * starting from the last non-leaf node(at n/2 - 1 th index) down to the root node(at 0th index).
 * Return a heap structure pointing to the same array a[], with size n.
 */
Heap buildMaxHeap(int *const a, int n)
{
    Heap h;
    h.a = a;
    h.size = n;
    for(int i= n/2 -1;i>=0;i--)
    {
        maxHeapify(h,i);
    }
    return h;
}
/**
 * MAX_HEAPIFY: Compare h.a[idx] with its two children(if they exist), 
 * and swap the smallest of the three with the element at idx, 
 * and recursively call maxHeapify on the child node that got swapped.
 */
void maxHeapify(Heap h, int idx)
{   
    int max = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;
    if(left < h.size && h.a[left] > h.a[max])
    {
        max = left;
    }
    if(right<h.size && h.a[right] > h.a[max])
    {
        max = right;
    }
    if(max!=idx)
    {
        int temp = h.a[max];
        h.a[max] = h.a[idx];
        h.a[idx] = temp; 
        maxHeapify(h,max);
    }
}
/**
 * HEAP_SORT: Sort array a[] by first building max heap, 
 * and then, iteratively swap the max element with last element
 * and call heapify on the root node. Remember to decrease heap.size after each iteration.
 */
void heapSort(int *const a, int n)
{
    Heap curr = buildMaxHeap(a,n);
    for(int i=n-1;i>0;i--)
    {
        int temp = curr.a[0];
        curr.a[0] = curr.a[i];
        curr.a[i] = temp;
        curr.size = i;
        maxHeapify(curr,0);
    }
}
/**
 * A great article to understand heap sort:
 * https://medium.com/basecs/heapify-all-the-things-with-heap-sort-55ee1c93af82
 */