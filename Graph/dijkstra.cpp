#include <iostream>
using namespace std;

int minDistance(int distance[], bool visited[])
{
    int min = INT32_MAX;
    int min_index;
    for (int i = 0; i < 5; i++)
    {
        if (visited[i] == false && distance[i] <= min)
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void output(int distance[])
{
    cout << "Vertex\tDistance from source" << endl;
    for (int i = 0; i < 5; i++)
    {
        char c = 65 + i;
        cout << c << "\t\t" << distance[i] << endl;
    }
}

void dijkstra(int graph[5][5], int source)
{
    int distance[5];
    bool visited[5];
    for (int i = 0; i < 5; i++)
    {
        distance[i] = INT32_MAX;
        visited[i] = false;
    }

    distance[source] = 0;

    for (int i = 0; i < 5; i++)
    {
        int u = minDistance(distance, visited);
        visited[u] = true;
        for (int j = 0; j < 5; j++)
        {
            if (!visited[j] && graph[u][j] && distance[u] + graph[u][j] < distance[j])
            {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }
    output(distance);
}

int main()
{
    int graph[5][5] = {
        {0, 10, 5, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 3, 0, 9, 2},
        {
            0,
            0,
            0,
            0,
            0,
        },
        {2, 0, 0, 6, 0}};
    dijkstra(graph, 3);
}