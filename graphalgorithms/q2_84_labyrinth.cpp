#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    pair<int,int> start,end;
    vector<vector<char>> grid(n,vector<char>(m));;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                start = {i,j};
                grid[i][j] = '.';
            }
            if(grid[i][j] == 'B') {
                end = {i,j};
                grid[i][j] = '.';
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    vector<vector<char>> vis(n,vector<char>(m,'0'));
    vis[start.first][start.second] = '1';
    pair<int,int> curr;
    int cr,cc,s;
    while(!q.empty()){
        s = q.size();
        for(int i = 0; i < s; i++){
            curr = q.front();
            if(curr == end){
                cout << "YES" << '\n';
                string ans = "";
                cr = curr.first;
                cc = curr.second;
                while(vis[cr][cc] != '1'){
                    ans.push_back(vis[cr][cc]);
                    if(vis[cr][cc] == 'U') cr++;
                    else if(vis[cr][cc] == 'D') cr--;
                    else if(vis[cr][cc] == 'R') cc--;
                    else cc++;
                }
                reverse(ans.begin(),ans.end());
                cout << ans.size() << '\n';
                cout << ans;
                return 0;
            }
            q.pop();
            cr = curr.first;
            cc = curr.second;
            if(cr > 0 && vis[cr-1][cc] == '0' && grid[cr-1][cc] == '.'){
                q.push({cr-1,cc});
                vis[cr-1][cc] ='U';
            }
            if(cc > 0 && vis[cr][cc-1] == '0' && grid[cr][cc-1] == '.'){
                q.push({cr,cc-1});
                vis[cr][cc-1] = 'L';
            }
            if(cr < grid.size()-1 && vis[cr+1][cc] == '0' && grid[cr+1][cc] == '.'){ 
                q.push({cr+1,cc});
                vis[cr+1][cc] = 'D';
            }
            if(cc < grid[0].size()-1 && vis[cr][cc+1] == '0' && grid[cr][cc+1] == '.'){ 
                vis[cr][cc+1] = 'R'; 
                q.push({cr,cc+1});
            }
        }

    }

    cout << "NO" <<'\n';
    
}