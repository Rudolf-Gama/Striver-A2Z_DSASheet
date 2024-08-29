#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<int> Adj[], vector<int> &vis) {
    vis[node] = 1; // Mark the node as visited
    for (auto it : Adj[node]) { // Traverse all the adjacent nodes
        if (!vis[it]) { // If the node is not visited, recursively call DFS
            dfs(it, Adj, vis);
        }
    }
}


int numProvinces(vector<vector<int>> adj, int V) {
    // Convert the adjacency matrix to adjacency list
    vector<int> Adj[V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1 && i != j) { // If there is an edge and it's not a self-loop
                Adj[i].push_back(j);
                Adj[j].push_back(i);
            }
        }
    }
    
    vector<int> vis(V, 0); // Initialize visited vector
    int cnt = 0; // Initialize province count
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) { // If the node is not visited
            cnt++; // Increment province count
            dfs(i, Adj, vis); // Perform DFS from this node
        }
    }
    
    return cnt; // Return the total number of provinces
}

int main() {
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    int V = adj.size();
    
    cout << "Number of Provinces: " << numProvinces(adj, V) << endl;

    return 0;
}
