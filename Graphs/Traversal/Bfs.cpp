#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS on the graph and return the traversal
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};       // Visited array to keep track of visited nodes
    queue<int> q;           // Queue for BFS
    vis[0] = 1;             // Mark the starting node (0) as visited
    q.push(0);              // Push the starting node to the queue
    vector<int> bfs;        // Vector to store the BFS traversal

    while (!q.empty()) {
        int node = q.front(); // Get the front node from the queue
        q.pop();              // Remove the front node from the queue
        bfs.push_back(node);  // Add the node to the BFS traversal

        // Iterate through all the adjacent nodes of the current node
        for (auto i : adj[node]) {
            if (!vis[i]) {    // If the node is not visited
                q.push(i);    // Push the node to the queue
                vis[i] = 1;   // Mark the node as visited
            }
        }
    }
    return bfs;
}

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Comment this line if the graph is directed
}

// Function to print the adjacency list of the graph
void printAdjList(vector<int> adj[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ":";
        for (int j : adj[i]) {
            cout << " " << j;
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Print the adjacency list of the graph
    printAdjList(adj, V);

    // Perform BFS on the graph and print the BFS traversal
    vector<int> bfs = bfsOfGraph(V, adj);
    cout << "BFS Traversal: ";
    for (int i : bfs) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
