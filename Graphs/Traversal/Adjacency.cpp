#include <iostream>
#include <vector>
#include <utility> // For std::pair

using namespace std;

// Function to create and return the adjacency list of a graph
vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

// Function to print the adjacency list of the graph
void printAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << "Vertex " << i << ":";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << " " << adj[i][j];
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};

    vector<vector<int>> adj = printGraph(V, edges);
    printAdjList(adj);

    return 0;
}
