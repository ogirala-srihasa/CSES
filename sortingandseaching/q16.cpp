#include <bits/stdc++.h>
using namespace std;

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
            ans += r -l +1;
        }else{
            while(l < r && hm.size() != (r-l+1)){
                hm[arr[l]]--;
                if(hm[arr[l]] == 0) hm.erase(arr[l]);
                l++;
            }
            ans += r -l +1;
        }
        r++;
    }

    cout << ans;

}