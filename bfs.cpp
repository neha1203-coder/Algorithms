#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int V, vector<vector<int> >& adj) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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
    bfs(V, adj);
    return 0;
}