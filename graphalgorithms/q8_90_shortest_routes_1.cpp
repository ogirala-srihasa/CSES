#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,c;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    vector<long long> sdis(n+1,LLONG_MAX);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    set<pair<long long,int>> pq;
    
    pq.insert({0,1});
    sdis[1] = 0;
    pair<long long,int> curr;
    while(!pq.empty()){
        curr = *(pq.begin());
        pq.erase(pq.begin());
        for(auto it:adj[curr.second]){
            if(sdis[curr.second] + it.second < sdis[it.first]){
                pq.erase({sdis[it.first],it.first});
                pq.insert({sdis[curr.second] + it.second,it.first});
                sdis[it.first] = sdis[curr.second] + it.second;
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << sdis[i] << ' ';


}