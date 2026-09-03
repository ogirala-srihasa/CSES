#include <bits/stdc++.h>
using namespace std;

vector<int> dx  = {-1,1,0,0};
vector<int> dy  = {0,0,-1,1};
vector<char> d  = {'U','D','L','R'};
bool isvalid(int nr, int nc, int n, int m){
    return nr >= 0 && nc >= 0 && nr < n && nc < m;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    queue<pair<int,int>> monsters;
    queue<pair<int,int>> human;

    //vector<vector<bool>> monstervis(n,vector<bool>(m,false));
    vector<vector<char>> humanvis(n,vector<char>(m,'1'));

    vector<vector<char>> grid(n,vector<char>(m,'1'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'M'){
                monsters.push({i,j});
                //monstervis[i][j] = true;
            }else if(grid[i][j] == 'A'){
                human.push({i,j});
                humanvis[i][j] = 'A';
                grid[i][j] = '.';
            }
        }
    }
    pair<int,int> curr;
    int s,nr,nc;
    while(!human.empty()){
        s = monsters.size();
        for(int i = 0; i < s; i++){
            curr = monsters.front();
            monsters.pop();
            for(int j = 0; j < 4; j++){
                nr = curr.first + dx[j];
                nc = curr.second + dy[j];
                if(isvalid(nr,nc,n,m)  && grid[nr][nc] == '.'){
                    grid[nr][nc] = 'M';
                    monsters.push({nr,nc});
                }
            }
        }

        s = human.size();
        for(int i = 0; i < s; i++){
            curr = human.front();
            human.pop();
            if(curr.first == 0 || curr.second == 0 || curr.first == n-1 || curr.second == m-1){
                string ans = "";
                while(humanvis[curr.first][curr.second] != 'A'){
                    ans.push_back(humanvis[curr.first][curr.second]);
                    if(humanvis[curr.first][curr.second] == 'U') curr.first++;
                    else if(humanvis[curr.first][curr.second] == 'D') curr.first--;
                    else if(humanvis[curr.first][curr.second] == 'L') curr.second++;
                    else curr.second--;
                }
                reverse(ans.begin(),ans.end());
                cout << "YES" << '\n' << ans.size() << '\n' << ans;
                return 0;
            }
            for(int j = 0; j < 4; j++){
                nr = curr.first + dx[j];
                nc = curr.second + dy[j];
                if(isvalid(nr,nc,n,m)  && grid[nr][nc] == '.' && humanvis[nr][nc] == '1'){
                    human.push({nr,nc});
                    humanvis[nr][nc] = d[j];
                }
            }

        }
    }

    cout << "NO";


}