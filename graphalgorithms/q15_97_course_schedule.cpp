#include <bits/stdc++.h>
using namespace std;

bool detectandprintcycle(int i, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>& pathvis){
    vis[i] = true;
    pathvis[i] = true;
    for(int nb:adj[i]){
        if(pathvis[nb]){
            return true;
        }
        if(!vis[nb]){
            if(detectandprintcycle(nb,adj,vis,pathvis)){
                return true;
            };
        }
    }

    pathvis[i] = false;
    return false;
}

void dfs(int i,vector<vector<int>> &adj, vector<bool>&vis, stack<int>&topo){

    vis[i] = true;

    for(int nb:adj[i]){
        if(!vis[nb]) dfs(nb,adj,vis,topo);
    }

    topo.push(i);

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<bool> vis1(n+1,false), pathvis(n+1,false);
    for(int i = 1; i <= n; i++){
        if(!vis1[i] && detectandprintcycle(i,adj,vis1,pathvis)){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<bool> vis(n+1, false);
    stack<int> topo;

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i,adj,vis,topo);
    }

    while(!topo.empty()){
        cout << topo.top() << ' ';
        topo.pop();
    }
}