#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n) {
    ll a = ((n*n)*n)*2;
    ll b = 3*(n*n);
    ll c = 7*n;
    return a + b - c+8;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ll> arr(t+1);
    if(t == 1){ 
        cout << 0;
        return 0;
    }
    if(t == 2) {
        cout << 0 << '\n' << 6;
        return 0;
    }
    arr[1] = 0;
    arr[2] = 6;
    cout << 0 << '\n' << 6;
    for(ll i = 3; i <= t; i++){
        arr[i]  = arr[i-1] + solve(i-1);
        cout << '\n' << arr[i];
    }
}