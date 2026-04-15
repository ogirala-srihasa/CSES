#include <bits/stdc++.h>
using namespace std;
bool ispossible(int t, long long m, vector<int>&arr){
    long long count = 0;
    for(auto it:arr){
        count += m/it;
        if(count >= t) return true;
    }
    return false;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    long long l = 0;
    long long h = (1LL * t) * arr.back();
    long long m;
    long long ans;
    while(l <= h){
        m = l + (h-l)/2;
        if(ispossible(t,m,arr)){
            ans = m;
            h = m-1;
        }else{
            l = m+1;
        }
    }

    cout << ans;
}