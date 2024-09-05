#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the order of courses to take given the prerequisites.
    vector<int> findOrder(int n, int m, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        
        for (int i = 0; i < m; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        
        // Enqueue all vertices with in-degree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        
        // Process until queue is empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // Reduce in-degree for all adjacent vertices
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the number of courses in the answer list is equal to the total number of courses, return the order
        return (ans.size() == n) ? ans : vector<int>{};
    }

    vector<int> findOrderMy(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
         vector<int> adj[n];
         for(int i=0;i<m;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
         }
	     vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
       reverse(ans.begin(),ans.end());
       vector<int> a;
       return (ans.size()==n) ? ans : a;
    }
};


int main() {
    Solution obj;
    
    int n = 4; // Number of courses
    int m = 3; // Number of prerequisite pairs
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}}; // Prerequisite pairs
    
    vector<int> order = obj.findOrderMy(n, m, prerequisites);
    
    if (order.empty()) {
        cout << "It's not possible to complete all courses" << endl;
    } else {
        cout << "Order of courses to complete: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
