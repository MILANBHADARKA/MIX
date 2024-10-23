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




//output
// Enter number of vertices: 5
// Enter the adjacency matrix: 0 10 0 5 0
// 0 0 1 2 0
// 0 0 0 0 4
// 0 3 9 0 2
// 7 0 6 0 0
// Enter source vertex: 0
// Shortest distance from source vertex 0 to all other vertices:
// 0 -> 0 = 0
// 0 -> 1 = 8
// 0 -> 2 = 9
// 0 -> 3 = 5
// 0 -> 4 = 7
// Time Complexity: O(V^2) where V is the number of vertices in the graph.
// Space Complexity: O(V) where V is the number of vertices in the graph.



