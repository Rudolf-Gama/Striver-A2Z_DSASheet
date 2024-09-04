#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);  // Array to store the in-degree of each node
        queue<int> q;  // Queue to store nodes with in-degree 0
        vector<int> ans;  // Vector to store the topological order
        
        // Calculate in-degree of each node
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it] += 1;
            }
        }
        
        // Push all nodes with in-degree 0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process nodes in the queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // Reduce the in-degree of adjacent nodes
            for (auto it : adj[node]) {
                indegree[it] -= 1;
                if (indegree[it] == 0) {
                    q.push(it);  // Push the node if in-degree becomes 0
                }
            }
        }
        
        return ans;  // Return the topological order
    }
};

int main() {
    int V = 6;  // Number of vertices
    vector<int> adj[V];

    // Adding edges to the adjacency list
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> topo = obj.topoSort(V, adj);

    // Print the topological order
    for (auto it : topo) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
