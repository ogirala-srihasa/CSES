#include <bits/stdc++.h>
using namespace std;
pair<int,long long> segments(long long mid, vector<int>&arr){
    long long curr_sum = 0;
    int comp = 0;
    long long maxsum = 0;
    for(int i = 0; i < arr.size(); i++){
        if(curr_sum + arr[i] > mid){
            comp++;
            maxsum = max(maxsum,curr_sum);
            curr_sum = arr[i];
        }else{
            curr_sum += arr[i];
        }
    }
    comp++;
    maxsum = max(maxsum,curr_sum);
    return {comp,maxsum};
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    long long high = 0;
    long long low = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        high += arr[i];
        low = max(low, 1LL * arr[i]);
    }

    long long mid;
    long long ans;
    while(low <= high){
        mid = low  + (high-low)/2;
        int c = segments(mid,arr).first;
        long long csum = segments(mid,arr).second;
        if(c > k){
            low = mid+1;
        }else if(c == k){
            ans = csum;
            high = csum -1;
        }else{
            ans = csum;
            high = mid -1;
        }
    }

    cout << ans;
}