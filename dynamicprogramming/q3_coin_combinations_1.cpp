#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin >> n >> t;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int> dp(t+1,0);
    dp[0] = 1;
    for(int ta = 1; ta <= t; ta++){
        for(int i = 0; i < n; i++){
            if(ta < arr[i]) break;
            if(dp[ta] + dp[ta-arr[i]] >= mod){
                dp[ta] = dp[ta] + dp[ta-arr[i]] - mod;
            }
            else dp[ta] = (dp[ta] + dp[ta-arr[i]]);
        }
    }

    cout << dp[t];


}