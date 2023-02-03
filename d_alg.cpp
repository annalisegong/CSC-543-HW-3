#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

//adds edge = link between two nodes with its width
void addEdge(vector <pair<int, int> > adjList[], int n, int N, int w)
{
    //vector = sequence container that will store adjacency lists of ints
    //pair = simple container to store pair of elements (node, width)

    //push_back function inserts new element at end of vector and ++1 vector size
    //make_pair function initializes and assigns pair between two elements
    adjList[n].push_back(make_pair(N, w));
    adjList[N].push_back(make_pair(n, w));
}

void printGraph(vector<pair<int, int> > adjList[], int totalNodes)
{
    int N;
    int w;
    for(int i = 0; i < totalNodes; i++)
    {
        cout << "Node " << i << " has edge with \n";
        //auto keyword defines type for me
        for(auto it = adjList[i].begin(); it != adjList[i].end(); it++)
        {
            N = it->first; //first refers to first element in pair aka node name
            w = it->second; //second refers to second element in pair
            cout << "\tNode " << N << " with width = " << w << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    int totalNodes = 5; // may need to change to 4
    vector<pair<int, int> > adjList[totalNodes];
    addEdge(adjList, 0, 1, 10);//A to B
    addEdge(adjList, 0, 4, 3);//A to E
    addEdge(adjList, 1, 2, 2);//B to C
    addEdge(adjList, 1, 4, 4);//B to E
    addEdge(adjList, 2, 3, 9);//C to D
    addEdge(adjList, 3, 2, 7);//D to C
    addEdge(adjList, 4, 1, 1);//E to B
    addEdge(adjList, 4, 2, 8);//E to C
    addEdge(adjList, 4, 3, 2);//E to D
    printGraph(adjList, totalNodes);
    cout << "done";
    return 0;
}
//issue