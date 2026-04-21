#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin >> n >> t;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    
    vector<int> curr(t+1, 0);
    vector<int> prev(t+1, 0);
    curr[0] = 1;
    prev[0] = 1;
    for(int i = 1; i <=n; i++){
        for(int ta = 1; ta <= t; ta++){
            if(ta < arr[i-1]){
                curr[ta] = prev[ta];
            }else{
                curr[ta] = (prev[ta] + curr[ta-arr[i-1]])%mod;
            }
        }
        prev = curr;
    }
    
    cout << curr[t];

}