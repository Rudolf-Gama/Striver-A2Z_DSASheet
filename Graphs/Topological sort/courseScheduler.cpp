#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if it is possible to finish all courses given the prerequisites.
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        // Create adjacency list
        vector<int> adj[N];
        for (auto it : prerequisites) {
            adj[it.first].push_back(it.second);
        }

        // Calculate in-degrees of all vertices
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        
        // Enqueue all vertices with in-degree 0
        for (int i = 0; i < N; i++) {
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

        // If the count of visited nodes is equal to the number of vertices, it is possible to complete all courses
        return (cnt == N);
    }
};

int main() {
    Solution obj;

    int N = 4; // Number of courses
    int P = 3; // Number of prerequisite pairs
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}}; // Prerequisite pairs

    if (obj.isPossible(N, P, prerequisites)) {
        cout << "It is possible to finish all courses" << endl;
    } else {
        cout << "It is not possible to finish all courses" << endl;
    }

    return 0;
}
