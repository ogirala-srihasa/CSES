#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<vector<bool>> vis(n,vector<bool>(n,false));
    string ans = "";
    vis[0][0] = true;
    ans.push_back(grid[0][0]);
    vector<pair<int,int>> actlis;
    actlis.push_back({0,0});
    
    while(ans.length() < 2*n-1){
        char min_char = 'Z' + 1;
        for(auto it:actlis){
            if(it.first+1 < n && min_char > grid[it.first+1][it.second]) min_char = grid[it.first+1][it.second];
            if(it.second+1 < n && min_char > grid[it.first][it.second+1]) min_char = grid[it.first][it.second+1];
        }

        ans.push_back(min_char);
        vector<pair<int,int>> neighbours;
        for(auto it:actlis){
            if(it.first+1 < n && min_char == grid[it.first+1][it.second] && !vis[it.first+1][it.second]){
                vis[it.first+1][it.second] = true;
                neighbours.push_back({it.first+1,it.second});
            }
            //if(it.second+1 < n && min_char == grid[it.first][it.second+1]) min_char = grid[it.first][it.second+1];
            if(it.second+1 < n && min_char == grid[it.first][it.second+1] && !vis[it.first][it.second+1]){
                vis[it.first][it.second+1] = true;
                neighbours.push_back({it.first,it.second+1});
            }
        }

        actlis = neighbours;



    }
    cout << ans;



}