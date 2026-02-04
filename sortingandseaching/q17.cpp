#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;

long long pow(int n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(n%2) return (2*pow(n-1))%mod;
    else{
        long long a = pow(n/2);
        return (a*a)%mod;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long ans = 1;
    int l = 0;
    int r = 1;
    map<int,int> hm;
    hm[arr[0]]++;
    while(r < n){
        hm[arr[r]]++;
        if(hm.size() == (r-l+1)){
            ans += pow(r-l);
            ans %= mod;
        }else{
            while(l < r && hm.size() != (r-l+1)){
                hm[arr[l]]--;
                if(hm[arr[l]] == 0) hm.erase(arr[l]);
                l++;
            }
            ans += pow(r-l);
            ans %= mod;
        }
        r++;
    }

    cout << ans;

}