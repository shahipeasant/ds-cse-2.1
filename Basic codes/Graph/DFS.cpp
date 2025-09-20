#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<int> order;

void dfs(int u) {
    color[u] = 1;
    order.push_back(u);

    for (int v : adj[u]) {
        if (color[v] == 0) {
            dfs(v);
        }
    }

    color[u] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    color.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    cout << "DFS Visit Order: ";
    for (int u : order) cout << u << " ";
    cout << "\n";

    return 0;
}
