#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int>&a, vector<int>&b){
    if(a[1] < b[1]) return true;
    return false;
}

int find(vector<vector<int>>&arr, int start, int i){
    int l = 0;
    int h = i-1;
    int ans = -1;
    int m;
    while(l <= h){
        m = l + (h-l)/2;
        if(arr[m][1] < start){
            ans = m;
            l =m+1;
        }else{
            h = m-1;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(3,0));

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    }

    sort(arr.begin(),arr.end(),compare);
    vector<long long> dp(n);
    dp[0] = arr[0][2];

    for(int i = 1; i < n; i++){
        long long dontpick = dp[i-1];
        long long pick = arr[i][2];
        int li = find(arr,arr[i][0],i);
        if(li != -1) pick += dp[li];

        dp[i] = max(pick,dontpick);

    }

    cout << dp[n-1];


}