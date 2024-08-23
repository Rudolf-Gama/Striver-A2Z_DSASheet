#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and check for cycles in the graph
bool dfs(int node, int parent, vector<int> adj[], int vis[]) {
    vis[node] = 1; // Mark the current node as visited

    for (auto it : adj[node]) { // Traverse all adjacent nodes
        if (!vis[it]) { // If the adjacent node is not visited
            if (dfs(it, node, adj, vis)) { // Recursively perform DFS
                return true; // Cycle detected
            }
        } else if (parent != it) { // If the adjacent node is visited and is not the parent
            return true; // Cycle detected
        }
    }
    return false; // No cycle found
}

// Function to check if there's a cycle in the graph
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0}; // Initialize the visited array with 0 (unvisited)
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) { // If the node is not visited
            if (dfs(i, -1, adj, vis)) { // Check for a cycle starting from this node
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
