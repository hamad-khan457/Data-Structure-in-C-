#include <iostream>
#include <queue>
#include <stack>
#define V 4
using namespace std;
void initialize(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[][V], int i, int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void displayGraph(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        cout << i << ":  ";
        for (int j = 0; j < V; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void BFS(int arr[][V], int start)
{
    bool visited[V] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS traversal starting from vertex: " << start << endl;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < V; i++)
        {
            if (arr[current][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void DFS(int arr[][V], int start)
{
    bool visited[V] = {false};
    stack<int> s;
    s.push(start);
    cout << "DFS traversal start from the vertex: " << start << endl;
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        if (!visited[current])
        {
            visited[current] = true;
            cout << current << " ";
        }
        for (int i = V - 1; i >= 0; i--)
        {
            if (arr[current][i] == 1 && !visited[i])
            {
                s.push(i);
            }
        }
    }
    cout << endl;
}

void DFSRecusiveutil(int arr[][V], int start, vector<bool> &visited)
{
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < V; i++)
    {
        if (arr[start][i] == 1 && !visited[i])
        {
            DFSRecusiveutil(arr, i, visited);
        }
    }
}
void DFSRecursive(int arr[][V], int start)
{
    vector<bool> visited(V, false);
    DFSRecusiveutil(arr, start, visited);
}
int main()
{

    int adjencyMatrix[V][V];
    initialize(adjencyMatrix);
    // displayGraph(adjencyMatrix);
    addEdge(adjencyMatrix, 0, 1);
    addEdge(adjencyMatrix, 2, 1);
    addEdge(adjencyMatrix, 2, 3);
    addEdge(adjencyMatrix, 0, 3);
    displayGraph(adjencyMatrix);
    BFS(adjencyMatrix, 1);
    DFS(adjencyMatrix, 1);
    // DFSRecursive(adjencyMatrix, 1);
}