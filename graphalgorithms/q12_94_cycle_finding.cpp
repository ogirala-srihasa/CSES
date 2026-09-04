#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    long long c;
    cin >> n >> m;

    //vector<vector<pair<int,int>>> adj(n+1);
    vector<long long> sdis(n+1,0);
    map<pair<int,int>,long long> edges;
    vector<int> parent(n+1,-1);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(edges.find({a,b}) != edges.end()){
            edges[{a,b}] = min(edges[{a,b}],c);
        }else{
            edges[{a,b}] = c;
        }
        //adj[a].push_back({b,c});
    }

    sdis[1] = 0;
    for(int i = 0; i < n-1; i++){
        for(auto it:edges){
            //if(sdis[it.first.first] == LLONG_MAX) continue;
            if(sdis[it.first.first] + it.second < sdis[it.first.second]){
                sdis[it.first.second] = sdis[it.first.first] + it.second;
                parent[it.first.second] = it.first.first;
                
            }
        }
    }
    int ncycle = -1;
    for(auto it:edges){
        //if(sdis[it.first.first] == LLONG_MAX) continue;
        if(sdis[it.first.first] + it.second < sdis[it.first.second]){
            if(ncycle == -1) ncycle = it.first.first;
            parent[it.first.second] = it.first.first;
        }
    }

    if(ncycle != -1){
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            ncycle = parent[ncycle];
        }
        int cur = ncycle;
        vector<int> cycle;
        cycle.push_back(ncycle);
        cur = parent[cur];
        while(cur != ncycle) {
            cycle.push_back(cur);
            cur = parent[cur];
        }
        cycle.push_back(ncycle);
        reverse(cycle.begin(),cycle.end());
        for(auto it: cycle) cout << it << ' ';

    }
    else  cout << "NO";
    //cout << -1 * sdis[n];

}