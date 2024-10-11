#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
    // Create adjacency list
    vector<int> adj[N];
    for(auto it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // Initialize distance array
    int dist[N];
    for(int i = 0; i < N; i++) {
        dist[i] = 1e9; // Assign large value initially (infinity)
    }

    // BFS starting from the source node
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it: adj[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    // Prepare answer array
    vector<int> ans(N, -1);
    for(int i = 0; i < N; i++) {
        if(dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}

int main() {
    int N = 5;  // Number of nodes
    int M = 6;  // Number of edges
    int src = 0;  // Source node

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {2, 4}};

    vector<int> result = shortestPath(edges, N, M, src);

    cout << "Shortest distances from source " << src << ": ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
