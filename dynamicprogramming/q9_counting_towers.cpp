#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;

    cin >> t;
    for(int test = 0; test  < t; t++){
        cin >> n;
        if(n == 1) cout << 2 << '\n';
        else if(n == 2) cout << 8 << '\n';
        else{
            vector<int> dp(n+1);
            dp[1] = 2;
            dp[2] = 8;
            
        }
    }


}