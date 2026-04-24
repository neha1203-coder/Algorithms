#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, vector<vector<int> >& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
int main() {
    int V = 5;
    vector<vector<int> > adj(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfs(0, adj, visited);
    return 0;
}