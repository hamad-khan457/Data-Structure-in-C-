#include <iostream>
#include <cstdint>
using namespace std;
#define V 8

int minKey(int key[V], bool visited[V])
{
    int minVal = INT32_MAX;
    int minindex;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < minVal)
        {
            minVal = key[i];
            minindex = i;
        }
    }
    return minindex;
}

void printMST(int graph[V][V], int parent[V])
{
    cout << "Edge\tCost" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << char('A' + parent[i]) << "-" << char('A' + i) << "\t" << graph[i][parent[i]] << endl;
    }
}

void primsAlgo(int graph[V][V])
{
    bool visited[V];
    int key[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        key[i] = INT32_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V; i++)
    {
        int u = minKey(key, visited);
        visited[u] = true;
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] && !visited[j] && graph[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printMST(graph, parent);
}
int main()
{
    int graph[V][V] = {
        {0, 8, 0, 0, 0, 10, 0, 4},
        {8, 0, 4, 0, 10, 7, 0, 9},
        {0, 4, 0, 3, 0, 3, 0, 0},
        {0, 0, 3, 0, 25, 18, 2, 0},
        {0, 10, 0, 25, 0, 2, 7, 0},
        {10, 7, 3, 18, 2, 0, 0, 0},
        {0, 0, 0, 2, 7, 0, 0, 3},
        {4, 9, 0, 0, 0, 0, 3, 0}};
    primsAlgo(graph);
}