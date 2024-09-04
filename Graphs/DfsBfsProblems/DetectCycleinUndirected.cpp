#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathvis) {
    vis[node] = 1;
    pathvis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, adj, vis, pathvis)) {
                return true;
            }
        } else if (pathvis[it]) {
            return true;
        }
    }

    pathvis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> pathvis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathvis)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 4;
    vector<int> adj[V];

    // Defining the adjacency list
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    if (isCyclic(V, adj)) {
        cout << "The graph has a cycle.\n";
    } else {
        cout << "The graph does not have a cycle.\n";
    }

    return 0;
}
