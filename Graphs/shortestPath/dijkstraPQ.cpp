#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int n = adj.size();
    // Min-heap priority queue to store {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Distance vector initialized with a large number (infinity)
    vector<int> dist(n, 1e9);
    dist[src] = 0;  // Distance to the source node is 0
    
    // Start with the source node
    pq.push({0, src});
    
    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        // Traverse all adjacent nodes of the current node
        for (auto it : adj[node]) {
            int adjnode = it.first;   // Adjacent node
            int w = it.second;        // Weight of the edge
            
            // If a shorter path is found
            if (dis + w < dist[adjnode]) {
                dist[adjnode] = dis + w;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Graph represented as an adjacency list
    vector<vector<pair<int, int>>> adj(n);
    
    cout << "Enter the edges (format: u v w, where u and v are nodes and w is the weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // Uncomment this line if the graph is undirected
    }
    
    int src;
    cout << "Enter the source node: ";
    cin >> src;
    
    // Run Dijkstra's algorithm
    vector<int> dist = dijkstra(adj, src);
    
    // Output the shortest distances
    cout << "Shortest distances from node " << src << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == 1e9) {
            cout << "Node " << i << ": Not reachable" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
    
    return 0;
}
