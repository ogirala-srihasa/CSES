#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    map<int, int> hm;
    long long ans = 0;
    int psum = 0;
    hm[0] = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            psum =  (psum + (n - (abs(arr[i])%n)) )%n;
        }
        else psum = (psum + arr[i])%n;
        if(hm.find(psum) != hm.end()){
            ans += hm[psum];
        }
        hm[psum]++;

    }

    cout << ans;
}