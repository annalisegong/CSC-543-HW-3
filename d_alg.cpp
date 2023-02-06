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
        //checks adj node and returns index of adj node with shorter width
        if(visited[i] == false && distance[i] <= min)
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

int printSolution(int distance[], int path[], int end)
{
    cout << "Shortest Distance from Starting Node: ";
    for(int i = 0; i < 5; i++)
    {
        while(i == end)
        {
            cout << distance[i] << "\n";
            cout << "Shortest Distance Path: ";
            for(int j = 0; j < 5; j++)
            {
                cout << path[j] << ", ";
            }
            return 0;
        }
    }
}

void dijkstra(int graph[5][5], int initial, int end)
{
    int distance[5]; //stores shortest distance from initial to terminal

    bool visited[5]; //true if node is included in shortest distance path

    int path[5]; //stores shortest path order

    //initially set all distances to infinity, and all nodes to false = not visited
    for(int i = 0; i < 5; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[initial] = 0; //assign starting distance for initial node to 0
    path[0]= initial; //all paths starts with initial node

    //find shortest path for all vertices
    for(int count = 0; count < 4; count++)
    {
        int current = minDistance(distance, visited);
        visited[current] = true;
        //update distance value for adj nodes of current node
        for(int i = 0; i < 5; i++)
        {
            // Update dist[i] only if is not in visited, there is an edge from
            // current to i, and total weight of path from initial to i through current is
            // smaller than current value of dist[i]
            if(!visited[i] && graph[current][i] && distance[current] != INT_MAX
            && distance[current] + graph[current][i] < distance[i])
            {  
                distance[i] = distance[current] + graph[current][i];
                if(current == end)
                {
                    path[count + 1] = end;
                }
                else
                {
                    path[count+1] = i;
                }
            }
        }
        //after min distance is found, need to update path to include current node;
    }
    printSolution(distance, path, end);
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

    cout << "choose a starting node: 0,1,2,3,4\n";
    int initial;
    cin >> initial;

    cout << "choose an ending node: 0,1,2,3,4\n";
    int end;
    cin >> end;

    dijkstra(graph, initial, end);
    return 0;
}