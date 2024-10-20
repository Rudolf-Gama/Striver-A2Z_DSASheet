#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shortestDistance(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    // Step 1: Replace all -1 values with a large number to indicate no connection
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1) {
                mat[i][j] = 1e9;  // A large number to represent infinity
            }
        }
    }
    
    // Step 2: Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {        // For each intermediate vertex
        for (int i = 0; i < n; i++) {    // For each starting vertex
            for (int j = 0; j < m; j++) { // For each destination vertex
                if (mat[i][k] != 1e9 && mat[k][j] != 1e9) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }
    
    // Step 3: Replace large numbers back to -1 to indicate no possible path
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1e9) {
                mat[i][j] = -1;  // No path
            }
        }
    }
}

int main() {
    // Define the matrix
    vector<vector<int>> mat = {
        {0, 3, -1, 7},
        {-1, 0, 2, -1},
        {-1, -1, 0, 1},
        {6, -1, -1, 0}
    };

    // Apply the shortestDistance function
    shortestDistance(mat);

    // Print the result matrix
    cout << "The shortest distances between every pair of vertices are:" << endl;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
