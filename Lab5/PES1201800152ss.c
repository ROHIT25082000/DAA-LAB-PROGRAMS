#include<stdio.h>
#include<stdlib.h>
#include "session5_sort.h"
#include <time.h>


double time_elapsed(struct timespec start, struct timespec end);
void swap(Record*A,Record*B)
{
    Record C = *A;
    *A = *B;
    *B = C;
}
//Insertion Sort
//Sorts the array of Records on the serialnumber field using the Insertion Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int InsertionSort(Record* A, int n)
{
    int num = 0;
    int i,j;
    int swap;
    for(int i = 1;i<n;i++)
    {
        j = i-1;
        swap = A[i].serialnumber;
        while(A[j].serialnumber > A[i].serialnumber && j>=0)
        {
            num++;
            j--;
        }
        A[j+1].serialnumber = swap;
    }
    return num;
}

//Bubble Sort
//Sorts the array of Records on the serialnumber field using the Bubble Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int BubbleSort(Record* A, int n)
{
    long int num = 0;int sort = 1;
    for(int i=0;i<n-1;i++)
    {
        int num = 0;
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j].serialnumber>A[j+1].serialnumber)
            {
                num++;
                swap(&A[j],&A[j+1]);
                //sort = 1;
            }
        }
    }
    return num;
}

//Selection Sort
//Sorts the array of Records on the serialnumber field using the Selection Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int SelectionSort(Record* A, int n)
{
   long int num = 0;
    for(int i = 0;i<n-1;i++)
    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(A[j].serialnumber < A[min].serialnumber)
            {
                min = j;
                num++;
            }
        }
        swap(&A[i],&A[min]);
    }
    return num;
}

int main()
{
    struct timespec start, end; //timestamps
    int n;
    scanf("%d",&n);
    Record * A = (Record*)malloc(sizeof(Record)*n);
    Record * B = (Record*)malloc(sizeof(Record)*n);
    Record * C = (Record*)malloc(sizeof(Record)*n);

    for(int i=0;i<n;i++)
    {

        scanf("%ld %d",&A[i].serialnumber,&A[i].score);
        B[i].serialnumber = A[i].serialnumber;
        B[i].score  = A[i].score;
        C[i].serialnumber = A[i].serialnumber;
        C[i].score = A[i].score;
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int result1 = InsertionSort(A,n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    printf("\n\n\ninsertion %d %2.6f\n", result1, time_elapsed(start, end));

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int result2 = BubbleSort(A,n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    printf("BubbleSort %d %2.6f\n", result2, time_elapsed(start, end));


    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int result3 = SelectionSort(A,n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp

    printf("SelectionSort %d %2.6f\n", result3, time_elapsed(start, end));


} 


double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}
