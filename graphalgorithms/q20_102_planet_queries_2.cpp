#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int>&depth, vector<int>&cycle_id, vector<int>&cycle_len, vector<int>&cycle_pos, vector<bool>&vis, vector<bool>&pathvis, vector<vector<int>>&adj){
     
    pathvis[i] = true;
    int nb = adj[i][0];
    if(pathvis[nb]){
        int curr = nb;
        int len = 0;
        while(curr != i){
            depth[curr] = 0;
            cycle_id[curr] = nb;
            cycle_pos[curr] = len;
            len++; 
            curr = adj[curr][0];
        }
        depth[curr] = 0;
        cycle_id[curr] = nb;
        cycle_pos[curr] = len;
        len++; 
        cycle_len[nb] = len;

    }else if(vis[nb]){
        depth[i] = 1 + depth[nb];
        cycle_id[i] = cycle_id[nb];
        cycle_len[i] = cycle_len[nb];


    }else{
        dfs(nb,depth,cycle_id,cycle_len,cycle_pos,vis,pathvis,adj);
        if(depth[i] == -1) depth[i] = depth[nb] + 1;
        cycle_id[i] = cycle_id[nb];
    }

    pathvis[i] = false;
    vis[i] = true;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> jump(n+1,vector<int>(32,0));
    vector<int> depth(n+1,-1);
    vector<int> cycle_id(n+1,0);
    vector<int> cycle_len(n+1,0);
    vector<int> cycle_pos(n+1,-1);
    for(int i = 1; i <= n; i++){
        cin >> jump[i][0];
    }

    for(int i = 1; i < 32; i++){
        for(int planet = 1; planet <= n; planet++){
            jump[planet][i] = jump[jump[planet][i-1]][i-1];
        }
    }

    vector<bool> pathvis(n+1,false);
    vector<bool> vis(n+1,false);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i,depth,cycle_id,cycle_len,cycle_pos,vis,pathvis,jump);
        }
    }

    for(int i = 0; i < m; i++){
        int start,end;
        cin >> start >> end;

        if(cycle_id[start] != cycle_id[end]){
            cout << -1 << '\n';
            continue;
        }

        if(depth[start] < depth[end]){
            cout << -1 << '\n';
            continue;
        }

        if(depth[start] != 0 && depth[end] != 0){
            int k = depth[start] - depth[end];
            for(int bit = 0; bit < 32; bit++){
                if(k >> bit & 1){
                    start = jump[start][bit];
                }
            }
            if(start == end){
                cout << k << '\n';
            }else{
                cout << -1 << '\n';
            }
            continue;
        }

        if(depth[start] == 0 && depth[end] == 0){
            cout << (cycle_len[cycle_id[start]] + cycle_pos[end] - cycle_pos[start])%cycle_len[cycle_id[start]] << '\n';
            continue;
        }

        if(depth[start] != 0 && depth[end] == 0){
            int k = depth[start];
            for(int bit = 0; bit < 32; bit++){
                if(k >> bit & 1){
                    start = jump[start][bit];
                }
            }
            cout << k + (cycle_len[cycle_id[start]] + cycle_pos[end] - cycle_pos[start])%cycle_len[cycle_id[start]] << '\n';
            continue;

        }


    }



}