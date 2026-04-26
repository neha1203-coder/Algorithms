#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, int parent, vector<vector<int> >& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}
bool hasCycle(int V, vector<vector<int> >& adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int V = 5;
    vector<vector<int> > adj(V);
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(1); 
    adj[1].push_back(3);

    if (hasCycle(V, adj)) {
        cout << "Cycle Detected";
    } else {
        cout << "No Cycle";
    }

    return 0;
}