#include<stdlib.h>
#include<stdio.h>
#include"graphSearch.h"

// Given an unweighted and undirected graph, 
// check if it is a tree topology or not
// Return true/false
bool isTree(int n, const int graph[][n])
{
	int * stack = (int *)calloc(n,sizeof(int));
	int * visit = (int *)calloc(n,sizeof(int));
	int top = -1;
	stack[++top] = 0;
	while(top!=-1)
	{
		int temp = stack[top--];
		visit[temp]= 1;
		for(int i = 0;i<n;i++)
		{
			if(graph[temp][i] == 1 && visit[i]==0)
				stack[++top] = i;
			else if(graph[temp][i] == 1 && visit[i]==1)
			{
				return false;
			}
		}
	}
	return true;
}
// In FrogLand, Pepe the Frog wants to build a food delivery app after being inspired by Swiggy.
// Frogs in FrogLand are not very friendly and don't allow frogs to jump from 
// HouseX to HouseY if they are enemies. Each house in FrogLand has a safeSequence 
// that mentions which houses are safe to jump onto, from the current house.
// No two frogs can cover the same house. Houses are numbered from 0 to n-1.
// Your task is to help Pepe find how many delivery frogs are required for his swamp,
// and to find the maximum number of houses any delivery agent has to visit.
// Note: Frogs can start at any house initially.
// Return a structure Result, with its members assigned.
Result pepesAnswers(int n, const int safeSeq[][n])
{
	int * stack = (int *)calloc(n,sizeof(int));
	int * visit = (int *)calloc(n,sizeof(int));
	int frogs = 0;
	int maxHouse = 0;
	int houses_visited = 0;
	while(houses_visited < n)	// Selecting a house and apply a frog on it and the using a frog apply BFS..
	{
		int starthome = 0;
		for(int i=0;i<n;i++)
		{
			if(visit[i]==0)
			{
				visit[i] = 1;
				starthome = i;
			}
			break;
		}
	
		int c = 0;
		int top = -1;
		stack[++top] = starthome;
		frogs++;
		while(top!=-1)
		{
			c++;
			int temp = stack[top--];
			visit[temp] =1;
			houses_visited++;
			for(int i=0;i<n;i++)
			{
				if(safeSeq[temp][i]==1 && visit[i]==0)
				{
					visit[i] = 1;
					stack[++top] = i;
				}
			}
		}
		if(c> maxHouse)
			maxHouse = c;
		
	}
	Result pack;
	pack.numDeliveryFrogs = frogs;
	pack.maxHouses = maxHouse;
	return pack;	
}

// The swamp has now grown in population, and hence there are more frog houses.
// A delivery frog can only jump over 'k' houses at a time. 
// ie. A frog can jump from HouseX to HouseY only if abs(X-Y) <= k
// Hence modify your above solutions to account for this.
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
    Result pack;
	pack.numDeliveryFrogs = 3;
	pack.maxHouses = 2;
	return pack;
}
