#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Priority queue to store {weight, node}, sorted by weight (min-heap)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);  // Visited array to track visited nodes
        int sum = 0;            // Sum to store the total weight of the MST

        // Start from node 0 with weight 0
        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int wt = it.first;
            pq.pop();

            // If the node is already visited, skip it
            if (vis[node] == 1) continue;
            vis[node] = 1;  // Mark the node as visited
            sum += wt;      // Add the edge weight to the MST sum

            // Traverse all adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];

                // If the adjacent node is not visited, push it into the priority queue
                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;  // Return the total weight of the MST
    }
};

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj[V];

    // Example graph (undirected with weights)
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[3].push_back({2, 7});
    adj[4].push_back({2, 5});

    Solution obj;
    int result = obj.spanningTree(V, adj);
    cout << "Total weight of the Minimum Spanning Tree is: " << result << endl;

    return 0;
}
