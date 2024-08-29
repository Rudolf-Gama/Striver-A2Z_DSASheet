#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0) {
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0}); // Store relative position
    
    // Direction vectors for moving up, right, down, and left
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    
    // Explore the four possible directions
    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        // Check if the new position is within the grid, unvisited, and part of an island
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
            dfs(nrow, ncol, n, m, grid, vis, vec, row0, col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix
    set<vector<pair<int, int>>> st; // Set to store unique island shapes
    
    // Traverse the entire grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) { // If it's an unvisited part of an island
                vector<pair<int, int>> vec; // Vector to store the shape of the island
                dfs(i, j, n, m, grid, vis, vec, i, j); // Perform DFS to explore the island
                st.insert(vec); // Insert the island shape into the set
            }
        }
    }
    
    return st.size(); // The size of the set gives the number of distinct islands
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };
    
    int distinctIslands = countDistinctIslands(grid);
    cout << "Number of distinct islands: " << distinctIslands << endl;
    
    return 0;
}
