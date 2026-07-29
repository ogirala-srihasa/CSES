#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;

    cin >> t;
    n = 0;
    vector<int> arr(t);
    for(int test = 0; test  < t; test++){
        cin >> arr[test];
        n = max(arr[test],n);
    }
    vector<vector<long long>> dp(n+1,vector<long long>(2,1));
    for(int i = 2; i <= n; i++){
        dp[i][0] = ((dp[i-1][0] * 4)%mod + dp[i-1][1])%mod;
        dp[i][1] = ((dp[i-1][1] * 2)%mod + dp[i-1][0])%mod;
    }
    for(auto it:arr){
        cout << (dp[it][0] + dp[it][1])%mod << '\n';
    }


}