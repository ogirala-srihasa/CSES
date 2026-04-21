#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n < 10){
        cout << 1;
        return 0;
    }
    vector<int> dp(n+1,-1);
    for(int i = 1; i < 10; i++){
        dp[i] = 1;
    }
    dp[0] = 0;
    int c,t;
    for(int i = 10; i <= n; i++){
        t = i;
        for(int j = 1; j <= 7; j++){
            c = t % 10;
            t /= 10;
            if(c == 0) continue;
            if(dp[i] == -1) dp[i] = 1 + dp[i-c];
            else dp[i]  = min(dp[i],1+dp[i-c]);
        }
    }

    cout << dp[n];

}