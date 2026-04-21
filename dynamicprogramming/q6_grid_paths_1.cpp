#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout << 0;
        return 0;
    }
    vector<int> curr(n,0);
    vector<int> prev(n,0);
    prev[0] = 1;
    for(int i = 1; i < n; i++){
        if(grid[0][i] == '*') break;
        prev[i] = 1;
    }
    int c;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*'){
                curr[j] = 0;
                continue;
            }
            c = j > 0 ? curr[j-1] + prev[j] : prev[j];
            curr[j] = c >= mod ? c-mod : c;
        }
        prev = curr;
    }

    cout << prev[n-1];
}