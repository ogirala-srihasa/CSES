#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

void dfs(int i, vector<vector<int>> &adj, vector<long long>& ways, vector<bool>& vis, int n){
    
    if(i == n){
        ways[n] = 1;
        vis[n] = true;
        return;
    }

    for(int nb:adj[i]){
        if(!vis[nb]) dfs(nb,adj,ways,vis,n);
        ways[i] = (ways[i] + ways[nb])%mod;
    }

    vis[i] =true;
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

    vector<long long> ways(n+1,0);
    vector<bool> vis(n+1,false);
    dfs(1,adj,ways,vis,n);
    cout << ways[1];
    
    

}