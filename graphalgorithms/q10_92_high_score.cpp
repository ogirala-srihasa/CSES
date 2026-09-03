#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    long long c;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<long long> sdis(n+1,LLONG_MAX);
    map<pair<int,int>,long long> edges;
    //vector<int> parent(n+1,-1);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(edges.find({a,b}) != edges.end()){
            edges[{a,b}] = min(edges[{a,b}],-1 * c);
        }else{
            edges[{a,b}] = -1 * c;
        }
        adj[a].push_back(b);
    }

    sdis[1] = 0;
    for(int i = 0; i < n-1; i++){
        if(sdis[1] < 0){
            cout << -1;
            return 0;
        }
        for(auto it:edges){
            if(sdis[it.first.first] == LLONG_MAX) continue;
            if(sdis[it.first.first] + it.second < sdis[it.first.second]){
                sdis[it.first.second] = sdis[it.first.first] + it.second;
                
            }
        }
    }
    queue<int> hm;
    vector<bool> vis(n+1,false);
    for(auto it:edges){
        if(sdis[it.first.first] == LLONG_MAX) continue;
        if(sdis[it.first.first] + it.second < sdis[it.first.second]){
            hm.push(it.first.second);
            vis[it.first.second] = true;
        }
    }

    while(!hm.empty()){
        int curr = hm.front();
        if(curr == n){
            cout << -1;
            return 0;
        }
        hm.pop();
        for(int it:adj[curr]){
            if(!vis[it]){
                hm.push(it);
                vis[it] = true; 
            }
        }
    }

    cout << -1 * sdis[n];

}