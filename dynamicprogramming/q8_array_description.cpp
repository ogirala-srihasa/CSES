#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> prev (m+1,0);
    vector<int> curr (m+1,0);
    if(arr[0] == 0){
        for(int i = 1; i <= m; i++){
            prev[i] = 1;
        }
    }
    else prev[arr[0]] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] != 0){
            for(int j = 1; j <= m; j++){
                curr[j] = 0;
            }
            curr[arr[i]] = prev[arr[i]];
            if(arr[i] > 1) curr[arr[i]] = (curr[arr[i]] + prev[arr[i]-1])%mod;
            if(arr[i] < m) curr[arr[i]] = (curr[arr[i]] + prev[arr[i]+1])%mod;
        }else{
            for(int j = 1; j <= m; j++){
                curr[j] = prev[j];
                if(j > 1) curr[j] = (curr[j] + prev[j-1])%mod;
                if(j < m) curr[j] = (curr[j] + prev[j+1])%mod;
            }
        }

        prev = curr;
    }

    int ans = 0;
    for(auto it: prev){
        ans = (ans + it)%mod;
    }

    cout << ans;

}