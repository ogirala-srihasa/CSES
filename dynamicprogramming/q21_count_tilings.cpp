#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

void generate(int mask, int row, int newmask, vector<vector<long long>>&dp,int j, int n){

    if(row == n){
        dp[j+1][newmask] = (dp[j+1][newmask]+dp[j][mask])%mod;
        return;
    }

    if(1 << row & mask) generate(mask,row+1,newmask,dp,j,n);
    else{
        if(row +1 < n && !(1 << row+1 & mask)) generate(mask,row+2,newmask,dp,j,n);
        generate(mask,row+1,newmask|(1<<row),dp,j,n);
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    if(n %2 && m% 2){
        cout << 0;
        return 0;
    }
    int dpl = 1 << n;
    vector<vector<long long>> dp(m+1,vector<long long>(dpl,0));

    dp[0][0] = 1;

    for(int j = 0; j < m; j++){
        for(int mask = 0;  mask < dpl; mask++){
            if(dp[j][mask] != 0){
                generate(mask,0,0,dp,j,n);
            }
        }
    }

    cout << dp[m][0];



}