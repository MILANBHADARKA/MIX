//dFS with adjacency matrix with recursion

#include <iostream>
using namespace std;

int adj[10][10], n;


void dfs(int v)
{
    static int visited[10] = {0};

    visited[v] = 1;
    cout << v << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{

    int i, j;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix: ";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    cout << "DFS Traversal: ";

    dfs(0);

    return 0;
}