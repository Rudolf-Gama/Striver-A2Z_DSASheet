#include <vector>
#include<bits/stdc++.h>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0; // Handle empty grid case
        int m = grid[0].size();
        int vis[n][m]; // 2D array to keep track of visited cells
        queue<pair<pair<int, int>, int>> q; // Queue to perform BFS

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2; // Mark as visited and rotten
                    q.push({{i, j}, 0}); // Push the cell with time = 0
                } else {
                    vis[i][j] = 0; // Mark as not visited
                }
            }
        }

        int tm = 0; // Time counter
        int drow[] = {-1, 0, 1, 0}; // Row direction array
        int dcol[] = {0, 1, 0, -1}; // Column direction array

        // Perform BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t); // Track the maximum time

            // Check all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1}); // Push the new rotten orange with incremented time
                    vis[nrow][ncol] = 2; // Mark as visited and rotten
                }
            }
        }

        // Check if any fresh orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1; // Fresh orange left that cannot be rotted
                }
            }
        }

        return tm; // Return the total time taken to rot all oranges
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    int result = sol.orangesRotting(grid);
    if (result == -1) {
        cout<<"All oranges cannot be rotted.";
    } else {
        cout<<"Minimum time required to rot all oranges:"<<result<<endl;
    }
    return 0;
}
