#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, vector<vector<int> >& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
int countComponents(int V, vector<vector<int> >& adj) {
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;  
        }
    }
    return count;
}
int main() {
    int V = 6;
    vector<vector<int> > adj(V);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    int result = countComponents(V, adj);
    cout << "Number of Connected Components: " << result;
    return 0;
}