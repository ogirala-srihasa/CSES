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

    
    vector<int> curr(t+1,-1);
    vector<int> prev(t+1,-1);
    prev[0] = 0;
    curr[0] = 0;

    for(int i = 1; i <=n; i++){
        for(int ta = 1; ta <= t; ta++){
            if(ta < arr[i-1]){
                curr[ta] = prev[ta];
            }else{
                if(prev[ta] == -1){
                    if(curr[ta-arr[i-1]] != -1) curr[ta] = 1 + curr[ta-arr[i-1]]; 
                }else{
                    if (curr[ta-arr[i-1]] != -1) curr[ta] = min(1 + curr[ta-arr[i-1]],prev[ta]);
                    else curr[ta] = prev[ta];
                }
            }
        }
        prev = curr;
    }

    cout << curr[t];

}