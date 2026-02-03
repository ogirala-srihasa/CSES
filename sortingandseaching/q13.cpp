#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    map<int,int> hm;
    int l = 0;
    int r = 1;
    int ans = 1;
    hm[arr[0]] = 1;
    while(r < n){
        hm[arr[r]]++;
        if(r-l+1 == hm.size()){
            ans = max(ans,r-l+1);
        }else{
            while(l < r && r-l+1 != hm.size()){
                hm[arr[l]]--;
                if(hm[arr[l]] == 0){
                    hm.erase(arr[l]);
                }
                l++;
            }
        }
        r++;
    }
    cout << ans;
}