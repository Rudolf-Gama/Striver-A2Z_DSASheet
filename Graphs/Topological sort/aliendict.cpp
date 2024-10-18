#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        queue<int> q;

        // Calculate the indegree of each node
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it] += 1;
            }
        }

        // Push all nodes with indegree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        // Process the nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Reduce the indegree of adjacent nodes
            for (auto it : adj[node]) {
                indegree[it] -= 1;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }

    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];

        // Build the graph by comparing adjacent words
        for (int i = 0; i < n - 1; i++) {
            string s1 = dict[i], s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            // Find the first mismatching character
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // Perform topological sort to find the order of characters
        vector<int> topo = topoSort(k, adj);
        string ans;

        // Convert the topological sort result to characters
        for (auto it : topo) {
            ans += char(it + 'a');
        }

        return ans;
    }
};

// Driver code to test the solution
int main() {
    Solution obj;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;
    int k = 4;

    string result = obj.findOrder(dict, n, k);
    cout << "Order of characters: " << result << endl;

    return 0;
}
