#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin >> n >> t;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    map<long long, int> hm;
    long long ans = 0;
    long long psum = 0;
    hm[0] = 1;
    for(int i = 0; i < n; i++){
        psum += arr[i];
        if(hm.find(psum - t) != hm.end()){
            ans += hm[psum -t];
        }
        hm[psum]++;

    }

    cout << ans;
}