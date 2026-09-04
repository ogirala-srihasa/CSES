#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,c;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<long long>> sdis(2,vector<long long>(n+1,LLONG_MAX));
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    set<pair<long long ,pair<int,int>>> pq;
    
    pq.insert({0,{0,1}});
    sdis[0][1] = 0;
    pair<long long ,pair<int,int>> curr;
    while(!pq.empty()){
        curr = *(pq.begin());
        pq.erase(pq.begin());
        //if(sdis[curr.second.first][curr.second.second] > curr.first) sdis[curr.second.first][curr.second.second] = curr.first;
        for(auto it:adj[curr.second.second]){
            if(sdis[curr.second.first][curr.second.second] + it.second < sdis[curr.second.first][it.first]){
                pq.erase({sdis[curr.second.first][it.first],{curr.second.first,it.first}});
                pq.insert({sdis[curr.second.first][curr.second.second] + it.second,{curr.second.first,it.first}});
                sdis[curr.second.first][it.first] = sdis[curr.second.first][curr.second.second] + it.second;
            }

            if(curr.second.first == 0 && sdis[0][curr.second.second] + it.second/2 < sdis[1][it.first]){
                pq.erase({sdis[1][it.first],{1,it.first}});
                pq.insert({sdis[0][curr.second.second] + it.second/2,{1,it.first}});
                sdis[1][it.first] = sdis[0][curr.second.second] + it.second/2;
            }
        }
    }

    cout << sdis[1][n];


}