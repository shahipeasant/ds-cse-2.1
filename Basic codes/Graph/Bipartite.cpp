#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int n, vector<vector<int>> &adj, vector<int> &color){
    queue<int> q;
    color.assign(n+1, -1);
    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            color[i] = 0;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v: adj[u]){
                    if(color[v]==-1){
                        color[v] = 1-color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m; // number of nodes and edges
    vector<vector<int>> adj(n+1);
    vector<int> color;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartite(n, adj, color)){
        cout << "The graph is bipartite" << endl;
    }
    else{
        cout << "The graph is not bipartite" << endl;
    }
}