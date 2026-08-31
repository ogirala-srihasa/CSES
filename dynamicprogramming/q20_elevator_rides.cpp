#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,lim;
    cin >> n >> lim;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());
    int dpl = 1 << n;
    vector<pair<int,int>> dp(dpl);
    dp[0] = {1,0};
    for(int i = 1; i < dpl; i++){
        dp[i] ={INT_MAX,-1};
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                pair<int,int> prev = dp[i ^ (1 << j)];
                if(prev.second + arr[j] <= lim){
                    if(dp[i].first > prev.first || (dp[i].first == prev.first && dp[i].second > prev.second + arr[j] )){
                        dp[i] = {prev.first,prev.second + arr[j]};
                    }
                }else{
                    int mini = min(prev.second,arr[j]);
                    if(dp[i].first > prev.first + 1 || (dp[i].first == prev.first + 1 && dp[i].second > mini )){
                        dp[i] = {prev.first+1,mini};
                    }

                }
            }
        }
    }


    cout << dp[dpl-1].first;


}