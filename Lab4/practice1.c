#include<stdio.h>
#include<stdlib.h>
#include"tsp.h"


// Header file for travelling salesman problem

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int n, int graph[][n])
{
    int * arr = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        arr[i] = i;
    int min_cost = __INT_MAX__;
    do
    {
        int cost = getCost(n,graph,arr);
        if(cost<min_cost)
            min_cost = cost;
    } while (get_next_permutation(arr+1, n-1));
    return min_cost;
}

// Returns an array of size n, 
// starting at city_0 (that is the first node) 
// traversing the path with min-cost
// Note: Return the path which is lexicographically smaller in case two paths have the same cost
int* printPath(int n, int graph[][n])
{
    int * arr = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        arr[i] = i;
    int mincost = tsp(n,graph);
    int curr = getCost(n,graph,arr);
    while(curr!=mincost)
    {
        get_next_permutation(arr+1,n-1);
        curr = getCost(n,graph,arr);
    }
    return arr;
}
// Given a permutation of path - P[], 
// Return the cost from the starting city through the path and back
// P[0] -> P[1] -> ... -> P[n-1] -> P[0]
int getCost(int n, int graph[][n], int *P)
{
    int cost = 0;
    int k = P[0];
    for(int i=1;i<n;i++)
    {
        cost = cost + graph[k][P[i]];
        k = P[i];
    }
    cost+= graph[k][P[0]];
    return cost;
}

// Get the next permutation in lexicographical order
// Returns 0 if there is no permutation which lexicographically bigger 
// Implemented in tsp_sampletest.c and tsp_tests.c
// Not to be implemented as a part of lab session
int get_next_permutation(int *permutation, int n);
