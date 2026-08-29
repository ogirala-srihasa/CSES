#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ts = (n*(n+1))/2;

    if(ts%2){
        cout << 0;
        return 0;
    }

    int t = ts/2;

    vector<long long> ahead(ts+1,0);
    vector<long long> curr(ts+1);
    ahead[0] = 1;
    for(int i = n; i > 0; i--){
        for(int j = 0; j <= t; j++){
            curr[j] = ahead[j];
            if(i <= j) curr[j] = (ahead[j] + ahead[j-i])%mod;
        }
        ahead = curr;
    }

    cout << (ahead[t]* 500000004)%mod;



}