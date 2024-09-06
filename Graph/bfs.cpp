#include<bits/stdc++.h>
using namespace std;

int adj[10][10], n;

void bfs(int v)
{
    static int visited[10] = {0};

    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        cout << v << " ";
        
        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
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

    cout << "BFS Traversal: ";

    bfs(0);
    
    return 0;
}
