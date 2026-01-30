#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
bool issafe(int r, int c, int n){
    return r < n && c < n && r > -1 && c > -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n][n];
    queue<pair<int,int>> q;
    long long d = 0;
    q.push({0,0});
    vector<vector<int>> vis(n,vector<int>(n,0));
    vis[0][0] = 1;
    int s;
    pair<int,int> curr;
    while(!q.empty()){
        s = q.size();
        for(int i = 0; i < s; i++){
            curr = q.front();
            q.pop();
            arr[curr.first][curr.second] = d;
            for(int j = 0; j < 8;j++){
                if(issafe(curr.first+dx[j],curr.second+dy[j],n) && vis[curr.first+dx[j]][curr.second+dy[j]] == 0){
                    q.push({curr.first+dx[j],curr.second+dy[j]});
                    vis[curr.first+dx[j]][curr.second+dy[j]] = 1;
                }
            }
        }
        d++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}