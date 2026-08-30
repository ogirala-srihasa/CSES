#include <bits/stdc++.h>
using namespace std;

void computepge(vector<int>&arr,vector<int>&pge){
    stack<int> st;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if(st.empty()){
            pge[i] = -1;
        }else{
            pge[i] = st.top();
        }
        st.push(i);
    }
}

void computenge(vector<int>&arr,vector<int>&nge){
    stack<int> st;
    int n = arr.size();
    for(int i = n-1; i >= 0; i--){

        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if(st.empty()){
            nge[i] = n;
        }else{
            nge[i] = st.top();
        }
        st.push(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    vector<pair<int,int>> cpy(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        cpy[i] = {arr[i], i};
    }

    sort(cpy.begin(), cpy.end());
    
    vector<int> pge(n);
    vector<int> nge(n);
    vector<int> dp(n, 1);
    
    computepge(arr, pge);
    computenge(arr, nge);
    
    int ans = 0;

    for(int i = n-1; i >= 0; i--){
        int curr = cpy[i].second;
        int p = pge[curr];
        int ng = nge[curr];
        if(p == -1 && ng == n) dp[curr] = 1;
        else if(p == -1) dp[curr] = 1 + dp[ng];
        else if(ng == n) dp[curr] = 1 + dp[p];
        else dp[curr] = 1 + max(dp[p],dp[ng]);
        
        ans = max(ans,dp[curr]);

    }
    
    

    cout << ans << "\n";
    return 0;
}