#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>


#include "sm.h"


// Header file for the implementation of Naive algorithm for String Matching

// Find the offset of the first occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchFirstOccurrence(char *pattern, char *text)
{
	int i = 0;
	int m = strlen(text);
	int n = strlen(pattern);
	while(i < m-n+1)
	{
		int j = 0;
		while(j<n && pattern[j] == text[i+j])
		{
			j++;
		}
		if(j == n)
			return i;
		i++;
	}
	return -1;
}
// Find the offset of the last occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchLastOccurrence(char *pattern, char *text)
{
	int i = 0;
	int last = -1;
	int m = strlen(text);
	int n = strlen(pattern);
	while(i < m-n+1)
	{
		int j = 0;
		while(j<n && pattern[j] == text[i+j])
		{
			j++;
		}
		if(j == n)
			last = i;
		i++;
	}
	return last;
	
}

// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text)
{
	int count= 0;
	int i = 0;
	int m = strlen(text);
	int n = strlen(pattern);
	while(i < m-n+1)
	{
		int j = 0;
		while(j<n && pattern[j] == text[i+j])
		{
			j++;
		}
		if(j == n)
			count++;
		i++;
	}
	
	return count;
}


// Find the length of longest prefix of the pattern that matches a substring of the pattern
int longestPrefix(char *pattern, char *text)
{
	int max = 0;
	int i = 0;
	int m = strlen(text);
	int n = strlen(pattern);
	while(i< m-n+1)
	{
		int j =0;
		while(j<n && pattern[j] == text[i+j])
		{
			j++;
		}
		if(j > max)
			max =j;
		i++;
	}
	return max;
}


// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text)
{
	int char_count = 0;
	int i = 0;
	int m = strlen(text);
	int n = strlen(pattern);
	while(i < m-n+1)
	{
		int j = 0;
		while(j<n && pattern[j] == text[i+j])
		{
			j++;
		}
		if(j == n)
			char_count = char_count + n;
		else 
			char_count = char_count + j +1;
		i++;
	}
	return char_count;
}

