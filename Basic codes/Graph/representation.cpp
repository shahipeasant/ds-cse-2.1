#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    //adjacency matrix
    int adj[n+1][m+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //adjacency list
    vector<int> ad[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        ad[u].push_back(1);
        ad[v].push_back(1);
    }
    return 0;
}