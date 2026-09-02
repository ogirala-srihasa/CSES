#include <bits/stdc++.h>
using namespace std;

bool assigncolor(int i,vector<vector<int>>& adjlist, vector<int>& color){
    color[i] = 1;
    queue<int> q;
    q.push(i);
    int curr,nc;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        nc = color[curr] == 1 ? 2 : 1;
        for(int nb:adjlist[curr]){
            if(color[nb] == -1){
                color[nb] = nc;
                q.push(nb);
            }else if(color[nb] == nc) continue;
            else return false;
        }
    }

    return true;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    cin >> n >> m;

    vector<vector<int>> adjlist(n+1);
    vector<int> color(n+1,-1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
    bool ispossible = true;
    for(int i = 1; i <= n; i++){

        if(color[i] == -1){
            ispossible = ispossible && assigncolor(i,adjlist,color);
        }
    }

    if(ispossible){
        for(int i = 1;i <= n; i++) cout << color[i] << ' ';
    }else cout << "IMPOSSIBLE";


}