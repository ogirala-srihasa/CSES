#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,c,k;
    cin >> n >> m >> k;


    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<long long>> sdis(n+1,vector<long long>(k,LLONG_MAX));
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    //multiset<pair<long long,int>> pq;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0,1});
    sdis[1][0] = 0;
    pair<long long,int> curr;
    while(!pq.empty()){
        curr = pq.top();
        pq.pop();
        if(curr.first <= sdis[curr.second][k-1]){
            for(auto it:adj[curr.second]){
                if(curr.first + it.second < sdis[it.first][k-1]){
                    //pq.erase({sdis[it.first][k-1],it.first});
                    pq.push({curr.first + it.second,it.first});
                    sdis[it.first][k-1] = curr.first + it.second;
                    sort(sdis[it.first].begin(),sdis[it.first].end());
                }
            }
        }
        
    }

    for(auto it:sdis[n]) cout << it << ' ';

}