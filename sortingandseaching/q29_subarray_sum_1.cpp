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

    int l = 0;
    int r = 0;
    long long ans = 0;
    int curr_sum = 0;
    bool add_r = true;
    while(l < n && r < n){
        if(add_r) curr_sum += arr[r];
        if(curr_sum == t){
            ans++;
            r++;
            add_r = true;
        }else if(curr_sum < t){
            r++;
            add_r = true;
        }else{
            curr_sum -= arr[l];
            l++;
            add_r = false;
        }
    }

    cout << ans;
}