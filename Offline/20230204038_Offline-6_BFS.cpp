#include<bits/stdc++.h>
using namespace std;

void bfs(int source, vector<vector<int>>& adj, vector<int>& level, vector<int>& order) {
    int n = adj.size() - 1;
    level.assign(n + 1, -1);
    order.clear();

    queue<int> q;
    level[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u); // record visit order

        for (int v : adj[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m; // number of nodes and edges
    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cout << "Enter source: ";
    cin >> source;

    vector<int> level, order;
    bfs(source, adj, level, order);

    cout << "Visit order: ";
    for (int node : order) cout << node << " ";
    cout << endl;

    cout << "Levels:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << level[i] << endl;
    }

    return 0;
}
