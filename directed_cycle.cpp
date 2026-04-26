#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, vector<vector<int> >& adj, 
         vector<bool>& visited, vector<bool>& pathVisited) {
    visited[node] = true;
    pathVisited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, pathVisited)) {
                return true;
            }
        }
        else if (pathVisited[neighbor]) {
            return true;
        }
    }
    pathVisited[node] = false;

    return false;
}
bool hasCycle(int V, vector<vector<int> >& adj) {
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, pathVisited)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int V = 4;
    vector<vector<int> > adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); 

    if (hasCycle(V, adj)) {
        cout << "Cycle Detected";
    } else {
        cout << "No Cycle";
    }

    return 0;
}