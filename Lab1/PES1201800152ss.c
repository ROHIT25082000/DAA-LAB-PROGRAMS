#include<stdio.h>
#include<stdlib.h>
#include"ss.h"
int searchFirstOccurrence(int arr[], int n, int key)
{
	for(int i = 0; i < n; i++){
		if(key == arr[i])
		{
			return i;
		}
	}
	return -1;
} 
//Find the offset of the last occurrence of the key in an array of integers
//Return -1 in case of no occurrences of the key.
int searchLastOccurrence(int arr[], int n, int key)
{
	for (int i = n-1; i >=0 ; i--)
	{
		if(key == arr[i])
		{
			return i;
		}
	}
	return -1;
}

//Find the number of occurrences of the key in an array of integers
int numOccurrences(int arr[], int n, int key)
{
	int count = 0;
	for(int i = 0; i < n; i++){
		if(key == arr[i])
		{
			count++;
		}
	}
	return count;
}



int main(int argc, char const *argv[])
{
	int my[20] = {12,23,45,43,76,78,34,24,64,23};
	printf("The number of occurrences = %d\n",numOccurrences(my,10,23));
	printf("The number of searchFirstOccurrence = %d\n",searchFirstOccurrence(my,10,23));
	printf("The number of searchLastOccurrence = %d\n",searchLastOccurrence(my,10,23));
	return 0;
}








