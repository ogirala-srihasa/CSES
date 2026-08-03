#include <bits/stdc++.h>
using namespace std;



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> a >> b;

    vector<vector<long long>> dp(a+1,vector<long long>(b+1,-1));
    int i = 0;
    while(i <= a && i <= b){
        dp[i][i] = 0;
        i++;
    }
    long long c;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j) continue;
            c= LLONG_MAX;
            for(int k = 1; k < i; k++){
                if(dp[k][j] != -1 && dp[i-k][j] != -1) c = min(c,1+dp[k][j] +dp[i-k][j]);
            }
            for(int k = 1; k < j; k++){
                if(dp[i][k] != -1 && dp[i][j-k] != -1) c = min(c,1+dp[i][k] +dp[i][j-k]);
            }

            dp[i][j] = (c == LLONG_MAX)? -1:c;

        }
    }

    cout << dp[a][b];
}