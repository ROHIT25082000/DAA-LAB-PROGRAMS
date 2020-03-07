#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sm.h"

// Header file for the implementation of Naive algorithm for String Matching

// Find the offset of the first occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchFirstOccurrence(char *pattern, char *text)
{
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i = 0;i<n-m+1;i++)
    {
        int j = 0;
        while( j<m && pattern[j]==text[i+j])
        {
            j++;
        }
        if(j==m)
            return i;
    }
    return -1;
}

// Find the offset of the last occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchLastOccurrence(char *pattern, char *text)
{
    int last = 0;
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i = 0;i<n-m+1;i++)
    {
        int j = 0;
        while( j<m && pattern[j]==text[i+j])
        {
            j++;
        }
        if(j==m)
            last = i;
    }
    return last;
}

// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text)
{
    int num = 0;
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i =0;i<n-m+1;i++)
    {
        int j =0;
        while(j<m && pattern[j]==text[i+j])
        {
            j++;
        }
        if(j==m)
            num++;
    }
    return num;
}

// Find the length of longest prefix of the pattern that matches a substring of the pattern
int longestPrefix(char *pattern, char *text)
{
    int max= 0;
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i = 0;i<n-m+1;i++)
    {
        int len = 0;
        int j=0;
        while(j<m && pattern[j]==text[i+j])
        {
            len++;
            j++;
        }
        if(len>max) 
            max = len;
    }
    return max;
}

// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text)
{
    int count = 0;
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i = 0;i<n-m+1;i++)
    {
        int j =0;
        while( j<m && pattern[j]==text[i+j])
        {
            count++;
            j++;
        }
        if(j<m)
        {
            count+=1;
        }
    }
    return count;
}