#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<string>&board,int r, int c){
    for(int i = 0; i < r; i++){
        if(board[i][c] == 'Q') return false;
    }
    int nr = r-1;
    int nc = c-1;
    while(nr >= 0 && nc >= 0){
        if(board[nr][nc] == 'Q') return false;
        nr--;
        nc--;
    }
    nr = r-1;
    nc = c+1;
    while(nr >= 0 && nc < 8){
        if(board[nr][nc] == 'Q') return false;
        nr--;
        nc++;
    }
    return true;
}
long long func(vector<string>&board,int r){
    if(r == 8) return 1;
    long long ans = 0;
    for(int c = 0; c < 8; c++){
        if(board[r][c] == '.' && issafe(board,r,c)){
            board[r][c] = 'Q';
            ans += func(board,r+1);
            board[r][c] = '.';
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> board(8);
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    cout << func(board,0) << '\n';
}