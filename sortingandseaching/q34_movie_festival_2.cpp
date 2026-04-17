#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<vector<int>> arr(n,vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> arr[i][1] >> arr[i][0];
    }

    multiset<int> minHeap;

    sort(arr.begin(),arr.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(true){
            auto it =  minHeap.lower_bound(arr[i][1]);
            if(it == minHeap.end()){
                if(minHeap.size() == 0){
                    minHeap.insert(arr[i][0]);
                    ans++;
                }else{
                    it--;
                    minHeap.erase(it);
                    minHeap.insert(arr[i][0]);
                    ans++;}
            }
            else if(*it == arr[i][1]){
                minHeap.erase(it);
                minHeap.insert(arr[i][0]);
                ans++;
            }else if(it == minHeap.begin()){
                if(minHeap.size() < k){
                    minHeap.insert(arr[i][0]);
                    ans++;
                }
            }else{
                it--;
                minHeap.erase(it);
                minHeap.insert(arr[i][0]);
                ans++;
            }
        }
    }

    cout << ans;
}