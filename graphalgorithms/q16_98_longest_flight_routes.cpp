#include <bits/stdc++.h>
using namespace std;

void dfs(int i , vector<vector<int>> &adj, vector<int>&next, vector<int>&count,vector<bool>&vis, int n){

    if(i == n) return;
    for(int nb:adj[i]){
        if(!vis[nb]) dfs(nb,adj,next,count,vis,n);
        if(count[nb] != -1 && 1+count[nb] > count[i]){
            next[i] = nb;
            count[i] = 1+count[nb];
        } 
    }
    vis[i] = true;

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

    vector<int> next(n+1,-1);
    vector<int> count(n+1,-1);
    vector<bool> vis(n+1,false);
    count[n] = 1;
    dfs(1,adj,next,count,vis,n);
    if(count[1] == 0 || count[1] == -1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << count[1] << '\n';
    int node = 1;
    while(node != -1){
        cout << node << ' ';
        node = next[node];
    }
    
}