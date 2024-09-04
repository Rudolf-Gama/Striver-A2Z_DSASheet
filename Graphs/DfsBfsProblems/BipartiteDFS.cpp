#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int node, int col, vector<int> &color, vector<int> adj[]) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, color, adj) == false)
                    return false;
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    int V = 4;  // Number of vertices
    vector<int> adj[V];  // Adjacency list

    // Example graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    
    Solution obj;
    if (obj.isBipartite(V, adj)) {
        cout << "The graph is Bipartite." << endl;
    } else {
        cout << "The graph is not Bipartite." << endl;
    }

    return 0;
}
