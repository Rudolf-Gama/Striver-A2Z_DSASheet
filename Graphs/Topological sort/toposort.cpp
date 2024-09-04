#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1;  // Mark the node as visited
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, st, adj);  // Recursive call for unvisited neighbors
            }
        }
        st.push(node);  // Push the node onto the stack after visiting all its neighbors
    }
    
    vector<int> topoSort(int V, vector<int> adj[]) {
        stack<int> st;  // Stack to store the topological order
        vector<int> vis(V, 0);  // Visited array to keep track of visited nodes
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, st, adj);  // Perform DFS for each unvisited node
            }
        }
        
        vector<int> ans;  // Vector to store the final topological order
        while(!st.empty()) {
            ans.push_back(st.top());  // Get elements from the stack
            st.pop();
        }
        return ans;
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
    for(auto it: topo) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
