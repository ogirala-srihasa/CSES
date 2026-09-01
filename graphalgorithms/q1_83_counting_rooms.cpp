#include <bits/stdc++.h>
using namespace std;

void bfs(vector<string>&grid, int r, int c, vector<vector<bool>>&vis){
    vis[r][c] = true;
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        int cr = curr.first;
        int cc = curr.second;
        if(cr > 0 && !vis[cr-1][cc] && grid[cr-1][cc] == '.'){
            q.push({cr-1,cc});
            vis[cr-1][cc] =true;
        }
        if(cc > 0 && !vis[cr][cc-1] && grid[cr][cc-1] == '.'){
            q.push({cr,cc-1});
            vis[cr][cc-1] = true;
        }
        if(cr < grid.size()-1 && !vis[cr+1][cc] && grid[cr+1][cc] == '.'){ 
            q.push({cr+1,cc});
            vis[cr+1][cc] = true;
        }
        if(cc < grid[0].size()-1 && !vis[cr][cc+1] && grid[cr][cc+1] == '.'){ 
            vis[cr][cc+1] = true; 
            q.push({cr,cc+1});
        }
    }
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<string> grid(n);

    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                bfs(grid,i,j,vis);
                ans++;
            }
        }
    }

    cout << ans;
}