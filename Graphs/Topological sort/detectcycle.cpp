#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        // Calculate in-degrees of all vertices
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        
        // Enqueue all vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        // Process until queue is empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            // Reduce in-degree for all adjacent vertices
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the count of visited nodes is not equal to the number of vertices, there is a cycle
        return (cnt != V);
    }
};

int main() {
    int V = 4;  // Number of vertices
    vector<int> adj[V]; // Adjacency list
    
    // Example graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // This edge creates a cycle

    Solution obj;
    if (obj.isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
