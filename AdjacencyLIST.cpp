  #include <iostream>
#include <vector>
using namespace std;

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= nodes; i++) {
        cout << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    
    cout << "\nGraph Visualization:" << endl;
    for (int i = 1; i <= nodes; i++) {
        cout << i;
        for (int v : adj[i]) {
            cout << " -> " << v;
        }
        cout << endl;
    }

    return 0;
}