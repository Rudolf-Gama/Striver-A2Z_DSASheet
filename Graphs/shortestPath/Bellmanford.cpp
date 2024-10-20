#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Initialize distance array with a large number
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (auto it : edges) {
        int u = it[0], v = it[1], w = it[2];
        if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
            return { -1 };  // Return -1 if a negative cycle is detected
        }
    }

    return dist;
}

int main() {
    // Number of vertices and edges
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    int src = 0;  // Source vertex

    // Run Bellman-Ford algorithm
    vector<int> result = bellmanFord(V, edges, src);

    // Output the result
    if (result[0] == -1) {
        cout << "Negative weight cycle detected" << endl;
    } else {
        cout << "Vertex distances from source " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << ": " << result[i] << endl;
        }
    }
    return 0;
}

