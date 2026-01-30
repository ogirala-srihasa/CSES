#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    vector<string> grid(m);
    for(int i = 0; i < m; i++){
        cin >> grid[i];
    }
    char arr[4] = {'A','B','C','D'};
    char n1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                n1 = grid[i][j];
                for(int k = 0; k < 4; k++){
                    if(n1 != arr[k]){
                        grid[i][j] = arr[k];
                        cout << grid[i][j];
                        break;
                    }
                }
            }else if(i == 0){
                for(int k = 0; k < 4; k++){
                    if(grid[i][j-1] != arr[k] && grid[i][j] != arr[k]){
                        grid[i][j] = arr[k];
                        cout << grid[i][j];
                        break;
                    }
                }
            }else{
                for(int k = 0; k < 4; k++){
                    if(grid[i][j-1] != arr[k] && grid[i][j] != arr[k] && grid[i-1][j] != arr[k]){
                        grid[i][j] = arr[k];
                        cout << grid[i][j];
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
}