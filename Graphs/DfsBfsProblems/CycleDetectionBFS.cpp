#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in an undirected graph using BFS
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1; // Mark the source node as visited
    queue<pair<int, int>> q; // Queue to perform BFS, stores {current node, parent node}
    q.push({src, -1}); // Push the source node with no parent (-1)

    while (!q.empty()) {
        int node = q.front().first; // Current node
        int parent = q.front().second; // Parent of the current node
        q.pop();

        for (auto it : adj[node]) { // Traverse all adjacent nodes
            if (!vis[it]) { // If the adjacent node is not visited
                vis[it] = 1; // Mark it as visited
                q.push({it, node}); // Push it to the queue with the current node as parent
            } else if (parent != it) { // If the adjacent node is visited and it's not the parent
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle found
}

// Function to check if there's a cycle in the graph
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0}; // Initialize the visited array with 0 (unvisited)
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) { // If the node is not visited
            if (detect(i, adj, vis)) { // Check for cycle starting from this node
                return true; // Cycle found
            }
        }
    }
    return false; // No cycle found in any component
}

int main() {
    int V, E;
    cin >> V >> E; // Number of vertices and edges
    vector<int> adj[V]; // Adjacency list

    // Input the edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    // Check if the graph contains a cycle
    if (isCycle(V, adj)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle detected\n";
    }

    return 0;
}
