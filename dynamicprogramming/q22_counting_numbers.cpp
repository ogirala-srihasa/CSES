#include <bits/stdc++.h>
using namespace std;

long long func(vector<int>&s,int i, int prev, int tight, int leadingzero ,vector<vector<vector<vector<long long>>>>&dp){
    if(i == s.size()) return 1;
    if(dp[i][prev][tight][leadingzero] != -1) return dp[i][prev][tight][leadingzero];
    int upper = tight == 1 ? s[i] : 9;
    long long ans = (leadingzero == 1|| prev != 0) ? func(s,i+1,0,(tight== 1 && upper == 0)?1:0, leadingzero,dp) : 0;
    for(int d  = 1; d <= upper; d++){
        if(d != prev) ans += func(s,i+1,d,(tight == 1 && upper == d)?1:0, 0,dp);
    } 

    return dp[i][prev][tight][leadingzero] =  ans;
}
long long solve(long long x){
    int digits = 0;
    long long dx = x;
    while(dx > 0){
        dx /= 10;
        digits++;
    }

    vector<int> s(digits);
    dx = x;
    int i = digits-1;
    while(dx > 0){
        s[i] = dx%10;
        dx /= 10;
        i--;
    }

    vector<vector<vector<vector<long long>>>> dp(digits+1, vector<vector<vector<long long>>>(10,vector<vector<long long>>(2,vector<long long>(2,-1))));

    return func(s,0,0,1,1,dp);




}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a,b;
    cin >> a >> b;

    if(a != 0) cout << solve(b) - solve(a-1);
    else cout << solve(b);


}