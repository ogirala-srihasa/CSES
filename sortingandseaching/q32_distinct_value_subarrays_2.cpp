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

    map<int,int> active;
    long long ans = 0;
    int l = 0;
    int r = 0;
    int addr = true;
    while(l < n && r < n){
        
        if(addr) active[arr[r]]++;
        if(active.size() <= t){
            ans += (r-l+1);
            r++;
            addr = true;
        }else{
            active[arr[l]]--;
            if(active[arr[l]] == 0){
                active.erase(arr[l]);
            }
            l++;
            addr = false;
        }
    }

    cout << ans;

}