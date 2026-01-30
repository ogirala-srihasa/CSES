#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                arr[i][j] = 0;
                continue;
            }
            set<int> curr;
            for(int r = 0; r < i; r++){
                curr.insert(arr[r][j]);
            }
            for(int c= 0; c < j; c++){
                curr.insert(arr[i][c]);
            }
            int k = 0;
            for(auto it:curr){
                if(k == it) k++;
                else{
                    break;
                }
            }
            arr[i][j] = k;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}