#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<long long>> dp(n,vector<long long>(n));
    vector<vector<long long>> sumlr(n,vector<long long>(n));
    //sumlr[l][r] = sumlr[l-1][r] - arr[l-1];
    sumlr[0][0] = (long long)arr[0];
    for(int r = 1; r < n; r++){
        sumlr[0][r] += sumlr[0][r-1] + (long long)arr[r];
    }
    for(int l = 1; l < n; l++){
        for(int r = l; r < n; r++){
            sumlr[l][r] = sumlr[l-1][r] - (long long)arr[l-1]; 
        }
    }
    for(int l = n-1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(l == r){
                dp[l][r] = (long long)arr[l];
                continue;
            }
            dp[l][r] = max((long long)arr[l] + sumlr[l+1][r] - dp[l+1][r], (long long)arr[r] + sumlr[l][r-1] - dp[l][r-1]);
        }
    }

    cout << dp[0][n-1] << ' ';

}