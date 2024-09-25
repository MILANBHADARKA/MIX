// Find the Shortest Path using Dijkstra’s Algorithm

#include<bits/stdc++.h>

using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[n][n];
    cout << "Enter the adjacency matrix: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[n];
    bool visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distance from source vertex " << src << " to all other vertices: " << endl;
    for (int i = 0; i < n; i++) {
        cout << src << " -> " << i << " = " << dist[i] << endl;
    }

    return 0;
}

