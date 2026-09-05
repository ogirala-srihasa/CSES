#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,c;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    vector<long long> sdis(n+1,LLONG_MAX);
    vector<long long> ways(n+1,0);
    vector<int> minsize(n+1,-1);
    vector<int> maxsize(n+1,-1);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0,1});
    sdis[1] = 0;
    ways[1] = 1;
    minsize[1] = 0;
    maxsize[1] = 0;
    pair<long long,int> curr;
    while(!pq.empty()){
        curr = pq.top();
        pq.pop();
        if(curr.first <= sdis[curr.second]){
            for(auto it:adj[curr.second]){
                if(curr.first + it.second < sdis[it.first]){
                    pq.push({curr.first + it.second,it.first});
                    sdis[it.first] = curr.first + it.second;
                    ways[it.first] = ways[curr.second];
                    minsize[it.first] = 1 + minsize[curr.second];
                    maxsize[it.first] = 1 + maxsize[curr.second];
                }else if(curr.first + it.second == sdis[it.first]){
                    sdis[it.first] = curr.first + it.second;
                    ways[it.first] = (ways[it.first] + ways[curr.second])%mod;
                    minsize[it.first] = min(minsize[it.first],1 + minsize[curr.second]);
                    maxsize[it.first] = max(maxsize[it.first],1+maxsize[curr.second]);
                }
            }
        }
    }

    cout << sdis[n] << ' ' << ways[n] << ' ' << minsize[n] << ' ' << maxsize[n];
}