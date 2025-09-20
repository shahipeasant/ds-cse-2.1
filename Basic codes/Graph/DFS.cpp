#include <bits/stdc++.h>
using namespace std;

// DFS function: color, order, and cycleCount are passed by reference
void dfs(int u, const vector<vector<int>> &adj, vector<int> &color,
         vector<int> &order, int &cycleCount) 
{
    color[u] = 1;       // visiting
    order.push_back(u);  // record visit order

    for (int v : adj[u]) {
        if (color[v] == 0) {
            dfs(v, adj, color, order, cycleCount);
        } 
        else if (color[v] == 1) {
            // found a back edge -> cycle detected
            cycleCount++;
        }
    }

    color[u] = 2; // finished
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> color(n + 1, 0);
    vector<int> order;
    int cycleCount = 0;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i, adj, color, order, cycleCount);
        }
    }

    cout << "DFS Visit Order: ";
    for (int u : order) cout << u << " ";
    cout << "\nNumber of cycles (back edges): " << cycleCount << "\n";

    return 0;
}
