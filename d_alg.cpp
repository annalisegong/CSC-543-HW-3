//test branch
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int minDistance(int distance[], bool visited[])
{
    int min = INT_MAX;
    int min_index;

    for(int i = 0; i < 5; i++)
    {
        //checks ad
        if(visited[i] == false && distance[i] <= min)
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

int printSolution(int distance[], int totalNodes)
{
    printf("Vertex      Distance from Source\n");
    for(int i = 0; i < totalNodes; i++)
    {
        printf("%d \t %d\n", i, distance[i]);
    }
}

void dijkstra(int graph[5][5], int initial)
{
    int distance[5]; //stores shortest distance from initial to terminal

    bool visited[5]; //true if node is included in shortest distance path

    //initially set all distances to infinity, and all nodes to false = not visited
    for(int i = 0; i < 5; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[initial] = 0; //assign starting distance for initial node to 0

    //find shortest path for all vertices
    for(int count = 0; count < 4; count++)
    {
        int current = minDistance(distance, visited);

        visited[current] = true;

        //update distance value for adj nodes of current vertex
        for(int i = 0; i < 5; i++)
        {
            // Update dist[i] only if is not in sptSet, there is an edge from
            // current to i, and total weight of path from initial to i through current is
            // smaller than current value of dist[i]
            if(!visited[i] && graph[current][i] && distance[current] != INT_MAX
            && distance[current] + graph[current][i] < distance[i])
            {  
                distance[i] = distance[current] + graph[current][i];
            }
        }
    }
    printSolution(distance, 5);
}

int main()
{
    int graph[5][5] = {
        {0,10,0,0,3},
        {0,0,2,0,4},
        {0,0,0,9,0},
        {0,0,7,0,0},
        {0,1,8,2,0}
    };

    dijkstra(graph, 0);
    return 0;
}