#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int,int> hm;
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        hm[arr[i]]++;
    }

    long long ans = 1;
    for(auto it:hm){
        ans = (ans * ((it.second+1) % mod))%mod;
    }

    cout << ans-1;

}