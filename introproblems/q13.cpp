#include <bits/stdc++.h>
using namespace std;
int func(int n){
    if(n == 1) return 2;
    if(n == 0) return 1;
    if(n%2 == 0){
        int k = func(n/2);
        return k*k;
    }
    else return 2 * func(n-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int fn = func(n);
    vector<vector<int>> ans(fn,vector<int>(n));
    for(int i = 0; i < n; i++){
        int k = func(i+2);
        for(int j = 0; j < fn; j++){
            int c = j%k;
            if(c >= k/4 && c < (3*k)/4) ans[j][i] = 1;
        }
    }
    for(int i = 0; i < fn; i++){
        for(int j = 0; j < n; j++){
            cout<< ans[i][j];
        }
        cout <<'\n';
    }
}